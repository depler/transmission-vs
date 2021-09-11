# Transmission daemon for Windows
This project is about building Transmission torrent daemon as a single binary without dependencies with Visual Studio.

Current source code components:
* Transmission (https://github.com/transmission/transmission): 3.00 (bb6b5a062e)
* OpenSSL (https://github.com/openssl/openssl): 1.1.1l
* Curl (https://github.com/curl/curl): 7.78.0
* Event2 (https://github.com/libevent/libevent): 2.1.12
* Zlib (https://github.com/madler/zlib): 1.2.11

Releases contains additional binaries (besides transmission itself):
* Transmissionic Web UI (https://github.com/6c65726f79/Transmissionic): 1.4.0
* Transmission Remote GUI (https://github.com/transmission-remote-gui/transgui): 5.18.0

Binary dependencies: none. Compatible with Windows Vista and newer.

# Build
Clone current repository and build **transmission.sln** file with Visual Studio 2019 or newer. No, additional black magic is not required. Yes, just that simple.

# Config
Pay attention to file `[Transmission]\daemon\settings.json`. Probably you want/should to change settings `download-dir`, `incomplete-dir` (please dont use ending backslash).

# Run
Download latest **Transmission.zip** from releases, unpack it somewhere and run one of the following with administrator rights:
* daemon_create.bat: create windows service for transmission
* daemon_delete.bat: delete windows service for transmission
* daemon_start.bat: start windows service for transmission
* daemon_stop.bat: stop windows service for transmission
* run_foreground.bat: run transmission in console mode
* desktop_shortcut.bat: create desktop shortcut for transgui.exe
* web_install.bat: install web UI for transmission (browse http://localhost:9091/transmission/web/)

# Known issues
Transmission for windows have a bug with folders path ending with backslash. If you put download into folder like **C:\\Torrents** it will run ok, but path **C:\\Torrents\\** (with ending backslash) will fail. Not really a big deal, just make sure once that there is no backslash when starting torrent download.
