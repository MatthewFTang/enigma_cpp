cmake_minimum_required(VERSION 3.28)
project(Enigma)

set(CMAKE_CXX_STANDARD 17)

# Use FetchContent to automatically fetch GLFW
include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.3.8 # Use the appropriate version tag
)

FetchContent_MakeAvailable(glfw)

find_package(OpenGL REQUIRED)

set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/imgui)
file(GLOB IMGUI_SOURCES ${IMGUI_DIR}/*.cpp)

# Compile ImGui into a library
add_library(ImGui ${IMGUI_SOURCES})
target_include_directories(ImGui PRIVATE ${IMGUI_DIR})

add_executable(${PROJECT_NAME} src/main.cpp)
add_subdirectory(src)

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC "${PROJECT_SOURCE_DIR}/src" "${PROJECT_BINARY_DIR}"
        PRIVATE ${IMGUI_DIR}
)
target_link_libraries(ImGui PRIVATE glfw)

# Link the GLFW library downloaded by FetchContent
target_link_libraries(${PROJECT_NAME} PUBLIC EnigmaLib glfw OpenGL::GL ImGui)

file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})