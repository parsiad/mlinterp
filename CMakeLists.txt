PROJECT(MLINTERP)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

SET(CMAKE_SKIP_INSTALL_ALL_DEPENDENCY true)
INSTALL(FILES "${PROJECT_SOURCE_DIR}/mlinterp/mlinterp" "${PROJECT_SOURCE_DIR}/mlinterp/mlinterp.hpp" DESTINATION include)

SET(CMAKE_CXX_STANDARD 11)

SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}")

INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/mlinterp")

SET(CMAKE_BUILD_TYPE Release)

SET(PROJECT_BINARY_DIR "${PROJECT_SOURCE_DIR}/bin")
SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}")

OPTION(PACKAGE_TESTS "Build tests" ON)
if(PACKAGE_TESTS)
  ENABLE_TESTING()
  INCLUDE(GoogleTest)
  ADD_SUBDIRECTORY(tests)
endif()

# Add the mlinterp.cpp file to your project
ADD_LIBRARY(mlinterp SHARED "${PROJECT_SOURCE_DIR}/mlinterp/mlinterp.cpp")

# Specify the library output name and destination based on the platform
SET_TARGET_PROPERTIES(mlinterp PROPERTIES OUTPUT_NAME "mlinterp")
INSTALL(TARGETS mlinterp LIBRARY DESTINATION lib)

# Make sure to include the directory containing mlinterp.hpp
# TARGET_INCLUDE_DIRECTORIES(mlinterp PUBLIC "${PROJECT_SOURCE_DIR}/mlinterp")

