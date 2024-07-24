#ifndef FACHNOTEN_LISTE_H
#define FACHNOTEN_LISTE_H

#include "fachnote.h" // Bezieht die Definition der Klasse 'fachnote' ein
#include <functional> // Bezieht die Definition für std::function ein
#include <iterator> // Bezieht die Definitionen für Iterator-Tags ein

// Definition der Klasse 'fachnoten_liste'
class fachnoten_liste {
private:
    // Struktur, die ein Element der verketteten Liste repräsentiert
    struct Node {
        fachnote* data; // Zeiger auf die Fachnote
        Node* next; // Zeiger auf das nächste Listenelement
        explicit Node(fachnote* f) : data(f), next(nullptr) {} // Konstruktor für ein Node-Element
    };

    Node* head; // Zeiger auf den Kopf der Liste
    std::function<void(fachnote*)> deleter; // Funktionsobjekt zum Löschen von fachnote-Objekten

public:
    // Konstruktor, der einen Deleter als Funktionsobjekt annimmt
    explicit fachnoten_liste(std::function<void(fachnote*)>);
    // Destruktor der Klasse 'fachnoten_liste'
    ~fachnoten_liste();

    // Methode zum Einfügen eines neuen fachnote-Objekts in die Liste
    void insert(fachnote*);

    // Löschen Sie den Kopierkonstruktor und den Zuweisungsoperator
    fachnoten_liste(const fachnoten_liste&) = delete;
    fachnoten_liste& operator=(const fachnoten_liste&) = delete;

    // Definition der Iterator-Klasse für die 'fachnoten_liste'
    class iterator {
    public:
        using iterator_category = std::forward_iterator_tag; // Iterator-Kategorie
        using value_type = fachnote*; // Werttyp des Iterators
        using difference_type = std::ptrdiff_t; // Differenztyp des Iterators
        using pointer = fachnote**; // Zeigertyp des Iterators
        using reference = fachnote*&; // Referenztyp des Iterators

        // Konstruktor des Iterators, der einen Zeiger auf ein Node-Element annimmt
        explicit iterator(Node* ptr) : node_ptr(ptr) {}

        // Dereferenzierungsoperator zum Zugriff auf die Fachnote
        value_type operator*() const { return node_ptr->data; }
        
        // Präinkrementoperator zum Weiterschalten des Iterators
        iterator& operator++() {
            node_ptr = node_ptr->next;
            return *this;
        }
        
        // Ungleichheitsoperator zum Vergleichen von Iteratoren
        bool operator!=(const iterator& other) const { return node_ptr != other.node_ptr; }
    
    private:
        Node* node_ptr; // Zeiger auf das aktuelle Node-Element
    };

    // Methode zur Rückgabe eines Iterators auf den Anfang der Liste
    iterator begin() const { return iterator(head); }
    // Methode zur Rückgabe eines Iterators auf das Ende der Liste (null-Zeiger)
    iterator end() const { return iterator(nullptr); }
};

#endif // FACHNOTEN_LISTE_H
