cmake_minimum_required(VERSION 3.5)

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


add_library(cquadpack ${source_files} ${header_files})
if (${BUILD_SHARED_LIBS})
    # Shared library
    message(STATUS "Will compile the library in shared mode")
    set_property(TARGET cquadpack PROPERTY POSITION_INDEPENDENT_CODE 1)
else()
    # Static library
    message(STATUS "Will compile the library in static mode")
    add_definitions(-DCQUADPACK_STATIC_DEFINE)
endif()

# Add export header
include(GenerateExportHeader)
generate_export_header(cquadpack)
include_directories(${PROJECT_BINARY_DIR})

set(tests
    dq4tst
    dqaget
    dqagit
    dqagpt
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
    add_executable(${test_target} test/${test_target}.c ${header_files})
    add_test(NAME ${test_target} COMMAND $<TARGET_FILE:${test_target}> --exe)
    target_link_libraries(${test_target} cquadpack)
endforeach(test_target)

# Add the math libraries (gcc requires this)
if(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    target_link_libraries(cquadpack m)
endif()

install(TARGETS cquadpack
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(FILES
    include/cquadpack.h
    ${PROJECT_BINARY_DIR}/cquadpack_export.h
    DESTINATION include
)
