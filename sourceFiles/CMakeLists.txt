
# Находим все файлы в подпапке
file(GLOB LIB_SOURCES "*.cpp")

# Создаем объектную библиотеку
add_library(MainLib OBJECT ${LIB_SOURCES})

target_link_libraries(MainLib
        PUBLIC
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
  #      Qt5::WebSockets
)