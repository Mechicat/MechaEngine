cmake_minimum_required(VERSION 3.10)

# set the project name
project(MechaEngine)

# add the executable
add_executable(MechaEngine main.cpp "engine_setup.h" "libraries/speedykv/KeyValue.h" "libraries/speedykv/KeyValue.cpp" "engine_setup.cpp" "fileops.cpp" "fileops.h")

include_directories("${PROJECT_SOURCE_DIR}/libraries/")

link_directories(
	"${PROJECT_SOURCE_DIR}/libraries/SDL2/lib/x64"
)

target_link_libraries(
MechaEngine 
"${PROJECT_SOURCE_DIR}/libraries/SDL2/lib/x64/SDL2.lib"
"${PROJECT_SOURCE_DIR}/libraries/SDL2/lib/x64/SDL2main.lib"
)

message("Source Dir:${PROJECT_SOURCE_DIR}")