# Example for [Scapix Language Bridge](https://www.scapix.com/)

On the fly code generation to bridge C++ to Java, Objective-C, Swift and Python.

1. Change your C++ files and press "Build" in the IDE.
2. Call newly added C++ code from Java, Objective-C, Swift or Python.

### Install

```bash
$ mkdir scapix
$ cd scapix
$ git clone https://github.com/scapix-com/example1
$ git clone https://github.com/scapix-com/scapix
```

### Getting started

- Run one of the scripts in **project** folder to create library project (chatlib).
- Open corresponding platform specific application project in **ui** folder (chat).

#### iOS

- Run: **example1/project/xcode_ios_objc.sh**
- Open in Xcode: **example1/ui/ios/chat.xcworkspace**

#### MacOS

- Run: **example1/project/xcode_mac_objc.sh**
- Open in Xcode: **example1/ui/macos/chat.xcworkspace**

#### Android

- Open in Android Studio: **example1/ui/android**

Requires CMake 3.14+, add to **example1/ui/android/local.properties**:

Mac: `cmake.dir=/usr/local`\
Windows: `cmake.dir=c\:\\Program Files\\CMake`

On Windows [ninja.exe](https://github.com/ninja-build/ninja/releases) needs to be in PATH.\
On Mac if `/usr/include` folder is missing, run `xcode-select --install` (Mojave: install package `/Library/Developer/CommandLineTools/Packages/macOS_SDK_headers_for_macOS_10.14.pkg`)

#### Python (Mac)

- brew install python3
- Run: **example1/project/xcode_mac_python.sh**
- To edit and rebuild C++ code, open in Xcode: **example1/project/build/xcode_mac_python/chatlib.xcodeproj**
- To test, run: **example1/ui/python/run.py**

#### Python (Windows)

- Install [python3](https://www.python.org/downloads/windows/)
- Run: **example1\project\vs_python.cmd**
- To edit and rebuild C++ code, open in Visual Studio: **example1\project\build\vs_python\chatlib.sln**
- To test, run: **example1\ui\python\run.py**

#### Python (Linux)

- sudo apt install python3-dev
- To build, run: **example1/project/default_python.sh**
- To test, run: **example1/ui/python/run.py**
