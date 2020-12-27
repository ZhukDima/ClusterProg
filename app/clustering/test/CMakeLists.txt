include_directories("${PROJECT_SOURCE_DIR}/app/clustering/include/")

file(GLOB tests "${PROJECT_SOURCE_DIR}/app/clustering/test/*.cpp")
list(REMOVE_ITEM tests "${PROJECT_SOURCE_DIR}/app/clustering/test/main.cpp")

foreach (file ${tests})
    set(name)
    get_filename_component(name ${file} NAME_WE)
    add_executable("${name}_tests"
            ${sources}
            ${file}
            "${PROJECT_SOURCE_DIR}/app/clustering/test/main.cpp")
    target_link_libraries("${name}_tests" gtest_main)
    add_test(NAME ${name} COMMAND "${name}_tests")
endforeach ()
