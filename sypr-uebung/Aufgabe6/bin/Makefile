#
# Makefile Aufgabe6/bin
#
# Variablen für das ausführbare Programm-Makefile
CXX = g++
CXXFLAGS = -g -W -Wall -Weffc++ -Wold-style-cast -std=$(STD) -fpic
CPPFLAGS = -I$(LIBDIR)
LDFLAGS = -L$(LIBDIR) -Wl,-rpath=$(LIBDIR)
STD = c++11
RM = rm -f

TARGET = notenspiegel
OBJECTS = \
    $(TARGET).o
SOURCES = $(OBJECTS:.o=.cpp)
HEADERS = \
    $(LIBDIR)fachnoten_liste.h \
    $(LIBDIR)benotung.h \
    $(LIBDIR)fachnote.h
LIBDIR = ../lib/
LIBNAME = aufgabe6
LIBTYPE = a

.PHONY: all clean

# Standardziel "all": Erstellt das ausführbare Programm
all: $(TARGET)

# Musterregel für das Übersetzen von Quelldateien
%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Ziel "clean": Löscht alle erzeugten Dateien
clean:
	$(RM) $(TARGET) $(OBJECTS) depend

# Ziel "depend": Generiert Abhängigkeiten automatisch
depend: $(SOURCES) $(HEADERS)
	$(CXX) $(CPPFLAGS) -MM $(SOURCES) > $@

# Linken des ausführbaren Programms mit der statischen Bibliothek
$(TARGET): $(OBJECTS) $(LIBDIR)lib$(LIBNAME).$(LIBTYPE)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o $@ $< -l$(LIBNAME)

# Einbinden der Abhängigkeitsdatei
include depend
