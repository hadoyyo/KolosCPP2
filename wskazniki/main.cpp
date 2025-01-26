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
    Element* tail; // Wska�nik na ostatni element listy

public:
    Lista() : head(nullptr), tail(nullptr) {}

    // Dodawanie na pocz�tek listy
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

    // Usuwanie z pocz�tku listy
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

    // Usuwanie z ko�ca listy
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

    // Wy�wietlanie zawarto�ci listy
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
};

int main() {
    Lista lista;

    // Testowanie operacji na li�cie
    lista.dodajNaPoczatek(10);
    lista.dodajNaPoczatek(20);
    lista.dodajNaKoniec(5);
    lista.dodajNaKoniec(1);
    lista.wyswietl(); // Powinno wy�wietli�: 20 10 5 1

    lista.usunZPoczatku();
    lista.wyswietl(); // Powinno wy�wietli�: 10 5 1

    lista.usunZKoniec();
    lista.wyswietl(); // Powinno wy�wietli�: 10 5

    lista.usunZPoczatku();
    lista.usunZPoczatku();
    lista.wyswietl(); // Powinno wy�wietli�: Lista jest pusta!

    std::cout << "Czy lista jest pusta? " << (lista.czyPusta() ? "Tak" : "Nie") << std::endl;

    return 0;
}
