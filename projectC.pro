QT +=widgets
QMAKE_CXXFLAGS += -std=c++14

SOURCES += \
    main.cpp \
    mafenetre.cpp \
    DecodeCesar.cpp \
    Donnees.cpp \
    DecodeRandom.cpp


HEADERS += \
    mafenetre.h \
    DecodeCesar.hpp \
    Donnees.hpp \
    DecodeRandom.hpp

DISTFILES += \
    frenchssaccent.dic \
    frenchssaccent.txt \
    projectC.pro.user
