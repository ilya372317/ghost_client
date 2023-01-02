cmake_minimum_required(VERSION 3.16)
project(ghost_client LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/widgets/itemviews/ghost_list")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_add_executable(ghost_client
        main.cpp
        src/Widget/MainWindow.cpp
        src/Widget/MainWindow.h
        src/Model/Post/PostModel.cpp
        src/Model/Post/PostModel.h
        src/Widget/Library/TextEditor.cpp
        src/Widget/Library/TextEditor.h
        src/Widget/Post/Edit/PostEditWindow.cpp
        src/Widget/Post/Edit/PostEditWindow.h
        src/Widget/Post/View/PostListWidget.cpp
        src/Widget/Post/View/PostListWidget.h
        src/Widget/ChildWidgetInterface.h
        src/Parser/WebClientInterface.h
        src/Parser/Ghost/GhostClient.cpp
        src/Parser/Ghost/GhostClient.h
        )

set_target_properties(ghost_client PROPERTIES
        WIN32_EXECUTABLE TRUE
        MACOSX_BUNDLE TRUE
        )

target_link_libraries(ghost_client PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        )

install(TARGETS ghost_client
        RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
        BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
        LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
        )

# Resources:
set(ghost_client_resource_files
        "Images/ghost-logo-dark.png"
        )

qt_add_resources(ghost_client "ghost_client"
        PREFIX
        "/"
        FILES
        ${notepad_resource_files}
        )


