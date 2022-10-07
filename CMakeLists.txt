project(schedule)

set(SOURCE src/main.cpp)

# include(src/CMakeLists.txt)

include_directories(src)

add_executable(${PROJECT_NAME} ${SOURCE})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)