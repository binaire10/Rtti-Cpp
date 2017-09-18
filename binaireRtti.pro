QMAKE_CXXFLAGS += -pedantic -Wall -Wextra -Wold-style-cast -Woverloaded-virtual -Wfloat-equal -Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align -Wconversion -Wshadow -Weffc++
QMAKE_CXXFLAGS += -Wredundant-decls -Wdouble-promotion -Winit-self -Wswitch-default -Wswitch-enum -Wundef -Wlogical-op -Winline

CONFIG += c++11
#QMAKE_CXXFLAGS_GNUCXX14 = -std=c++1z

DEFINES += undefined=0
DEFINES += BUILD_NAME=\\\"$$TARGET\\\"
unix: LIBS += -static-libgcc -static-libstdc++

include($$PWD/depend/MetaString/include.pri)
include($$PWD/depend/TraitsTemplate/include.pri)

HEADERS_PP += \
    ClassInfoInstance.tpp \
    trait_ClassInfoInstance.inl \
    TypeInfoInstance.tpp \
    trait_TypeInfoInstance.inl \
    trait_FunctionMemberInfoInstance.inl \
    FunctionMemberInfoInstance.tpp \
    arrayOf.tpp \
    hash_ClassInfo_t.inl \
    hash_pair.tpp \
    hash_TypeInfo_t.inl

HEADERS += \
    vTypeInfo.h \
    vFunctionInfo.h \
    vMemberInfo.h \
    vAttributeMemberInfo.h \
    vClassInfo.h \
    trait_type.h \
    vTypeLogger.h \
    TypeInfo.h \
    ClassInfo.h \
    TypeInfoInstance.h \
    TypeInfo_t.h \
    ClassInfo_t.h \
    ClassInfoInstance.h \
    Parent.h \
    FunctionMemberInfo_t.h \
    ClassMember.hpp \
    ClassInfoInstance.hpp \
    TypeInfoInstance.hpp \
    FunctionMemberInfoInstance.h \
    FunctionMemberInfoInstance.hpp \
    arrayOf.h \
    arrayOf.hpp \
    hash_ClassInfo_t.hpp \
    hash_ClassInfo_t.h \
    hash_pair.h \
    hash_pair.hpp \
    FunctionMemberInfo_t.hpp \
    hash_TypeInfo_t.h \
    hash_TypeInfo_t.hpp \
    FunctionMember.h \
    ElementName.h \
    NameType.h \
    Conversion.h

HEADERS += $$HEADERS_PP

SOURCES += \
    main.cpp \
    vTypeLogger.cpp \
    TypeInfo_t.cpp \
    ClassInfo_t.cpp \
    FunctionMemberInfo_t.cpp
