#-------------------------------------------------
#
# Project created by QtCreator 2016-02-22T10:36:12
#
#-------------------------------------------------

QT       += core

QT       += gui
QT   += widgets

TARGET = SilhouettesExtractor
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app


SOURCES += main.cpp \
    HumanPartsExtractorStorage/humanpartsextractor.cpp \
    HumanPartsExtractorStorage/bodypartshaperecognizeralgorithm.cpp \
    extractedobject.cpp \
    recursiveiterationalgorithm.cpp \
    humansilhouetteprobability.cpp \
    HumanPartsExtractorStorage/bodyproportionrecognizeralgorithm.cpp

HEADERS += \
    HumanPartsExtractorStorage/humanpartsextractor.h \
    HumanPartsExtractorStorage/bodypartshaperecognizeralgorithm.h \
    extractedobject.h \
    recursiveiterationalgorithm.h \
    humansilhouetteprobability.h \
    HumanPartsExtractorStorage/bodyproportionrecognizeralgorithm.h
