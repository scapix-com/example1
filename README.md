# Example for [Scapix Language Bridge](https://www.scapix.com/)

On the fly code generation to bridge C++ to Java, Objective-C, Swift and Python.

1. Change your C++ files and press "Build" in the IDE.
2. Call newly added C++ code from Java, Objective-C, Swift or Python.

### Install

```bash
mkdir scapix
cd scapix
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

{{% notice note %}}
Requires CMake 3.12+, add to **example1/ui/android/local.properties**: Mac: cmake.dir=/usr/local, Windows: cmake.dir=c\:\\Program Files\\CMake
{{% /notice %}}

#### Python (Mac)

- Run: **example1/project/xcode_mac_python.sh**
- Open and build in Xcode: **example1/project/build/xcode_mac_python/chatlib.xcodeproj**

```bash
cd example1/project/build/xcode_mac_python/Debug
python3
import chatlib
c = chatlib.Contact()
c.name('hello')
c.name()
```

#### Python (Windows)

- Run: **example1\project\vs_python.cmd**
- Open and build in Visual Studio: **example1\project\build\vs_python\chatlib.sln**

```bash
cd example1\project\build\vs_python\Debug
python
import chatlib
c = chatlib.Contact()
c.name('hello')
c.name()
```
