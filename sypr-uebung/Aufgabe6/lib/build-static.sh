#!/bin/sh

# Kompilierungsoptionen festlegen
CXX=g++
CXXFLAGS="-g -c -W -Wall -Weffc++ -Wold-style-cast -std=c++11"

# Quellcodedateien
SOURCES="benotung.cpp fachnote.cpp fachnoten_liste.cpp"

# Objektdateien erzeugen
for SRC in $SOURCES; do
    OBJ=$(basename $SRC .cpp).o
    compile_command="$CXX $CXXFLAGS $SRC -o $OBJ"
    echo $compile_command   # Ausgabe des Kommandos auf der Konsole
    eval $compile_command   # Ausführen des Kommandos
    
    if [ $? -ne 0 ]; then   # Überprüfung des Rückgabewerts des Kommandos
        echo "build failed"
        exit 1
    fi
done

# Link-Befehl zum Erstellen der statischen Bibliothek
link_command="ar rvs libaufgabe6.a benotung.o fachnote.o fachnoten_liste.o"
echo $link_command          # Ausgabe des Link-Befehls auf der Konsole
eval $link_command          # Ausführen des Link-Befehls

# Überprüfung des Rückgabewerts des Link-Befehls
if [ $? -ne 0 ]; then
    echo "build failed"
    exit 1
fi

echo "build successful"     # Ausgabe einer Erfolgsmeldung
