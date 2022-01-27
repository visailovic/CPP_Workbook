cmake_minimum_required(VERSION 3.15.0 FATAL_ERROR)

set(CMAKE_SYSTEM_VERSION 10.0 CACHE STRING "" FORCE)

project(C++Workbook CXX)

################################################################################
# Set target arch type if empty. Visual studio solution generator provides it.
################################################################################
if(NOT CMAKE_VS_PLATFORM_NAME)
    set(CMAKE_VS_PLATFORM_NAME "x64")
endif()
message("${CMAKE_VS_PLATFORM_NAME} architecture in use")

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"
     OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86"))
    message(FATAL_ERROR "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif()

################################################################################
# Global configuration types
################################################################################
set(CMAKE_CONFIGURATION_TYPES
    "Debug"
    "Release"
    CACHE STRING "" FORCE
)

################################################################################
# Global compiler options
################################################################################
if(MSVC)
    # remove default flags provided with CMake for MSVC
    set(CMAKE_CXX_FLAGS "")
    set(CMAKE_CXX_FLAGS_DEBUG "")
    set(CMAKE_CXX_FLAGS_RELEASE "")
endif()

################################################################################
# Global linker options
################################################################################
if(MSVC)
    # remove default flags provided with CMake for MSVC
    set(CMAKE_EXE_LINKER_FLAGS "")
    set(CMAKE_MODULE_LINKER_FLAGS "")
    set(CMAKE_SHARED_LINKER_FLAGS "")
    set(CMAKE_STATIC_LINKER_FLAGS "")
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_RELEASE "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_RELEASE "${CMAKE_STATIC_LINKER_FLAGS}")
endif()

################################################################################
# Nuget packages function stub.
################################################################################
function(use_package TARGET PACKAGE VERSION)
    message(WARNING "No implementation of use_package. Create yours. "
                    "Package \"${PACKAGE}\" with version \"${VERSION}\" "
                    "for target \"${TARGET}\" is ignored!")
endfunction()

################################################################################
# Common utils
################################################################################
include(CMake/Utils.cmake)

################################################################################
# Additional Global Settings(add specific info there)
################################################################################
include(CMake/GlobalSettingsInclude.cmake OPTIONAL)

################################################################################
# Use solution folders feature
################################################################################
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

################################################################################
# Sub-projects
################################################################################
add_subdirectory(01_C++_Basics_Example_01)
add_subdirectory(01_C++_Basics_Example_02)
add_subdirectory(02_Variables_And_Fundamental_Data_Types_Example_01)
add_subdirectory(02_Variables_And_Fundamental_Data_Types_Example_02)
add_subdirectory(02_Variables_And_Fundamental_Data_Types_Example_03)
add_subdirectory(02_Variables_And_Fundamental_Data_Types_Example_04)
add_subdirectory(02_Variables_And_Fundamental_Data_Types_Example_05)
add_subdirectory(02_Variables_And_Fundamental_Data_Types_Example_06)
add_subdirectory(02_Variables_And_Fundamental_Data_Types_Example_07)
add_subdirectory(03_Control_Flow_Example_01)
add_subdirectory(03_Control_Flow_Example_02)
add_subdirectory(03_Control_Flow_Example_03)
add_subdirectory(03_Control_Flow_Example_04)
add_subdirectory(03_Control_Flow_Example_05)
add_subdirectory(03_Control_Flow_Example_06)
add_subdirectory(03_Control_Flow_Example_07)
add_subdirectory(03_Control_Flow_Example_08)
add_subdirectory(03_Control_Flow_Example_09)
add_subdirectory(04_Compound_Data_Types_Exercise_01)
add_subdirectory(04_Compound_Data_Types_Exercise_02)
add_subdirectory(04_Compound_Data_Types_Exercise_03)
add_subdirectory(04_Compound_Data_Types_Exercise_04)
add_subdirectory(04_Compound_Data_Types_Exercise_05)
add_subdirectory(04_Compound_Data_Types_Exercise_06)
add_subdirectory(04_Compound_Data_Types_Exercise_07)
add_subdirectory(04_Compound_Data_Types_Exercise_08)
add_subdirectory(04_Compound_Data_Types_Exercise_09)
add_subdirectory(04_Compound_Data_Types_Exercise_10)
add_subdirectory(05_Arrays_Pointers_And_References_Exercise_01)
add_subdirectory(05_Arrays_Pointers_And_References_Exercise_02)
add_subdirectory(05_Arrays_Pointers_And_References_Exercise_03)
add_subdirectory(05_Arrays_Pointers_And_References_Exercise_04)
add_subdirectory(05_Arrays_Pointers_And_References_Exercise_05)
add_subdirectory(05_Arrays_Pointers_And_References_Exercise_06)
add_subdirectory(05_Arrays_Pointers_And_References_Exercise_07)
add_subdirectory(05_Arrays_Pointers_And_References_Exercise_08)
add_subdirectory(05_Arrays_Pointers_And_References_Exercise_09)
add_subdirectory(05_Arrays_Pointers_And_References_Exercise_10)
add_subdirectory(06_Functions_Exercise_01)
add_subdirectory(06_Functions_Exercise_02)
add_subdirectory(06_Functions_Exercise_03)
add_subdirectory(06_Functions_Exercise_04)
add_subdirectory(06_Functions_Exercise_05)
add_subdirectory(07_Basic_object_oriented_programming_Exercise_01)
add_subdirectory(07_Basic_object_oriented_programming_Exercise_02)
add_subdirectory(07_Basic_object_oriented_programming_Exercise_03)
add_subdirectory(07_Basic_object_oriented_programming_Exercise_04)
add_subdirectory(08_Operator_Overloading_Exercise_01)
add_subdirectory(08_Operator_Overloading_Exercise_02)
add_subdirectory(08_Operator_Overloading_Exercise_03)
add_subdirectory(08_Operator_Overloading_Exercise_04)
add_subdirectory(09_Inheritance_And_Polymorphism_Exercise_01)
add_subdirectory(09_Inheritance_And_Polymorphism_Exercise_02)
add_subdirectory(09_Inheritance_And_Polymorphism_Exercise_03)
add_subdirectory(10_Introduction_To_Exception_Handling_Exercise_01)
add_subdirectory(10_Introduction_To_Exception_Handling_Exercise_02)
add_subdirectory(11_Lists_Exercise_01)
add_subdirectory(11_Lists_Exercise_02)
add_subdirectory(12_Generic_Programming_Exercise_01)
add_subdirectory(12_Generic_Programming_Exercise_02)
add_subdirectory(12_Generic_Programming_Exercise_03)

