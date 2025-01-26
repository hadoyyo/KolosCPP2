#include <iostream>
#include <memory>

class Element {
public:
    int data;
    std::unique_ptr<Element> next;
    Element* prev;

    // Konstruktor
    Element(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class Lista {
private:
    std::unique_ptr<Element> head; // Pierwszy element listy
    Element* tail; // WskaŸnik na ostatni element listy

public:
    Lista() : head(nullptr), tail(nullptr) {}

    // Dodawanie na pocz¹tek listy
    void dodajNaPoczatek(int data) {
        auto nowyElement = std::make_unique<Element>(data);
        if (!head) {
            head = std::move(nowyElement);
            tail = head.get();
        } else {
            nowyElement->next = std::move(head);
            nowyElement->next->prev = nowyElement.get();
            head = std::move(nowyElement);
        }
    }

    // Dodawanie na koniec listy
    void dodajNaKoniec(int data) {
        auto nowyElement = std::make_unique<Element>(data);
        if (!head) {
            head = std::move(nowyElement);
            tail = head.get();
        } else {
            nowyElement->prev = tail;
            tail->next = std::move(nowyElement);
            tail = tail->next.get();
        }
    }

    // Usuwanie z pocz¹tku listy
    void usunZPoczatku() {
        if (head) {
            if (head.get() == tail) {
                head.reset(); // Usuwa jedyny element
                tail = nullptr;
            } else {
                head = std::move(head->next);
                head->prev = nullptr;
            }
        } else {
            std::cout << "Lista jest pusta!" << std::endl;
        }
    }

    // Usuwanie z koñca listy
    void usunZKoniec() {
        if (tail) {
            if (head.get() == tail) {
                head.reset(); // Usuwa jedyny element
                tail = nullptr;
            } else {
                tail = tail->prev;
                if (tail) {
                    tail->next.reset();
                }
            }
        } else {
            std::cout << "Lista jest pusta!" << std::endl;
        }
    }

    // Wyœwietlanie zawartoœci listy
    void wyswietl() const {
        if (!head) {
            std::cout << "Lista jest pusta!" << std::endl;
            return;
        }
        Element* current = head.get();
        while (current) {
            std::cout << current->data << " ";
            current = current->next.get();
        }
        std::cout << std::endl;
    }

    // Sprawdzenie, czy lista jest pusta
    bool czyPusta() const {
        return head == nullptr;
    }

     void usunPoIndeksie(int index) {
        if (!head) {
            std::cout << "Lista jest pusta!" << std::endl;
            return;
        }

        Element* current = head.get();
        int currentIndex = 0;

        while (current && currentIndex < index) {
            current = current->next.get();
            currentIndex++;
        }

        if (!current) {
            std::cout << "Element o podanym indeksie nie istnieje!" << std::endl;
            return;
        }

        if (current == head.get()) {
            usunZPoczatku();
        } else if (current == tail) {
            usunZKoniec();
        } else {
            current->prev->next = std::move(current->next);
            if (current->prev->next) {
                current->prev->next->prev = current->prev;
            }
        }
    }
};

int main() {
    Lista lista;

    // Testowanie operacji na liœcie
    lista.dodajNaPoczatek(10);
    lista.dodajNaPoczatek(20);
    lista.dodajNaKoniec(5);
    lista.dodajNaKoniec(1);
    lista.wyswietl(); // 20 10 5 1

    lista.usunPoIndeksie(1);
    lista.wyswietl(); // 20 5 1

    lista.usunPoIndeksie(0);
    lista.wyswietl(); // 5 1

    lista.usunPoIndeksie(10); // Element o podanym indeksie nie istnieje!


    lista.usunZPoczatku();
    lista.usunZPoczatku();
    lista.wyswietl(); // Powinno wyœwietliæ: Lista jest pusta!

    std::cout << "Czy lista jest pusta? " << (lista.czyPusta() ? "Tak" : "Nie") << std::endl;

    return 0;
}
