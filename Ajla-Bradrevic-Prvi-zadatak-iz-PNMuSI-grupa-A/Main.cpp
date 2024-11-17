#include <iostream>
using namespace std;

// Deklaracije funkcija za metode rješavanja zadataka
void regulaFalsi();    // Metoda Regula Falsi
void newtonMetoda();   // Newtonova metoda

int main() {
    int izbor;           // Varijabla za pohranu izbora korisnika
    bool nastavak = true; // Kontrolna varijabla za petlju glavnog menija

    while (nastavak) {
        // Ispis glavnog menija
        cout << "Izaberite metodu:\n";
        cout << "1. Regula Falsi\n";        // Opcija za metodu Regula Falsi - 1. zadatak
        cout << "2. Newtonova metoda\n";   // Opcija za Newtonovu metodu - 2. zadatak
        cout << "0. Izlaz\n";              // Opcija za izlazak iz programa
        cout << "Unesite vaš izbor (0-2): ";
        cin >> izbor;

        // Obrada korisnièkog izbora 
        switch (izbor) {
        case 1:
            regulaFalsi();  // Poziv funkcije za Regula Falsi metodu
            break;
        case 2:
            newtonMetoda(); // Poziv funkcije za Newtonovu metodu
            break;
        case 0:
            nastavak = false; // Izlazak iz programa
            break;
        default:
            // Obrada neispravnog unosa
            cout << "Nepoznata opcija! Pokušajte ponovo." << endl;
            break;
        }

        cout << endl;
    }

    return 0; 
}
