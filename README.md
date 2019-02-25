# SimpleSQL
Simple C++11 library to parse and evaluate SQL expressions

## Dependencies
- antlr4 C++ runtime:
  `brew install antlr4-cpp-runtime`
- dyno
  https://github.com/packetzero/dyno

## Build Without Tests
```
mkdir build && cd build
cmake
```

## Building for MacOS XCode

```
brew install antlr antlr4-cpp-runtime
sh ./antr_gen_cpp.sh
mkdir build && cd build
MAKE_TESTS=1 GTEST_DIR=/path/to/googletest cmake -G Xcode ..
# either open project in Xcode and build/run
xcodebuild
```

## Updating SQL grammar

```
brew install antlr
sh ./antr_gen_cpp.sh
```

## TODO
- improve unit tests
- implement bulk of functions in sqlite_functions.cpp
