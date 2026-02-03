add_library(src
        qtgeneralwindows.cpp
        manager.cpp
        sequences_files_format_descriptions.cpp
        interface.cpp
)

target_link_libraries(src
        Qt5::Widgets
)