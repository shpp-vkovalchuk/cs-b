QT += core
QT -= gui

CONFIG += c++11

TARGET = CalculatorProject
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    BusinessObject/shuntingyardalgorithm.cpp \
    utils.cpp \
    BusinessObject/binarytreealgorithm.cpp \
    CalculatorSubtypes/calculator.cpp \
    CalculatorSubtypes/scientificcalculator.cpp \
    treenodeitem.cpp \
    mathtokenaccessory.cpp \
    tokensgenerator.cpp \
    errorhandler.cpp \
    CalculatorSubtypes/standartcalculator.cpp

HEADERS += \
    BusinessObject/shuntingyardalgorithm.h \
    utils.h \
    BusinessObject/binarytreealgorithm.h \
    CalculatorSubtypes/calculator.h \
    CalculatorSubtypes/scientificcalculator.h \
    treenodeitem.h \
    mathtokenaccessory.h \
    tokensgenerator.h \
    errorhandler.h \
    CalculatorSubtypes/standartcalculator.h
