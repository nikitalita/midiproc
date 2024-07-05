# Install script for directory: /Users/andyvand/Downloads/midiproc-AnV

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/bin/llvm-objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/libmidiproc.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib" TYPE STATIC_LIBRARY FILES "/Users/andyvand/Downloads/midiproc-AnV/buildandroid_i686/libmidiproc.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/midiproc/midiproc.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/midiproc" TYPE FILE FILES "/Users/andyvand/Downloads/midiproc-AnV/src/midiproc.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/midiproc/MIDIContainer.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/midiproc" TYPE FILE FILES "/Users/andyvand/Downloads/midiproc-AnV/src/MIDIContainer.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/midiproc/MIDIProcessor.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/midiproc" TYPE FILE FILES "/Users/andyvand/Downloads/midiproc-AnV/src/MIDIProcessor.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/midiproc/Range.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/midiproc" TYPE FILE FILES "/Users/andyvand/Downloads/midiproc-AnV/src/Range.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/cmake/midiproc/midiproc-targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/cmake/midiproc/midiproc-targets.cmake"
         "/Users/andyvand/Downloads/midiproc-AnV/buildandroid_i686/CMakeFiles/Export/eea57f8a40eb4b384d223cf8b61717de/midiproc-targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/cmake/midiproc/midiproc-targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/cmake/midiproc/midiproc-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/cmake/midiproc/midiproc-targets.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/cmake/midiproc" TYPE FILE FILES "/Users/andyvand/Downloads/midiproc-AnV/buildandroid_i686/CMakeFiles/Export/eea57f8a40eb4b384d223cf8b61717de/midiproc-targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/cmake/midiproc/midiproc-targets-release.cmake")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/cmake/midiproc" TYPE FILE FILES "/Users/andyvand/Downloads/midiproc-AnV/buildandroid_i686/CMakeFiles/Export/eea57f8a40eb4b384d223cf8b61717de/midiproc-targets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/cmake/midiproc/midiprocConfigVersion.cmake;/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/cmake/midiproc/midiprocConfig.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/cmake/midiproc" TYPE FILE FILES
    "/Users/andyvand/Downloads/midiproc-AnV/buildandroid_i686/midiprocConfigVersion.cmake"
    "/Users/andyvand/Downloads/midiproc-AnV/buildandroid_i686/midiprocConfig.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/pkgconfig/midiproc.pc")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/pkgconfig" TYPE FILE FILES "/Users/andyvand/Downloads/midiproc-AnV/buildandroid_i686/midiproc.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/share/midiproc/copyright")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/share/midiproc" TYPE FILE RENAME "copyright" FILES "/Users/andyvand/Downloads/midiproc-AnV/LICENSE")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/andyvand/Downloads/midiproc-AnV/buildandroid_i686/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
