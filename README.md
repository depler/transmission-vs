# Transmission daemon for Windows
This project is about building Transmission torrent daemon as a single binary without dependencies with Visual Studio.

Current source code components:
* Transmission (https://github.com/transmission/transmission): 3.00
* OpenSSL (https://github.com/openssl/openssl): 3.0.0
* Curl (https://github.com/curl/curl): 7.80.0
* Event2 (https://github.com/libevent/libevent): 2.1.12
* Zlib (https://github.com/madler/zlib): 1.2.11
* MiniUPnP (https://github.com/miniupnp/miniupnp): 2.2.3
* DHT (https://github.com/jech/dht): 0.26
* ARC4 (https://github.com/transmission/arc4): 1.0.0
* libutp (https://github.com/transmission/libutp): post-3.3-transmission
* libb64 (https://github.com/libb64/libb64): 2.0.0.1
* libnatpmp (https://github.com/transmission/libnatpmp): master

Releases contains additional binaries (besides transmission itself):
* Transmissionic Web UI (https://github.com/6c65726f79/Transmissionic): 1.4.2
* Transmission Remote GUI (https://github.com/transmission-remote-gui/transgui): 5.18.0

Binary dependencies: none. Compatible with Windows Vista and newer.

# Build
Clone current repository and build **transmission.sln** file with Visual Studio 2022 or newer. No, additional black magic is not required. Yes, just that simple.

# Config
Pay attention to file `[Transmission]\daemon\settings.json`. Probably you want/should change following settings: `download-dir`, `incomplete-dir`. Some default values:
- torrents folder path is `C:\Torrents` (please dont use ending backslash)
- web UI url is http://localhost:9091/transmission/web/

# Run
Download latest **Transmission.zip** from releases, unpack it somewhere and run one of the following with administrator rights:
* run_foreground.bat: run transmission in console mode (without service installation)
* daemon_create.bat: create windows service for transmission
* daemon_start.bat: start windows service for transmission
* daemon_stop.bat: stop windows service for transmission
* daemon_delete.bat: delete windows service for transmission
* desktop_shortcut.bat: create desktop shortcut for transgui.exe

# Known issues
`FIXED` Transmission for windows has bug with folders path ending with backslash. If you put download into folder like **C:\\Torrents** it will run ok, but path **C:\\Torrents\\** (with ending backslash) will fail. Not really a big deal, just make sure once that there is no backslash when starting torrent download.
