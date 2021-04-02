# Transmission daemon for Windows
This project is about building Transmission torrent daemon as a single binary without dependencies with Visual Studio.

Current components:
* Transmission (https://github.com/transmission/transmission): 3.00 (bb6b5a062e)
* OpenSSL (https://github.com/openssl/openssl): 1.1.1j
* Curl (https://github.com/curl/curl): 7.76.0
* Event2 (https://github.com/libevent/libevent): 2.1.12
* Zlib (https://github.com/madler/zlib): 1.2.11

Binary dependencies: none. Compatible with Windows Vista and newer.

# Build
Clone current repository and build **transmission.sln** file with Visual Studio 2019 or newer. No, additional black magic is not required. Yes, just that simple.
