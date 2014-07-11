cmake_minimum_required(VERSION 2.8)

project(cquadpack C)

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

set(targets cquadpack_dll cquadpack)

add_library(cquadpack STATIC ${source_files})
add_library(cquadpack_dll SHARED ${source_files})

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
  add_executable(${test_target} test/${test_target}.c)
  target_link_libraries(${test_target} cquadpack)
  add_test(NAME ${test_target} COMMAND ${test_target})
endforeach(test_target)


# Set the output directory to 'lib'
foreach(target ${targets})
    set_target_properties(${target} PROPERTIES LIBRARY_OUTPUT_DIRECTORY lib)
    set_target_properties(${target} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY lib)
    set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY lib)
endforeach(target)
