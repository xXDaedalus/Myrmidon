#include "benotung.h"
#include <stdexcept> // Enthält die Definitionen für Ausnahmen wie std::invalid_argument
#include <iostream>  // Enthält die Definitionen für Ein- und Ausgabe

namespace{
    // Methode zur Validierung der Note. Wenn die Note ungültig ist, wird eine Ausnahme ausgelöst.
    void validiere_note(int n);
}
// Initialisierung der statischen Konstanten für die besten und schlechtesten Noten.
const benotung benotung::beste = benotung(10);
const benotung benotung::schlechteste = benotung(50);

// Konstruktor der Klasse 'benotung', der eine Note als Parameter annimmt.
benotung::benotung(int n) : note(n) {
    validiere_note(n); // Überprüft, ob die Note gültig ist.
}
namespace{
    // Methode zur Validierung der Note. Wenn die Note ungültig ist, wird eine Ausnahme ausgelöst.
    void validiere_note(int n) {
        // Array mit gültigen Notenwerten.
        static const int gueltige_noten[] = {10, 13, 17, 20, 23, 27, 30, 33, 37, 40, 50};
        // Schleife durch das Array der gültigen Noten.
        for (int gueltige_note : gueltige_noten) {
            // Wenn die Note gültig ist, kehre zurück.
            if (n == gueltige_note) {
                return;
            }
        }
        // Wenn die Note ungültig ist, werfe eine Ausnahme.
        throw std::invalid_argument("unzulaessige Note " + std::to_string(n));
    }
}
// Methode zur Rückgabe des int-Werts der Note.
int benotung::int_value() const {
    return note;
}

// Methode, die überprüft, ob die Note bestanden ist. Noten bis 40 sind bestanden.
bool benotung::ist_bestanden() const {
    return note <= 40;
}

// Vergleichsoperator, der zwei benotung-Objekte vergleicht.
bool operator==(benotung a, benotung b) {
    return a.note == b.note;
}
