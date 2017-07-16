cmake_minimum_required(VERSION 2.8)

project(alluis.lv2)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/osc.lv2)
include_directories(${PROJECT_SOURCE_DIR}/props.lv2)
include_directories(${PROJECT_SOURCE_DIR}/xpress.lv2)

set(CMAKE_C_FLAGS "-std=gnu11 -Wextra -Wno-unused-parameter -ffast-math -fvisibility=hidden ${CMAKE_C_FLAGS}")
set(CMAKE_C_FLAGS "-Wshadow -Wimplicit-function-declaration -Wmissing-prototypes -Wstrict-prototypes ${CMAKE_C_FLAGS}")
set(CMAKE_MODULE_LINKER_FLAGS "-Wl,-z,nodelete -Wl,-z,defs ${CMAKE_MODULE_LINKER_FLAGS}")

set(ALLUIS_MAJOR_VERSION 0)
set(ALLUIS_MINOR_VERSION 1)
set(ALLUIS_MICRO_VERSION 1)
set(ALLUIS_VERSION "${ALLUIS_MAJOR_VERSION}.${ALLUIS_MINOR_VERSION}.${ALLUIS_MICRO_VERSION}")

set(DEST lib/lv2/alluis.lv2)

find_package(PkgConfig) # ${PKG_CONFIG_FOUND}

set(LIBS m) # math library

pkg_search_module(LV2 REQUIRED lv2>=1.10)
include_directories(${LV2_INCLUDE_DIRS})

pkg_search_module(XCB REQUIRED xcb>=1.10) # XCB

pkg_search_module(GTK2 REQUIRED gtk+-2.0) # gtk+-2.0

pkg_search_module(GTK3 REQUIRED gtk+-3.0) # gtk+-3.0

pkg_search_module(QT4CORE REQUIRED QtCore) # Qt4Core
pkg_search_module(QT4GUI REQUIRED QtGui) # Qt4Gui

pkg_search_module(QT5CORE REQUIRED Qt5Core) # Qt5Core
pkg_search_module(QT5WIDGETS REQUIRED Qt5Widgets) # Qt5Widgets
pkg_search_module(QT5GUI REQUIRED Qt5Gui) # Qt5Gui

add_library(alluis MODULE
	test.c)
set_target_properties(alluis PROPERTIES PREFIX "")
install(TARGETS alluis DESTINATION ${DEST})

add_library(alluis_x11 MODULE
	test_x11.c)
target_link_libraries(alluis_x11
	${XCB_LDFLAGS})
target_include_directories(alluis_x11 PUBLIC ${XCB_INCLUDE_DIRS})
set_target_properties(alluis_x11 PROPERTIES PREFIX "")
install(TARGETS alluis_x11 DESTINATION ${DEST})

add_library(alluis_gtk2 MODULE
	test_gtk2.c)
target_link_libraries(alluis_gtk2
	${GTK2_LDFLAGS})
target_include_directories(alluis_gtk2 PUBLIC ${GTK2_INCLUDE_DIRS})
set_target_properties(alluis_gtk2 PROPERTIES PREFIX "")
install(TARGETS alluis_gtk2 DESTINATION ${DEST})

add_library(alluis_gtk3 MODULE
	test_gtk3.c)
target_link_libraries(alluis_gtk3
	${GTK3_LDFLAGS})
target_include_directories(alluis_gtk3 PUBLIC ${GTK3_INCLUDE_DIRS})
set_target_properties(alluis_gtk3 PROPERTIES PREFIX "")
install(TARGETS alluis_gtk3 DESTINATION ${DEST})

add_library(alluis_qt4 MODULE
	test_qt4.cpp)
target_link_libraries(alluis_qt4
	${QT4CORE_LDFLAGS}
	${QT4GUI_LDFLAGS})
target_include_directories(alluis_qt4 PUBLIC ${QT4CORE_INCLUDE_DIRS})
target_include_directories(alluis_qt4 PUBLIC ${QT4GUI_INCLUDE_DIRS})
set_target_properties(alluis_qt4 PROPERTIES PREFIX "")
install(TARGETS alluis_qt4 DESTINATION ${DEST})

#add_library(alluis_qt5 MODULE
#	test_qt5.cpp)
#target_link_libraries(alluis_qt5
#	${QT5CORE_LDFLAGS}
#	${QT5WIDGETS_LDFLAGS}
#	${QT5GUI_LDFLAGS})
#target_include_directories(alluis_qt5 PUBLIC ${QT5CORE_INCLUDE_DIRS})
#target_include_directories(alluis_qt5 PUBLIC ${QT5WIDGETS_INCLUDE_DIRS})
#target_include_directories(alluis_qt5 PUBLIC ${QT5GUI_INCLUDE_DIRS})
#set_target_properties(alluis_qt5 PROPERTIES PREFIX "")
#install(TARGETS alluis_qt5 DESTINATION ${DEST})

add_library(alluis_show MODULE
	test_show.c)
set_target_properties(alluis_show PROPERTIES PREFIX "")
install(TARGETS alluis_show DESTINATION ${DEST})

add_library(alluis_kx MODULE
	test_kx.c)
set_target_properties(alluis_kx PROPERTIES PREFIX "")
install(TARGETS alluis_kx DESTINATION ${DEST})

configure_file(${PROJECT_SOURCE_DIR}/manifest.ttl.in
	${PROJECT_BINARY_DIR}/manifest.ttl)
install(FILES ${PROJECT_BINARY_DIR}/manifest.ttl DESTINATION ${DEST})
install(FILES ${PROJECT_SOURCE_DIR}/alluis.ttl DESTINATION ${DEST})
install(FILES ${PROJECT_SOURCE_DIR}/alluis_ui.ttl DESTINATION ${DEST})
