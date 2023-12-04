cmake_minimum_required(VERSION 3.5)

add_library(reader
    ../logger/base_mesg.h
    ../logger/enable_key_log.h
    ../logger/enable_key_log.cpp
    ../logger/not_enable_key_log.h
    ../logger/not_enable_key_log.cpp
    ../logger/win_log.h
    ../logger/win_log.cpp
    ../logger/lose_log.h
    ../logger/lose_log.cpp        
    ../logger/logger.h
    ../logger/logger.cpp
    ../logger/new_game_log.h
    ../logger/new_game_log.cpp
    ../logger/output.h
    ../logger/file_out.h
    ../logger/file_out.cpp
    ../logger/terminal_out.h
    ../logger/terminal_out.cpp

    input.h
    input_reader.h
    input_reader.cpp
)

target_include_directories ( reader PUBLIC ../logger )