# Helper functions and classes 

C++ Helper functions and classes for my analysis code in Marlin and ROOT.

## Installation

1. Make sure your software is up-to-date (ROOT, gcc, cmake, ...) *or* load using macro (only on NAF):
 ```sh
 cd macros && source load_env.sh && cd ..
 ```
2. Create subdirectory for external packages:
 ```sh
 mkdir external
 ```
3. Clone and build spdlog from github:
 ```sh
 git clone -b 'v1.7.0' --depth 1 https://github.com/gabime/spdlog.git external/spdlog
 cd external/spdlog && mkdir build && cd build
 cmake .. && make -j
 cd ../../..
 ```
4. Clone the googletest repository from github:
 ```sh
 git clone -b 'release-1.10.0' --depth 1 https://github.com/google/googletest.git external/googletest
 ```
7. Compile the code:
 ```sh
 cd macros && chmod u+x compile.sh && ./compile.sh && cd ..
 ```
 The compilation can also be done in multithreaded mode using `./compile.sh --jobs=N_jobs`.
 
## Usage

The compiled library code will sit in the `lib` directory and can be linked in other projects.