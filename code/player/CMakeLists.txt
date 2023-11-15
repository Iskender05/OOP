cmake_minimum_required ( VERSION 3.5 )

add_library ( player
        player.h
        player.cpp
)

target_include_directories ( player PUBLIC ../controller )