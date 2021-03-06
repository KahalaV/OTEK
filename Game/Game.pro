TEMPLATE = app
TARGET = NYSSE

QT += core gui widgets network multimedia testlib

CONFIG += c++14

SOURCES += \
    actoritem.cpp \
    bomb.cpp \
    city.cpp \
    cloud.cpp \
    endwindow.cpp \
    engine.cpp \
    main.cc \
    mainwindow.cpp \
    nuke.cpp \
    player.cpp \
    split.cpp \
    startwindow.cpp \
    statistics.cpp \
    teststatistics.cpp

win32:CONFIG(release, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/ -lCourseLib

INCLUDEPATH += \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Course/CourseLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/libCourseLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/libCourseLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/CourseLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/CourseLib.lib
else:unix: PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/libCourseLib.a

FORMS += \
    endwindow.ui \
    mainwindow.ui \
    startwindow.ui

HEADERS += \
    actoritem.h \
    bomb.h \
    city.h \
    cloud.h \
    endwindow.h \
    engine.h \
    mainwindow.h \
    nuke.h \
    player.h \
    split.h \
    startwindow.h \
    statistics.h \
    teststatistics.h

RESOURCES += \
    Resources.qrc

