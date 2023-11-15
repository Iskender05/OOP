cmake_minimum_required ( VERSION 3.5 )

project ( game )
 
add_subdirectory ( ${PROJECT_SOURCE_DIR}/code )

add_executable ( ${PROJECT_NAME} code/main.cpp )
target_link_libraries ( ${PROJECT_NAME} PRIVATE controller events game_class map player reader )
