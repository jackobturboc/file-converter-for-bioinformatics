add_library(sourceFiles
        qtgeneralwindows.cpp
        manager.cpp
        sequences_files_format_descriptions.cpp
        interface.cpp
        container.cpp
        reader.cpp
        writer.cpp
)

add_library(MainLib
        qtgeneralwindows.cpp
        manager.cpp
        sequences_files_format_descriptions.cpp
        interface.cpp
        container.cpp
        reader.cpp
        #        widget.cpp
        writer.cpp
)

target_link_libraries(sourceFiles
        Qt5::Widgets
)