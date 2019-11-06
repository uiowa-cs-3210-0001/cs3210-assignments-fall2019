# C++ Tooling Guide

## Integrated Development Environments (IDEs)

While there is a [massive number](https://www.google.com/search?q=c%2B%2B+ides) of [IDEs](https://en.wikipedia.org/wiki/Integrated_development_environment) support C++, not all of them are created equal. This guide is giving preference to the modern IDEs and/or the IDEs that you'll be most likely to use in your professional practice. They also happen to be the easiest to install on each respective platform:

| Platform | Recommended IDEs |
| -------- | ---------------- |
| macOS    | [Xcode](#xcode), [Visual Studio Code](#visual-studio-code) |
| Windows  | [Visual Studio Community](#visual-studio-community), [Visual Studio Code](#visual-studio-code) |
| GNU/Linux | [Visual Studio Code](#visual-studio-code) |


## Compilers

Similarly to the IDEs, there are typically several C++ compilers available for every major OS platform. We'll be using the "default" compiler for each platform — the one that's distributed by the operating system's vendor as a part of their IDE/development toolset:

| Platform | Compiler | Installation |
| -------- | -------- | ------------ |
| Mac      | clang    | Installed with [Xcode](#xcode); a standalone download is [available here](https://developer.apple.com/download/more/) (you'll be asked to log in with your Apple ID; search for "command line tools" once in, make sure to sort the results by release date). |
| Windows  | Microsoft C/C++ compiler | Installed with [Visual Studio](#visual-studio-community); a standalone download is  [available here](https://visualstudio.microsoft.com/downloads/) under _Tools for Visual Studio 2019 > Build Tools for Visual Studio 2019_. |
| Linux    | gcc      | Included in all distribution; open a terminal and run `sudo apt install build-essential` if it's not installed by default. |

### C++17 support

Most recent versions of the compilers listed above support all or most of the [C++17 standard](https://en.wikipedia.org/wiki/C%2B%2B17). You do have to **explicitly enable C++17 support**, though:

| Compiler | Enabling C++17 support |
| -------- | ---------------------- |
| clang, gcc | Add `-std=c++17` to the compiler flags, e.g. `clang++ -std=c++17 main.cpp`. |
| Microsoft C/C++ compiler | See [How to enable C++17 compiling in Visual Studio](https://stackoverflow.com/a/46759740), or manually add `/std:c++17` to the compiler flags, e.g. `cl /std:c++17 main.cpp`. |


## Xcode

Xcode is Apple's IDE for developing on Mac. It supports C++ out-of-the-box and comes with Apple version of `clang` [compiler](#compilers).

### Installation
 
 - [Install](https://itunes.apple.com/us/app/xcode/id497799835) Xcode.
 - Install the command line tools by opening a terminal and running the following command: `xcode-select --instal`.

### Creating, building and running a project

#### Create a project
 - Launch Xcode, in the Welcome dialog select _Create a new Xcode project_.
 - In the project template dialog, choose _macOS_ > _Command Line Tool_, then enter the project name, organization identifier (you can use your last name), and change the _Language_ to _C++_.
 - Select the location for your project (e.g. your home directory).

#### Build

 - In the Xcode menu, select _Product > Build_ or press `⌘B`.

#### Run

 - In the Xcode menu, select _Product > Run_ or press `⌘R`.


## Visual Studio Community

Visual Studio Community is a [free edition](https://visualstudio.microsoft.com/vs/compare/) of Microsoft Visual Studio, a commercial IDE from Microsoft. It supports C++ out-of-the-box and comes with Microsoft C/C++ [compiler](#compilers).

### Installation

 - [Download and install](https://visualstudio.microsoft.com/vs/features/cplusplus/) Visual Studio Community.

### Creating, building and running a project

- See Visual Studio's [official documentation](https://docs.microsoft.com/en-us/cpp/ide/walkthrough-working-with-projects-and-solutions-cpp?view=vs-2019).
 

## Visual Studio Code

Visual Studio Code (VS Code) is a free, open source, customizable editor from Microsoft available on all major platforms. It includes [first-class support for C++](https://code.visualstudio.com/docs/languages/cpp), including debugging, syntax highlighting, code completion, linting and refactoring. It also comes with a [wealth of extensions](https://marketplace.visualstudio.com/vscode) that can be installed to further enhance the editor's functionality, effectively making it a full-fledged, extensible IDE.

### Installation
  - [Download and install](https://code.visualstudio.com) VS Code.
  - Launch VS Code, click on [the Extensions icon](https://code.visualstudio.com/docs/editor/extension-gallery#_browse-for-extensions), search for and install all of the following extensions:
  
    - [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) extension from Microsoft.   
    - [Easy C++ projects](https://marketplace.visualstudio.com/items?itemName=acharluk.easy-cpp-projects) from Alejandro Charte Luque.
    - [Catch2 and Google Test Explorer](https://marketplace.visualstudio.com/items?itemName=matepek.vscode-catch2-test-adapter) by Mate Pek.


### Creating, building and running a project
 
#### Create a project
 - Open a new folder in VS Code.
 - Open the command palette (`F1`) and search for "easy cpp", then select the _Easy Cpp/C++: Create new C++ project_ option.
 - Select your target platform/architecture (e.g. _\[Clang++/LLDB\] macOS_ ).

#### Build
 - Click "⚙️ Build" in the Status Bar at the bottom or press `⇧⌘B`.

#### Run
 - Click "▶ Build & Run" in the Status Bar at the bottom or press `F7`.


## Questions/Problems?

If you run into questions or problems while following this guide, please open a Github issue in this repo.
