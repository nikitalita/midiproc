#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "midiproc::midiproc" for configuration "Release"
set_property(TARGET midiproc::midiproc APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(midiproc::midiproc PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX"
  IMPORTED_LOCATION_RELEASE "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/libmidiproc.a"
  )

list(APPEND _cmake_import_check_targets midiproc::midiproc )
list(APPEND _cmake_import_check_files_for_midiproc::midiproc "/Users/andyvand/Library/Android/sdk/ndk/27.0.11902837/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/libmidiproc.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
