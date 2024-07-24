#ifndef FACHNOTE_H
#define FACHNOTE_H

#include "benotung.h" // Inkludiert die Definition der Klasse 'benotung'
#include <string> // Inkludiert die Definition der Klasse 'std::string'
#include <stdexcept> // Inkludiert die Definitionen für Ausnahmen wie std::invalid_argument

// Definition der Klasse 'fachnote'
class fachnote {
public:
    // Öffentliche konstante Mitglieder, die den Fachnamen und die Note repräsentieren
    const std::string fach;
    const benotung note;

    // Konstruktor, der einen Fachnamen und eine Note annimmt
    fachnote(const std::string&, const benotung&);

    // Löschen Sie den Kopierkonstruktor und den Zuweisungsoperator
    fachnote(const fachnote&) = delete;
    fachnote& operator=(const fachnote&) = delete;
};

#endif // FACHNOTE_H
