# Transmission daemon for Windows
This project is about building Transmission torrent daemon for Windows as a single binary without dependencies. For Android version of this project see: https://github.com/depler/transmission-android.

Current source code components:
* Transmission (https://github.com/transmission/transmission): 4.0.3
* WolfSSL (https://github.com/wolfSSL/wolfssl): 5.6.0
* Curl (https://github.com/curl/curl): 8.0.1
* Event2 (https://github.com/libevent/libevent): 2.1.12
* Zlib (https://github.com/madler/zlib): 1.2.13

Releases contains additional binaries (besides transmission itself):
* Transmissionic Web UI (https://github.com/6c65726f79/Transmissionic): 1.8.0
* Transmission Remote GUI (https://github.com/transmission-remote-gui/transgui): 5.18.0

Binary dependencies: none. Compatible with Windows Vista and newer.

# Build
Clone current repository and build **transmission.sln** file with Visual Studio 2022 or newer. No, additional black magic is not required. Yes, just that simple.

Branch `master` contains latest changes from original transmission code (version 4), for old version see branch `v3`.

# Config
Pay attention to file `[Transmission]\daemon\settings.json`. Probably you want/should change following settings: `download-dir`, `incomplete-dir`. Some default values:
- torrents folder path is `C:\Torrents\`
- web UI url is http://localhost:9091/transmission/web/

# Run
Download latest **Transmission.zip** from releases, unpack it somewhere and run one of the following with administrator rights:
* **run_foreground.bat**: run transmission in console mode (without service installation)
* **daemon_create.bat**: create windows service for transmission
* **daemon_start.bat**: start windows service for transmission
* **daemon_stop.bat**: stop windows service for transmission
* **daemon_delete.bat**: delete windows service for transmission
* **desktop_shortcut.bat**: create desktop shortcut for transgui.exe
