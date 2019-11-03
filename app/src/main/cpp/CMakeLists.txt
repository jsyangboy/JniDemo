# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

project(Audio)

#增加编译宏
add_definitions(-D ANDROID)

#打印
message(STATUS "********************************")
message(STATUS "CMAKE_SOURCE_DIR->" ${CMAKE_SOURCE_DIR})
message(STATUS "PROJECT_SOURCE_DIR->" ${PROJECT_SOURCE_DIR})
message(STATUS "********************************")

#设置是否启用RTC
set(ENABLE_RTC 1)
# 或者使用如下方式
#option(USE_RTC "Use RTC" ON)

#设置ffmpeg的目录变量
set(LIZHI_FFMPEG_DIR ffmpeg)

#设置rt的目录变量
set(LIZHI_RTC_DIR rtc)


link_directories(${LIZHI_FFMPEG_DIR}/lib)

#如果启动了RTC，增加编译宏 ENABLE_RTC
#if(USE_RTC)
if (ENABLE_RTC EQUAL 1)
    message(STATUS "enable rtc")
    link_directories(${LIZHI_RTC_DIR}/lib) #设置RTC的lib
    add_definitions(-DENABLE_RTC)#增加ENABLE_RTC 宏，可以在c代码中做其他处理
endif ()

#发现一个目录下所有的源代码文件并将列表存储在一个变量中。
aux_source_directory(. SRC_LIST)# 搜索当前目录下的所有.cpp文件

add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${SRC_LIST})


# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

#设置ffmpeg的路径
target_link_libraries( # Specifies the target library.
        native-lib

        libavformat.a libavcodec.a libavutil.a libavfilter.a libswscale.a libswresample.a
        -llog -lm -lz

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})