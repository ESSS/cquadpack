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
    include/cquadpack.h
)

set(targets cquadpack cquadpack_static)

# Static library
set(BUILD_SHARED_LIBS ON)
add_library(cquadpack_static STATIC ${source_files} ${header_files})
set_target_properties(cquadpack_static PROPERTIES
    COMPILE_FLAGS -DCQUADPACK_STATIC_DEFINE)

# Shared library
add_library(cquadpack SHARED ${source_files} ${header_files})
set_property(TARGET cquadpack PROPERTY POSITION_INDEPENDENT_CODE 1)


# Add export header
include (GenerateExportHeader)
generate_export_header(cquadpack)
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
  add_executable(${test_target}_static test/${test_target}.c ${header_files})
  set_target_properties(${test_target}_static PROPERTIES
    COMPILE_FLAGS -DCQUADPACK_STATIC_DEFINE)
  target_link_libraries(${test_target}_static cquadpack_static)
  add_test(NAME ${test_target}_static COMMAND ${test_target}_static)

  # An executable with the SHARED version
  add_executable(${test_target} test/${test_target}.c ${header_files})
  target_link_libraries(${test_target} cquadpack)
  add_test(NAME ${test_target} COMMAND ${test_target})
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

install(FILES
    include/cquadpack.h
    DESTINATION include
)
