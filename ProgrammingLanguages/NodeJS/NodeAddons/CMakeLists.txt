cmake_minimum_required(VERSION 3.10)
project(NodeJSAddons)

set(CMAKE_CXX_STANDARD 11)

include_directories(src,
        node_modules/nan
        /home/q/.nvm/versions/node/v8.11.1/include/node)

add_executable(NodeJSAddons
        lib/index.ts
        lib/queue.ts
        src/async.cc
        src/withnan.cc
        src/main.cc
        binding.gyp
        package.json
        tsconfig.json
        yarn.lock)
