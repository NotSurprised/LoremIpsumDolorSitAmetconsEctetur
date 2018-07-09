# Install EDB (OllyDBG in Unix)

`git clone --recursive https://github.com/eteran/edb-debugger.git`

```
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr/local/ ..
make
make install
edb
```

## boost
```
CMake Error at /usr/share/cmake-3.9/Modules/FindBoost.cmake:1898 (message):
  Unable to find the requested Boost libraries.

  Unable to find the Boost header files.  Please set BOOST_ROOT to the root
  directory containing Boost or BOOST_INCLUDEDIR to the directory containing
  Boost's headers.
Call Stack (most recent call first):
  CMakeLists.txt:23 (find_package)
```
`sudo apt-get install libboost-all-dev`

## PkgConfig
```
CMake Error at /usr/share/cmake-3.9/Modules/FindPackageHandleStandardArgs.cmake:137 (message):
  Could NOT find PkgConfig (missing: PKG_CONFIG_EXECUTABLE)
Call Stack (most recent call first):
  /usr/share/cmake-3.9/Modules/FindPackageHandleStandardArgs.cmake:377 (_FPHSA_FAILURE_MESSAGE)
  /usr/share/cmake-3.9/Modules/FindPkgConfig.cmake:36 (find_package_handle_standard_args)
  cmake/Modules/FindCapstone.cmake:2 (find_package)
  CMakeLists.txt:26 (find_package)
```
`sudo apt-get install pkg-config`

## capstone
```
-- Checking for module 'capstone>=3.0.4'
--   No package 'capstone' found
CMake Error at /usr/share/cmake-3.9/Modules/FindPkgConfig.cmake:412 (message):
  A required package was not found
Call Stack (most recent call first):
  /usr/share/cmake-3.9/Modules/FindPkgConfig.cmake:588 (_pkg_check_modules_internal)
  cmake/Modules/FindCapstone.cmake:4 (pkg_check_modules)
  CMakeLists.txt:26 (find_package)
```
`sudo apt-get install libcapstone-dev`

## Qt5
```
CMake Warning at CMakeLists.txt:49 (find_package):
  By not providing "FindQt5Core.cmake" in CMAKE_MODULE_PATH this project has
  asked CMake to find a package configuration file provided by "Qt5Core", but
  CMake did not find one.

  Could not find a package configuration file provided by "Qt5Core" with any
  of the following names:

    Qt5CoreConfig.cmake
    qt5core-config.cmake

  Add the installation prefix of "Qt5Core" to CMAKE_PREFIX_PATH or set
  "Qt5Core_DIR" to a directory containing one of the above files.  If
  "Qt5Core" provides a separate development package or SDK, be sure it has
  been installed.


CMake Error at src/CMakeLists.txt:26 (find_package):
  By not providing "FindQt5.cmake" in CMAKE_MODULE_PATH this project has
  asked CMake to find a package configuration file provided by "Qt5", but
  CMake did not find one.

  Could not find a package configuration file provided by "Qt5" (requested
  version 5.0.0) with any of the following names:

    Qt5Config.cmake
    qt5-config.cmake

  Add the installation prefix of "Qt5" to CMAKE_PREFIX_PATH or set "Qt5_DIR"
  to a directory containing one of the above files.  If "Qt5" provides a
  separate development package or SDK, be sure it has been installed.

```
`sudo apt-get install qt5-default`

## Qt5XmlPatterns
```
CMake Error at /usr/lib/x86_64-linux-gnu/cmake/Qt5/Qt5Config.cmake:26 (find_package): Could not
find a package configuration file provided by "Qt5XmlPatterns" with any of the following names:
 Qt5XmlPatternsConfig.cmake 
 qt5xmlpatterns-config.cmake
```
`sudo apt-get install libqt5xmlpatterns5-dev`

## Qt5Svg
```
Could not find a package configuration file provided by "Qt5Svg" with any
  of the following names:

    Qt5SvgConfig.cmake
    qt5svg-config.cmake

  Add the installation prefix of "Qt5Svg" to CMAKE_PREFIX_PATH or set
  "Qt5Svg_DIR" to a directory containing one of the above files.  If "Qt5Svg"
  provides a separate development package or SDK, be sure it has been
  installed.
```
`sudo apt-get install libqt5svg5-dev` 
