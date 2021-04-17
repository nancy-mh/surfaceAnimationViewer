QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    customglwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    objimageloader.cpp

HEADERS += \
    OBJ_Loader.h \
    customglwidget.h \
    mainwindow.h \
    objimageloader.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

mac: LIBS += -framework GLUT
else:win32: LIBS += -lGLUT
