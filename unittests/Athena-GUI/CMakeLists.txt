# Setup the search paths
xmake_import_search_paths(ATHENA_GUI)
xmake_import_search_paths(UNITTEST_CPP)

# if (DEFINED ATHENA_SCRIPTING_ENABLED AND ATHENA_SCRIPTING_ENABLED)
#     xmake_import_search_paths(ATHENA_SCRIPTING)
# endif()


# List the header files
set(HEADERS environments/GUITestEnvironment.h
            mocks/MockRenderInterface.h
)

# List the source files
set(SRCS main.cpp
         tests/test_GUIManager.cpp
)

# if (DEFINED ATHENA_SCRIPTING_ENABLED AND ATHENA_SCRIPTING_ENABLED)
#     set(HEADERS ${HEADERS} environments/ScriptingTestEnvironment.h)
#     set(SRCS ${SRCS} tests/scripting.cpp)
# endif()


# Declaration of the executable
xmake_create_executable(UNITTESTS_ATHENA_GUI UnitTests-Athena-GUI ${HEADERS} ${SRCS})

# xmake_add_to_list_property(UNITTESTS_ATHENA_GUI COMPILE_DEFINITIONS "ATHENA_GUI_UNITTESTS_SCRIPTS_PATH=\"${ATHENA_GUI_SOURCE_DIR}/unittests/Athena-GUI/scripts/\";ATHENA_SCRIPTING_JS_TEST_RUNNER_PATH=\"${ATHENA_SCRIPTING_SOURCE_DIR}/unittests/js-test-runner/\"")

xmake_project_link(UNITTESTS_ATHENA_GUI UNITTEST_CPP)
xmake_project_link(UNITTESTS_ATHENA_GUI ATHENA_GUI)

# if (DEFINED ATHENA_SCRIPTING_ENABLED AND ATHENA_SCRIPTING_ENABLED)
#     xmake_project_link(UNITTESTS_ATHENA_ENTITIES ATHENA_SCRIPTING)
# 
#     add_dependencies(UnitTests-Athena-Entities Athena-Entities-Scripting-module Run-UnitTests-Athena-Scripting)
# endif()


# Run the unit tests
set(WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
if (WIN32)
    set(WORKING_DIRECTORY "${WORKING_DIRECTORY}/$(OutDir)")
endif()

add_custom_target(Run-UnitTests-Athena-GUI ALL UnitTests-Athena-GUI
                  DEPENDS UnitTests-Athena-GUI
                  WORKING_DIRECTORY ${WORKING_DIRECTORY}
                  COMMENT "Unit testing: Athena-GUI..." VERBATIM)
