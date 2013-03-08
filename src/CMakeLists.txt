# File generation
configure_file(${ATHENA_GUI_SOURCE_DIR}/src/module.cpp.in
               ${XMAKE_BINARY_DIR}/generated/Athena-GUI/module.cpp)

# List the header files
set(HEADERS ${XMAKE_BINARY_DIR}/include/Athena-GUI/Config.h
            ../include/Athena-GUI/Prerequisites.h
)

# List the source files
set(SRCS ${XMAKE_BINARY_DIR}/generated/Athena-GUI/module.cpp
)


# List the include paths
set(INCLUDE_PATHS "${ATHENA_GUI_SOURCE_DIR}/include"
                  "${XMAKE_BINARY_DIR}/include")

include_directories(${INCLUDE_PATHS})

xmake_import_search_paths(ATHENA_CORE)


# Declaration of the library
xmake_create_dynamic_library(ATHENA_GUI Athena-GUI
                             "${ATHENA_GUI_VERSION_MAJOR}.${ATHENA_GUI_VERSION_MINOR}.${ATHENA_GUI_VERSION_PATCH}"
                             "${ATHENA_GUI_VERSION_MAJOR}.${ATHENA_GUI_VERSION_MINOR}.${ATHENA_GUI_VERSION_PATCH}"
                             ${HEADERS} ${SRCS} ${PLATFORM_HEADERS} ${PLATFORM_SRCS})

xmake_add_to_list_property(ATHENA_GUI COMPILE_DEFINITIONS "ATHENA_GUI_EXPORTS")

xmake_project_link(ATHENA_GUI ATHENA_CORE)


# Disable some warnings in Visual Studio
xmake_add_to_list_property(ATHENA_GUI COMPILE_DEFINITIONS "_CRT_SECURE_NO_WARNINGS")
xmake_disable_vs_warning(ATHENA_GUI 4251 YES)
xmake_disable_vs_warning(ATHENA_GUI 4661 YES)


# Exportations
xmake_export_include_paths(ATHENA_GUI ${INCLUDE_PATHS})
