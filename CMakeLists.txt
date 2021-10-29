cmake_minimum_required (VERSION 3.8)
project (TEST_APP)

set (CMAKE_WARN_DEPRECATED FALSE CACHE BOOL "Whether to issue warnings for deprecated functionality." FORCE)

macro (set_default_policies)
    # Honor visibility properties for all target types
    if (POLICY CMP0063)
        cmake_policy (SET CMP0063 NEW)
    endif ()

    # find_package() uses <PackageName>_ROOT variables.
    if (POLICY CMP0074)
        cmake_policy(SET CMP0074 NEW)
    endif ()

    # To control generation of Position Independent Executable (PIE) or not, some flags are required at link time.
    if (POLICY CMP0083)
        cmake_policy(SET CMP0083 NEW)
    endif ()

    # add_test() supports arbitrary characters in test names.
    if (POLICY CMP0110)
        cmake_policy(SET CMP0110 NEW)
    endif ()
endmacro ()

set_default_policies()

add_executable(test_app main.cpp temperature.cpp)

set_target_properties(
    test_app PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED on
    C_EXTENSIONS off
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED on
    CXX_EXTENSIONS off
    DISABLE_PRECOMPILE_HEADERS on
    )

find_package(Threads REQUIRED)
find_package(Boost 1.71.0 REQUIRED)

if (APPLE)
    find_library(FWCoreFoundation NAMES CoreFoundation REQUIRED)
    find_library(FWSecurity NAMES Security REQUIRED)
    find_library(FWIOKit NAMES IOKit REQUIRED)
endif ()

Include(FetchContent)

FetchContent_Declare(fmt
    GIT_REPOSITORY   https://github.com/fmtlib/fmt.git
    GIT_TAG          8.0.1
)
FetchContent_GetProperties(fmt)
if (NOT fmt_POPULATED)
    FetchContent_Populate(fmt)
    # set(MESSAGE_QUIET ON)
    add_subdirectory(${fmt_SOURCE_DIR} ${fmt_BINARY_DIR} EXCLUDE_FROM_ALL)
    # unset(MESSAGE_QUIET)
endif ()

target_compile_definitions(
    test_app
    PRIVATE $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:_GNU_SOURCE>
    PRIVATE $<$<AND:$<CONFIG:Debug>,$<NOT:$<CXX_COMPILER_ID:MSVC>>>:DEBUG>
    PRIVATE $<$<AND:$<CONFIG:Debug>,$<NOT:$<CXX_COMPILER_ID:MSVC>>>:_DEBUG>
    PRIVATE $<$<AND:$<NOT:$<CONFIG:Debug>>,$<NOT:$<CXX_COMPILER_ID:MSVC>>>:NDEBUG>
)

target_compile_options(
    test_app
    PRIVATE $<$<CXX_COMPILER_ID:AppleClang,Clang>:-stdlib=libc++>
    PRIVATE $<$<CXX_COMPILER_ID:AppleClang,Clang,GNU>:-g>
    PRIVATE $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:AppleClang,Clang,GNU>>:-Og>
    PRIVATE $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:AppleClang,Clang,GNU>>:-g3>
    PRIVATE $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:AppleClang,Clang>>:-glldb>
    PRIVATE $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:AppleClang,Clang>>:-fdebug-macro>
    PRIVATE $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:GNU>>:-ggdb3>
    PRIVATE $<$<AND:$<NOT:$<CONFIG:Debug>>,$<CXX_COMPILER_ID:AppleClang,Clang,GNU>>:-O2>
)

target_include_directories(
    test_app SYSTEM
    PRIVATE ${Boost_INCLUDE_DIRS}
    PRIVATE ${fmt_SOURCE_DIR}/include
)

target_link_libraries(
    test_app
    PRIVATE ${Boost_LIBRARIES}
    PRIVATE fmt::fmt
    PRIVATE $<$<CXX_COMPILER_ID:AppleClang,Clang>:-lc++>
    PRIVATE $<$<CXX_COMPILER_ID:AppleClang,Clang>:-lc++abi>
    PRIVATE $<$<PLATFORM_ID:Darwin>:${FWCoreFoundation}>
    PRIVATE $<$<PLATFORM_ID:Darwin>:${FWSecurity}>
    PRIVATE $<$<PLATFORM_ID:Darwin>:${FWIOKit}>
    PRIVATE Threads::Threads
    PRIVATE ${CMAKE_DL_LIBS}
)
