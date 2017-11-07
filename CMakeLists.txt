CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(SLOW_MOTION)

set(raspicam_DIR "/usr/local/lib/cmake")

FIND_PACKAGE(raspicam REQUIRED)

ADD_EXECUTABLE(SlowMotion
  Main.cpp
  Camera.cpp)

TARGET_LINK_LIBRARIES(SlowMotion ${raspicam_LIBS})
