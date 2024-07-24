#include "fachnote.h"

// Konstruktor der Klasse 'fachnote', der einen Fachnamen und eine Note annimmt.
fachnote::fachnote(const std::string& f, const benotung& n) : fach(f), note(n) {
    // Überprüft, ob der Fachname leer ist. Wenn ja, wird eine Ausnahme ausgelöst.
    if (f.empty()) {
        throw std::invalid_argument("Fachname darf nicht leer sein");
    }
}
