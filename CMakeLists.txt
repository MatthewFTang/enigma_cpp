cmake_minimum_required(VERSION 3.28)
project(Enigma)

set(CMAKE_CXX_STANDARD 23)
# #Dependencies
# =================
# 1/  Option 1: if you added imgui_bundle in a subfolder, you can add it to your
# # project with: if(IS_DIRECTORY
# ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui_bundle)
# add_subdirectory(external/imgui_bundle) endif()
#
# # 2/  Option 2: simply fetch imgui_bundle during the build if(NOT TARGET
# imgui_bundle) message(STATUS "Fetching imgui_bundle...") include(FetchContent)
# set(FETCHCONTENT_QUIET FALSE) FetchContent_Declare( imgui_bundle
# GIT_REPOSITORY https://github.com/pthom/imgui_bundle.git GIT_TAG main)
# FetchContent_MakeAvailable(imgui_bundle)
#
# # Uncomment the next line if you which to also automatically fetch and compile
# # OpenCV for immvision support set(IMMVISION_FETCH_OPENCV ON) endif()
#
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
add_executable(${PROJECT_NAME} src/main.cpp src/Application.cpp)

add_subdirectory(src)
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/imgui)
file(GLOB IMGUI_SOURCES ${IMGUI_DIR}/*.cpp)
target_sources(${PROJECT_NAME} PRIVATE ${IMGUI_SOURCES})
target_include_directories(
		${PROJECT_NAME}
		PUBLIC "${PROJECT_SOURCE_DIR}/src" "${PROJECT_BINARY_DIR}"
		PRIVATE ${IMGUI_DIR})
target_link_libraries(Enigma PUBLIC EnigmaLib glfw OpenGL::GL)
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
