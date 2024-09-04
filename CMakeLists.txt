cmake_minimum_required(VERSION 3.28)
project(Enigma)

set(CMAKE_CXX_STANDARD 23)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/imgui)
file(GLOB IMGUI_SOURCES ${IMGUI_DIR}/*.cpp)

# Compile ImGui into a library
add_library(ImGui ${IMGUI_SOURCES})
target_include_directories(ImGui PRIVATE ${IMGUI_DIR})

add_executable(${PROJECT_NAME} src/main.cpp src/Application.cpp)
add_subdirectory(src)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC "${PROJECT_SOURCE_DIR}/src" "${PROJECT_BINARY_DIR}"
    PRIVATE ${IMGUI_DIR}
)

# Link ImGui library to your executable
target_link_libraries(${PROJECT_NAME} PUBLIC EnigmaLib glfw OpenGL::GL ImGui)

file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
