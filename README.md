# Cinema app - C++ [![Build Status](https://github.com/mateiungureanu/POO-2023-proiect/actions/workflows/cmake.yml/badge.svg)](https://github.com/mateiungureanu/POO-2023-proiect/actions)
## Programare Orientata pe Obiecte (2023-2024)

### Table of contents
+ [Description](#description)
+ [Requirements](#requirements)
+ [Setup](#setup)
+ [How to use](#how-to-use)
  + [Customer Interface](#customer-interface)
  + [Admin Interface](#admin-interface)

### Description

+ Local application with an interactive terminal menu that updates based on user input and allows for returning back in case of an error. It utilizes OOP principles like polymorphism, multiple inheritance, abstract classes and templates, along with design patterns and exception handling. Integrated with GitHub Actions for CI/CD.
+ It offers customers the option to buy one or more tickets for a screening by selecting the cinema, the movie, the day, the hour, and the seat, and allows administrators to add or remove a movie, update a movie's rating, and view the entire selection of movies.

> **NOTE**
> The app does **not** have a database. All data is lost upon program exit.

### Requirements

+ Check if you have a C++ compiler installed \(`g++ --version`\). If not, install it from this [page](https://www.msys2.org/).
+ Open terminal MSYS2 UCRT64 or MSYS2 MINGW64 and run this command: `pacman -S mingw-w64-ucrt-x86_64-gcc`
+ Add PATH Variable _C:\msys64\mingw64\bin_
+ Check if you have CMake installed \(`cmake --version`\). If the command does not work but you know CMake is installed, run: `Get-Command cmake -ErrorAction SilentlyContinue` to find the location, then add it to system PATH. Otherwise, install it from this [page](https://cmake.org/download/). Make sure you check "Add CMake to system PATH".


<!-- + Check if you have gtest installed \(`vcpkg --version`\). If not, install it by running these commands:
  + `git clone https://github.com/microsoft/vcpkg.git`
  + `cd vcpkg`
  + `.\bootstrap-vcpkg.bat`  

  Then add PATH Variable _C:\Users\\[your-user-name\]\vcpkg_ \(or whatever location you installed it to\).
+ Install gtest: `vcpkg install gtest` -->

### Setup

+ `git clone https://github.com/mateiungureanu/POO-2023-proiect`
+ `cd POO-2023-proiect`
+ `cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -G Ninja`
+ `cmake --build build --config Debug --parallel 6`
+ To run the app: `.\build\oop.exe`
+ To run the tests: `.\build\test_oop.exe`

### How to use

#### Customer interface

+ Follow the instructions on screen.

#### Admin Interface

+ Admin credentials: _mateistefan_, _qwertyuiop_
+ Follow the instructions on screen.
