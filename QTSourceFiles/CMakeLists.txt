
# Создаем объектную библиотеку
add_library(QTlib
        webSocet.cpp
)

target_link_libraries(QTlib
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::WebSockets
        MainLib
)