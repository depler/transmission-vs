#include "arc4.h"

#include <assert.h>

#define ARC4_MAGIC 0x34637261 // 'arc4' (LE)

static inline void arc4_swap(struct arc4_context* ctx, size_t i, size_t j)
{
    assert(ctx != NULL);
    assert(i < 256);
    assert(j < 256);

    uint8_t const t = ctx->s[i];
    ctx->s[i] = ctx->s[j];
    ctx->s[j] = t;
}

static inline uint8_t arc4_next(struct arc4_context* ctx)
{
    assert(ctx != NULL);

    ctx->i += 1;
    ctx->j += ctx->s[ctx->i];

    arc4_swap(ctx, ctx->i, ctx->j);

    return ctx->s[(uint8_t)(ctx->s[ctx->i] + ctx->s[ctx->j])];
}

void arc4_init(struct arc4_context* ctx, void const* key, size_t key_length)
{
    assert(ctx != NULL);
    assert(key != NULL);
    assert(key_length < 256);

#ifndef NDEBUG
    ctx->magic = ARC4_MAGIC;
#endif

    ctx->i = 0;
    ctx->j = 0;

    for (size_t i = 0; i < 256; ++i)
    {
        ctx->s[i] = (uint8_t)i;
    }

    for (size_t i = 0, j = 0; i < 256; ++i)
    {
        j = (uint8_t)(j + ctx->s[i] + ((uint8_t const*)key)[i % key_length]);
        arc4_swap(ctx, i, j);
    }
}

void arc4_process(struct arc4_context* ctx, void const* src_data, void* dst_data, size_t data_length)
{
    assert(ctx != NULL);
    assert(ctx->magic == ARC4_MAGIC);

    if (data_length == 0)
    {
        return;
    }

    assert(src_data != NULL);
    assert(dst_data != NULL);
    assert(data_length < SIZE_MAX);

    for (size_t i = 0; i < data_length; ++i)
    {
        ((uint8_t*)dst_data)[i] = ((uint8_t const*)src_data)[i] ^ arc4_next(ctx);
    }
}

void arc4_discard(struct arc4_context* ctx, size_t length)
{
    assert(ctx != NULL);
    assert(ctx->magic == ARC4_MAGIC);
    assert(length < SIZE_MAX);

    for (size_t i = 0; i < length; ++i)
    {
        arc4_next(ctx);
    }
}
