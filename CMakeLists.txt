cmake_minimum_required(VERSION 3.10)
project(Archer)

set(CMAKE_CXX_STANDARD 11)



add_executable(Archer
        bin/Debug/lucznik.exe
        include/Arrow.h
        include/game.h
        include/Player.h
        include/Bow.h
        include/Collision.h
        src/Arrow.cpp
        src/Bow.cpp
        src/game.cpp
        src/Player.cpp
        src/Collision.cpp
        arial.ttf
        arrowDef.png
        bowNormal.png
        jungle.png
        lucznik.cbp
        lucznik.cscope_file_list
        lucznik.depend
        lucznik.layout
        main.cpp
        openal32.dll
        pirate.png
        include/Target.h src/Target.cpp)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Archer ${SFML_LIBRARIES})
endif()
