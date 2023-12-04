cmake_minimum_required ( VERSION 3.5 )

add_library ( logger_class
        ../controller/playerController.cpp
        ../reader/input_reader.cpp
        ../reader/input_reader.h

        base_mesg.h
        enable_key_log.h
        enable_key_log.cpp
        not_enable_key_log.h
        not_enable_key_log.cpp
        win_log.h
        win_log.cpp
        lose_log.h
        lose_log.cpp        
        logger.h
        logger.cpp
)

target_include_directories ( logger_class PUBLIC ../controller ../reader ../game )