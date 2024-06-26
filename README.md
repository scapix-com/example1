# Example for [Scapix Language Bridge](https://www.scapix.com/)

On the fly code generation to bridge C++ to `Java`, `Objective-C`, `Swift`, `Python`, `JavaScript` (WebAssembly) and `C#`.

1. Change your C++ code and build your project (bindings generated as part of the build).
2. Call newly changed C++ code from Java, Objective-C, Swift, Python, JavaScript or C#.

### Install

```bash
$ git clone https://github.com/scapix-com/example1
```

### Build

`build.sh` script (or `build.cmd` on Windows) runs CMake configure and build steps using selected CMake preset.

- Run `build` script without parameters to see list of available CMake presets.
- Run `build` script specifying one the the presets to create and build library project (chatlib).
- Open corresponding platform specific application project in **ui** folder (chat).

#### macOS

- Run: `./build.sh xcode-objc`
- Open in Xcode: **ui/macos/chat.xcworkspace**

#### iOS

- Run: `./build.sh xcode-objc-ios`
- Open in Xcode: **ui/ios/chat.xcworkspace**

#### tvOS

- Run: `./build.sh xcode-objc-tvos`

#### watchOS

- Run: `./build.sh xcode-objc-watchos`

#### visionOS

- Run: `./build.sh xcode-objc-visionos`

#### Android (on Windows, macOS or Linux)

- Open in Android Studio: **ui/android**
- Requires: [Ninja](https://github.com/ninja-build/ninja/releases), see [Install CMake and Ninja](https://developer.android.com/studio/projects/install-ndk#vanilla_cmake)

#### Python (on Windows, macOS or Linux)

```bash
$ ./build.sh python
$ cd ui/python
$ ./run.py
```

You can also specify CMake generator explicitly and then open generated project in corresponding IDE:

```bash
$ build vs2019-python
$ build vs2022-python
$ ./build.sh xcode-python
```

#### Java (on Windows, macOS or Linux)

```bash
$ ./build.sh java
```

You can also specify CMake generator explicitly and then open generated project in corresponding IDE:

```bash
$ build vs2019-java
$ build vs2022-java
$ ./build.sh xcode-java
```

#### JavaScript (Emscripten)

Install [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html)

```bash
$ ./build.sh js
$ cd ui/js
$ ./serve.sh
```

On Windows use ninja-js preset, as [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html) doesn't support Visual Studio CMake generators:

```bash
$ build ninja-js
$ cd ui/js
$ serve.sh
```

#### C#

```bash
$ build vs2022-cs
```

Open Visual Studio solution: `build\vs2022-cs\ui\cs\chat.sln`
