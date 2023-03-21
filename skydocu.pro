QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Location of build files
OBJECTS_DIR = build/objects
MOC_DIR = build/moc
QMAKE_CLEAN += $(TARGET) Makefile

# Compilation flags
QMAKE_CXX = g++
QMAKE_CXXFLAGS_DEBUG += -g -fsanitize=address
QMAKE_LFLAGS_DEBUG += -g -fsanitize=address

# Source files
SOURCES += $$system(find ./src/ -type f -name "*.cpp")
HEADERS += $$system(find ./src/ -type f -name "*.h")
FORMS += src/forms/mainwindow.ui \
    src/forms/sudokuwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
