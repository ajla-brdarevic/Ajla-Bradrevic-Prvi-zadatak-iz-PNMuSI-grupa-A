#include <iostream>
using namespace std;

// Deklaracije funkcija za metode rje�avanja zadataka
void regulaFalsi();    // Metoda Regula Falsi
void newtonMetoda();   // Newtonova metoda

int main() {
    int izbor;            // Varijabla za pohranu izbora korisnika
    bool nastavak = true; // Kontrolna varijabla za petlju glavnog menija

    while (nastavak) {
        // Ispis glavnog menija
        cout << "Izaberite metodu:\n";
        cout << "1. Regula Falsi\n";          // Opcija za metodu Regula Falsi - 1. zadatak
        cout << "2. Newtonova metoda\n";     // Opcija za Newtonovu metodu - 2. zadatak
        void prostaIteracija();             // Metoda proste iteracije - 3. zadatak
        cout << "0. Izlaz\n";              // Opcija za izlazak iz programa
        cout << "Unesite va� izbor (0-3): ";
        cin >> izbor;

        // Obrada korisni�kog izbora 
        switch (izbor) {
        case 1:
            regulaFalsi();  // Poziv funkcije za Regula Falsi metodu
            break;
        case 2:
            newtonMetoda(); // Poziv funkcije za Newtonovu metodu
            break;
        case 3:
            prostaIteracija(); // Poziv funkcije za metodu proste iteracije
            break;
        case 0:
            nastavak = false; // Izlazak iz programa
            break;
        default:
            // Obrada neispravnog unosa
            cout << "Nepoznata opcija! Poku�ajte ponovo." << endl;
            break;
        }

        cout << endl;
    }

    return 0; 
}
