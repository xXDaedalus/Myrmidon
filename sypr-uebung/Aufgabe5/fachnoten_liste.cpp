#include "fachnoten_liste.h"

// Konstruktor der Klasse 'fachnoten_liste', der einen Deleter als Funktionsobjekt annimmt
fachnoten_liste::fachnoten_liste(std::function<void(fachnote*)> del) 
    : head(nullptr), deleter(del) {}

// Destruktor der Klasse 'fachnoten_liste'
fachnoten_liste::~fachnoten_liste() {
    // Zeiger auf das aktuelle Node-Element setzen
    Node* current = head;
    // Solange das aktuelle Node-Element nicht null ist
    while (current != nullptr) {
        // Zeiger auf das nächste Node-Element speichern
        Node* next = current->next;
        // Verwenden Sie den Deleter, um das fachnote-Objekt zu löschen
        deleter(current->data);
        // Löschen Sie das aktuelle Node-Element
        delete current;
        // Zum nächsten Node-Element wechseln
        current = next;
    }
}

// Methode zum Einfügen eines neuen fachnote-Objekts in die Liste
void fachnoten_liste::insert(fachnote* f) {
    // Erstellen Sie ein neues Node-Element, das das fachnote-Objekt enthält
    Node* new_node = new Node(f);
    // Setzen Sie das nächste Element des neuen Node-Elements auf das aktuelle head-Element
    new_node->next = head;
    // Setzen Sie das head-Element auf das neue Node-Element
    head = new_node;
}
