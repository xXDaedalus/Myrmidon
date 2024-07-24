#ifndef BENOTUNG_H
#define BENOTUNG_H

// Definition der Klasse 'benotung'
class benotung {
public:
    // Konstruktor, der explizit eine int-Note annimmt
    explicit benotung(int);
    
    // Statische konstante Mitglieder, die die besten und schlechtesten Noten darstellen
    static const benotung beste;
    static const benotung schlechteste;

    // Methode zur Rückgabe des int-Werts der Note
    int int_value() const;
    
    // Methode zur Überprüfung, ob die Note bestanden ist
    bool ist_bestanden() const;

    // Freundschaftsdeklaration für den Vergleichsoperator
    friend bool operator==(benotung, benotung);

private:
    int note; // Mitgliedsvariable zur Speicherung der Note
};

#endif // BENOTUNG_H
