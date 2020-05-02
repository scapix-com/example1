# Example for [Scapix Language Bridge](https://www.scapix.com/)

On the fly code generation to bridge C++ to `Java`, `Objective-C`, `Swift`, `Python`, `JavaScript` (WebAssembly) and `C#`.

1. Change your C++ code and build your project (bindings generated as part of the build).
2. Call newly changed C++ code from Java, Objective-C, Swift, Python, JavaScript or C#.

### Install

```bash
$ git clone https://github.com/scapix-com/example1
```

### Getting started

- Run one of the scripts in **project** folder to create library project (chatlib).
- Open corresponding platform specific application project in **ui** folder (chat).

#### iOS

- Run: **xcode_ios_objc.sh**
- Open in Xcode: **ui/ios/chat.xcworkspace**

#### MacOS

- Run: **xcode_mac_objc.sh**
- Open in Xcode: **ui/macos/chat.xcworkspace**

#### Android

- Open in Android Studio: **ui/android**

Requires CMake 3.14+, add to **ui/android/local.properties**:

Mac: `cmake.dir=/usr/local`\
Windows: `cmake.dir=c\:\\Program Files\\CMake`

Windows: place [ninja.exe](https://github.com/ninja-build/ninja/releases) in PATH.

#### Python

**Mac:**

```bash
$ brew install python3
$ cd example1
$ ./xcode_mac_python.sh
$ cd ../ui/python
$ ./run.py
```

Xcode project: `build/xcode_mac_python/chatlib.xcodeproj`

**Windows:**

Install [python3](https://www.python.org/downloads/windows/)

```cmd
> cd example1
> vs_python.cmd
> cd ..\ui\python
> run.py
```

Visual Studio solution: `build\vs_python\chatlib.sln`

**Linux:**

```bash
$ sudo apt install python3-dev
$ cd example1
$ ./default_python.sh
$ cd ../ui/python
$ ./run.py
```

#### Java

**Mac:**

```bash
$ brew cask install java
$ cd example1
$ ./xcode_mac_java.sh
$ cd ../ui/java
$ ./compile.sh
$ ./run.sh
```

Xcode project: `build/xcode_mac_java/chatlib.xcodeproj`

**Windows:**

Install [JDK](https://www.oracle.com/technetwork/java/javase/downloads/index.html)

```cmd
> cd example1
> vs_java.cmd
> cd ..\ui\java
> compile.cmd
> run.cmd
```

Visual Studio solution: `build\vs_java\chatlib.sln`

**Linux:**

```bash
$ sudo apt install default-jdk
$ cd example1
$ ./xcode_mac_java.sh
$ cd ../ui/java
$ ./compile.sh
$ ./run.sh
```

#### JavaScript (Emscripten)

Install [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html)

```bash
$ cd example1
$ ./emscripten.sh
$ cd ../ui/js
$ ./serve.sh
```
