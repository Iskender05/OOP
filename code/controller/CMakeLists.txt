cmake_minimum_required ( VERSION 3.5 )

add_library ( controller
        ../player/player.h
        playerController.h
        directions.h
        playerController.cpp
)

target_include_directories ( controller PUBLIC ../player )