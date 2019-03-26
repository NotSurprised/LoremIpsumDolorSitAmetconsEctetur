# Install GoogleTest for Ubuntu Project Cmake

###### tags: `else`

https://github.com/google/googletest/blob/master/googletest/docs/Pkgconfig.md
https://stackoverflow.com/questions/8507723/how-to-start-working-with-gtest-and-cmake
However, pkgconfig always can not find `gtest_main.pc` when you install with `libgtest-dev`.

Setup.sh
```shell
sudo apt-get install -y cmake libsqlite3-dev sqlite3 libcurl4-openssl-dev

cd libs/googletest-release-1.8.1
mkdir build
cd build
cmake -DBUILD_GTEST=ON -DBUILD_GMOCK=ON -DINSTALL_GTEST=ON -DINSTALL_GMOCK=ON ../
sudo make install
```

```shell
$ cd libs/googletest-release-1.8.1
$ mkdir build
$ cd build
$ cmake -DBUILD_GTEST=ON -DBUILD_GMOCK=ON -DINSTALL_GTEST=ON -DINSTALL_GMOCK=ON ../
$ make install

-- Configuring done
-- Generating done
-- Build files have been written to: /home/ubuntu/oma-dm-client/libs/googletest-release-1.8.1/mybuild
Scanning dependencies of target gtest
[ 12%] Building CXX object googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 25%] Linking CXX static library libgtest.a
[ 25%] Built target gtest
Scanning dependencies of target gmock
[ 37%] Building CXX object googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 50%] Linking CXX static library libgmock.a
[ 50%] Built target gmock
Scanning dependencies of target gmock_main
[ 62%] Building CXX object googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[ 75%] Linking CXX static library libgmock_main.a
[ 75%] Built target gmock_main
Scanning dependencies of target gtest_main
[ 87%] Building CXX object googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[100%] Linking CXX static library libgtest_main.a
[100%] Built target gtest_main
Install the project...
-- Install configuration: ""
-- Up-to-date: /usr/local/include
-- Up-to-date: /usr/local/include/gmock
-- Up-to-date: /usr/local/include/gmock/gmock-generated-nice-strict.h
-- Up-to-date: /usr/local/include/gmock/gmock-cardinalities.h
-- Up-to-date: /usr/local/include/gmock/internal
-- Up-to-date: /usr/local/include/gmock/internal/gmock-port.h
-- Up-to-date: /usr/local/include/gmock/internal/gmock-generated-internal-utils.h
-- Up-to-date: /usr/local/include/gmock/internal/gmock-generated-internal-utils.h.pump
-- Up-to-date: /usr/local/include/gmock/internal/custom
-- Up-to-date: /usr/local/include/gmock/internal/custom/gmock-port.h
-- Up-to-date: /usr/local/include/gmock/internal/custom/gmock-matchers.h
-- Up-to-date: /usr/local/include/gmock/internal/custom/README.md
-- Up-to-date: /usr/local/include/gmock/internal/custom/gmock-generated-actions.h.pump
-- Up-to-date: /usr/local/include/gmock/internal/custom/gmock-generated-actions.h
-- Up-to-date: /usr/local/include/gmock/internal/gmock-internal-utils.h
-- Up-to-date: /usr/local/include/gmock/gmock-actions.h
-- Up-to-date: /usr/local/include/gmock/gmock-matchers.h
-- Up-to-date: /usr/local/include/gmock/gmock-generated-function-mockers.h
-- Up-to-date: /usr/local/include/gmock/gmock-more-actions.h
-- Up-to-date: /usr/local/include/gmock/gmock-generated-function-mockers.h.pump
-- Up-to-date: /usr/local/include/gmock/gmock.h
-- Up-to-date: /usr/local/include/gmock/gmock-spec-builders.h
-- Up-to-date: /usr/local/include/gmock/gmock-generated-actions.h.pump
-- Up-to-date: /usr/local/include/gmock/gmock-more-matchers.h
-- Up-to-date: /usr/local/include/gmock/gmock-generated-matchers.h
-- Up-to-date: /usr/local/include/gmock/gmock-generated-nice-strict.h.pump
-- Up-to-date: /usr/local/include/gmock/gmock-generated-matchers.h.pump
-- Up-to-date: /usr/local/include/gmock/gmock-generated-actions.h
-- Installing: /usr/local/lib/libgmock.a
-- Installing: /usr/local/lib/libgmock_main.a
-- Up-to-date: /usr/local/lib/pkgconfig/gmock.pc
-- Up-to-date: /usr/local/lib/pkgconfig/gmock_main.pc
-- Up-to-date: /usr/local/lib/cmake/GTest/GTestTargets.cmake
-- Installing: /usr/local/lib/cmake/GTest/GTestTargets-noconfig.cmake
-- Up-to-date: /usr/local/lib/cmake/GTest/GTestConfigVersion.cmake
-- Up-to-date: /usr/local/lib/cmake/GTest/GTestConfig.cmake
-- Up-to-date: /usr/local/include
-- Up-to-date: /usr/local/include/gtest
-- Up-to-date: /usr/local/include/gtest/gtest-message.h
-- Installing: /usr/local/include/gtest/gtest.h
-- Up-to-date: /usr/local/include/gtest/gtest-typed-test.h
-- Up-to-date: /usr/local/include/gtest/internal
-- Up-to-date: /usr/local/include/gtest/internal/gtest-type-util.h.pump
-- Up-to-date: /usr/local/include/gtest/internal/gtest-internal.h
-- Up-to-date: /usr/local/include/gtest/internal/gtest-tuple.h.pump
-- Up-to-date: /usr/local/include/gtest/internal/gtest-param-util-generated.h.pump
-- Up-to-date: /usr/local/include/gtest/internal/gtest-death-test-internal.h
-- Up-to-date: /usr/local/include/gtest/internal/gtest-filepath.h
-- Up-to-date: /usr/local/include/gtest/internal/gtest-param-util.h
-- Up-to-date: /usr/local/include/gtest/internal/gtest-port.h
-- Up-to-date: /usr/local/include/gtest/internal/gtest-param-util-generated.h
-- Up-to-date: /usr/local/include/gtest/internal/gtest-port-arch.h
-- Up-to-date: /usr/local/include/gtest/internal/gtest-linked_ptr.h
-- Up-to-date: /usr/local/include/gtest/internal/gtest-string.h
-- Up-to-date: /usr/local/include/gtest/internal/custom
-- Up-to-date: /usr/local/include/gtest/internal/custom/gtest.h
-- Up-to-date: /usr/local/include/gtest/internal/custom/gtest-printers.h
-- Up-to-date: /usr/local/include/gtest/internal/custom/README.md
-- Up-to-date: /usr/local/include/gtest/internal/custom/gtest-port.h
-- Up-to-date: /usr/local/include/gtest/internal/gtest-tuple.h
-- Up-to-date: /usr/local/include/gtest/internal/gtest-type-util.h
-- Up-to-date: /usr/local/include/gtest/gtest-printers.h
-- Up-to-date: /usr/local/include/gtest/gtest_pred_impl.h
-- Up-to-date: /usr/local/include/gtest/gtest-param-test.h.pump
-- Up-to-date: /usr/local/include/gtest/gtest-test-part.h
-- Up-to-date: /usr/local/include/gtest/gtest-spi.h
-- Up-to-date: /usr/local/include/gtest/gtest-param-test.h
-- Up-to-date: /usr/local/include/gtest/gtest-death-test.h
-- Up-to-date: /usr/local/include/gtest/gtest_prod.h
-- Installing: /usr/local/lib/libgtest.a
-- Installing: /usr/local/lib/libgtest_main.a
-- Up-to-date: /usr/local/lib/pkgconfig/gtest.pc
-- Up-to-date: /usr/local/lib/pkgconfig/gtest_main.pc

```

