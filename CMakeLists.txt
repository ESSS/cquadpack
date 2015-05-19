cmake_minimum_required(VERSION 2.8.6)

project(cquadpack)

include_directories(include)

set(source_files
    src/dqag.c
    src/dqage.c
    src/dqagi.c
    src/dqagp.c
    src/dqags.c
    src/dqawc.c
    src/dqawce.c
    src/dqawf.c
    src/dqawfe.c
    src/dqawo.c
    src/dqaws.c
    src/dqawse.c
    src/dqc25c.c
    src/dqc25o.c
    src/dqc25s.c
    src/dqcheb.c
    src/dqext.c
    src/dqfour.c
    src/dqk15.c
    src/dqk15i.c
    src/dqk15w.c
    src/dqk21.c
    src/dqk31.c
    src/dqk41.c
    src/dqk51.c
    src/dqk61.c
    src/dqmomo.c
    src/dqng.c
    src/dqsort.c
    src/dqwgt.c
)
set(header_files
    include/cquadpak.h
)

set(targets cquadpack cquadpack_dll)

# Static library
set(BUILD_SHARED_LIBS ON)
add_library(cquadpack STATIC ${source_files} ${header_files})
set_target_properties(cquadpack PROPERTIES
    COMPILE_FLAGS -DCQUADPACK_DLL_STATIC_DEFINE)

# Shared library
add_library(cquadpack_dll SHARED ${source_files} ${header_files})
set_property(TARGET cquadpack_dll PROPERTY POSITION_INDEPENDENT_CODE 1)


# Add export header
include (GenerateExportHeader)
generate_export_header(cquadpack_dll)
include_directories(${PROJECT_BINARY_DIR})

set(tests
    dq4tst
    dqaget
    dqagit
    #dqagpt
    dqagst
    dqagtst
    dqawct
    dqawft
    dqawot
    dqawst
    dqct
    dqngt
)

enable_testing()
foreach(test_target ${tests})
  # An executable with the STATIC version
  add_executable(${test_target} test/${test_target}.c ${header_files})
  set_target_properties(${test_target} PROPERTIES
    COMPILE_FLAGS -DCQUADPACK_DLL_STATIC_DEFINE)
  target_link_libraries(${test_target} cquadpack)
  add_test(NAME ${test_target} COMMAND ${test_target})

  # An executable with the SHARED version
  add_executable(${test_target}_dll test/${test_target}.c ${header_files})
  target_link_libraries(${test_target}_dll cquadpack_dll)
  add_test(NAME ${test_target}_dll COMMAND ${test_target}_dll)
endforeach(test_target)

foreach(target ${targets})
    # Add the math libraries (gcc requires this)
    if(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
        target_link_libraries(${target} m)
    endif()
endforeach(target)

install(TARGETS ${targets}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
