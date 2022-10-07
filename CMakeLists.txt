project(schedule)

include_directories(src)

set(SOURCE
src/main.cpp
src/read.cpp
src/read.h
src/uc.cpp
src/uc.h
)

add_executable(${PROJECT_NAME} ${SOURCE})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)