## undefined reference to 'pthread_getspecific' when using cmake for googletest
https://stackoverflow.com/questions/48137568/undefined-reference-to-pthread-getspecific-when-using-cmake-for-googletest

Use following cmake to include pthread while compiling.

```cmake
cmake_minimum_required(VERSION 2.8.8)

set(TARGET_NAME XXproject_Client_Test)

project(${TARGET_NAME})

find_package(PkgConfig REQUIRED)

pkg_search_module(LIBGTEST REQUIRED gtest_main)

# Google Test
add_executable(${TARGET_NAME} Unit_Gtest.cpp Libcurl_Tester.cpp Sqlite3_Tester.cpp)

# For gtest
target_link_libraries(${TARGET_NAME} gtest gtest_main pthread)
target_include_directories(${TARGET_NAME} PUBLIC ${LIBGTEST_INCLUDE_DIRS})
target_compile_options(${TARGET_NAME} PUBLIC ${LIBGTEST_CFLAGS_OTHER})
target_link_libraries(${TARGET_NAME} ${LIBPTHREAD_LIBRARIES})
target_include_directories(${TARGET_NAME} PUBLIC ${LIBPTHREAD_INCLUDE_DIRS})
target_compile_options(${TARGET_NAME} PUBLIC ${LIBPTHREAD_CFLAGS_OTHER})
include_directories("${PROJECT_SOURCE_DIR}/Client_Core")
target_link_libraries(${TARGET_NAME} XXproject_Client_Core)

enable_testing()
add_test(${TARGET_NAME} ${TARGET_NAME})
```

## gtest compile with c++, but not pure c

https://github.com/google/googletest/issues/1279

It will lost alot lib to include, and gtest will not add this into supporting feature.

So, if you try to use gtest to test with pure c project, your test case script in c++ sould add "C" macro to include c header, or it will not found the header even the function you want to test.

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <gtest/gtest.h>
extern "C"
{
  #include "../Client_Core/Libcurl_Wrapper.h"
}

/**
* Google Test Case Tester for Unit Test
* test_curl() in Libcurl_Wrapper.cpp
*/
namespace {
    TEST(CoreUnitTest, LibcurlWrapper) {
        EXPECT_TRUE(test_curl());
    }
}
```
Well, somthing like that.