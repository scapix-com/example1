# Example for [Scapix Language Bridge](https://www.scapix.com/)

On the fly code generation to bridge C++ to `Java`, `Objective-C`, `Swift`, `Python` and `JavaScript` (Emscripten).

1. Change your C++ code and build your project (bindings generated as part of the build).
2. Call newly changed C++ code from Java, Objective-C, Swift, Python or JavaScript.

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

#### Python

**Mac:**

```bash
$ brew install python3
$ cd example1
$ ./project/xcode_mac_python.sh
$ ./ui/python/run.py
```

Xcode project: `project/build/xcode_mac_python/chatlib.xcodeproj`

**Windows:**

Install [python3](https://www.python.org/downloads/windows/)

```cmd
> cd example1
> project\vs_python.cmd
> ui\python\run.py
```

Visual Studio solution: `project\build\vs_python\chatlib.sln`

**Linux:**

```bash
$ sudo apt install python3-dev
$ cd example1
$ ./project/default_python.sh
$ ./ui/python/run.py
```

#### Java

**Mac:**

```bash
$ brew cask install java
$ cd example1
$ ./project/xcode_mac_java.sh
$ ./ui/java/compile.sh
$ ./ui/java/run.sh
```

Xcode project: `project/build/xcode_mac_java/chatlib.xcodeproj`

**Windows:**

Install [JDK](https://www.oracle.com/technetwork/java/javase/downloads/index.html)

```cmd
> cd example1
> project\vs_java.cmd
> ui\java\compile.cmd
> ui\java\run.cmd
```

Visual Studio solution: `project\build\vs_java\chatlib.sln`

**Linux:**

```bash
$ sudo apt install default-jdk
$ cd example1
$ ./project/default_java.sh
$ ./ui/java/compile.sh
$ ./ui/java/run.sh
```

#### JavaScript (Emscripten)

Install [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html)

```bash
$ cd example1
$ ./project/emscripten.sh
$ ./ui/js/serve.sh
```
