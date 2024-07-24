#
# Makefile Aufgabe6/lib
#
# Variablen für das Bibliotheks-Makefile
CXX = g++
CXXFLAGS = -g -W -Wall -Weffc++ -Wold-style-cast -std=$(STD) -fpic
CPPFLAGS = -I.
STD = c++11
SL = ar rvs
DL = -shared
RM = rm -f

TARGET = lib$(LIBNAME)
OBJECTS = \
    benotung.o \
    fachnote.o \
    fachnoten_liste.o
SOURCES = $(OBJECTS:.o=.cpp)
HEADERS = $(OBJECTS:.o=.h)
LIBNAME = aufgabe6
LIBTYPE = a

.PHONY: all clean

# Standardziel "all": Erstellt die statische Bibliothek
all: lib$(LIBNAME).$(LIBTYPE)

# Musterregel für das Übersetzen von Quelldateien
%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Ziel "clean": Löscht alle erzeugten Dateien
clean:
	$(RM) $(TARGET).a $(TARGET).so $(OBJECTS) depend

# Ziel "depend": Generiert Abhängigkeiten automatisch
depend: $(SOURCES) $(HEADERS)
	$(CXX) $(CPPFLAGS) -MM $(SOURCES) > $@

# Explizite Regel zum Erstellen der statischen Bibliothek
lib$(LIBNAME).a: $(OBJECTS)
	$(SL) -o $@ $^

# Explizite Regel zum Erstellen der dynamischen Bibliothek
lib$(LIBNAME).so: $(OBJECTS)
	$(CXX) $(DL) -o $@ $^
    
# Einbinden der Abhängigkeitsdatei
include depend
