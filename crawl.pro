TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

#add a generated files dir in source so that we can link the symbol browser to it more easily.
GENERATED_FILES_DIR = $${_PRO_FILE_PWD_}/generated

#configure the flatbuffer compiler
faltbuffers.input = FLATBUFFER_DEFINITIONS
faltbuffers.output = $${GENERATED_FILES_DIR}/flatbuffers/${QMAKE_FILE_BASE}_generated.h
faltbuffers.variable_out = HEADERS
faltbuffers.CONFIG += no_link
faltbuffers.commands = $$_PRO_FILE_PWD_/libs/flatbuffers/flatbuffers/flatc -c -o $${GENERATED_FILES_DIR}/flatbuffers $$_PRO_FILE_PWD_/${QMAKE_FILE_NAME}
QMAKE_EXTRA_COMPILERS += faltbuffers


INCLUDEPATH += ./libs/flatbuffers/flatbuffers/include \
                $${GENERATED_FILES_DIR}/flatbuffers

linux-g++ {
    CONFIG += link_pkgconfig
    PKGCONFIG += sdl2
} else {
    error("sdl is not linked")
}

SOURCES += \
    src/game.cpp \
    src/main.cpp \
    src/system.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    src/game.h \
    src/system.h

FLATBUFFER_DEFINITIONS += \
    src/flatbuffers/game.fbs

