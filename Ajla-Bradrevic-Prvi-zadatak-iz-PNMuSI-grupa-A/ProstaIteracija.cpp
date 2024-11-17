#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Funkcija g(x)
// Definiše se prema zadatom problemu. Ovdje je primjer: g(x) = x^3 - x - 2
double g(double x) {
    // Raèuna vrijednost funkcije g(x) za zadani x
    return pow(x, 3) - x - 2;
}

// Funkcija za izraèunavanje nove aproksimacije
// Preureðivanje g(x) u obliku x = h(x), ovdje: x = (x + 2)^(1/3)
double novaAproksimacija(double x) {
    // Raèuna novu aproksimaciju prema preureðenoj funkciji
    return pow(x + 2, 1.0 / 3.0);
}

// Implementacija metode proste iteracije
void prostaIteracija() {
    double x0, taènost;           // Poèetna aproksimacija i tolerancija greške
    const int maxIteracija = 150; // Maksimalan broj iteracija

    // Unos poèetne aproksimacije i taènosti od strane korisnika
    cout << "Unesite poèetnu aproksimaciju (x0): ";
    cin >> x0;
    cout << "Unesite taènost: ";
    cin >> taènost;

    double x = x0;              // Trenutna aproksimacija
    double trenutnaGreška = 0;  // Trenutna greška

    // Zaglavlje ispisa rezultata
    cout << fixed << setprecision(6);
    cout << "Iteracija\tAproksimacija\tg(x)\t\tGreška" << endl;

    // Petlja koja iterativno raèuna novu aproksimaciju
    for (int i = 1; i <= maxIteracija; ++i) {
        // Izraèunavanje nove aproksimacije
        double novaX = novaAproksimacija(x);

        // Raèunanje vrijednosti funkcije g(x) za trenutnu aproksimaciju
        double g_x = g(novaX);

        // Raèunanje trenutne greške (apsolutna vrijednost g(x))
        trenutnaGreška = fabs(g_x);

        // Ispis trenutnih rezultata
        cout << i << "\t\t" << novaX << "\t\t" << g_x << "\t\t" << trenutnaGreška << endl;

        // Provjera kriterija zaustavljanja (taènost)
        if (trenutnaGreška < taènost) {
            cout << "Kriterij taènosti zadovoljen nakon " << i << " iteracija." << endl;
            return;
        }

        // Ažuriranje trenutne aproksimacije
        x = novaX;
    }

    // Ako se dostigne maksimalan broj iteracija
    cout << "Dostignut maksimalan broj iteracija (" << maxIteracija << ")." << endl;
    cout << "Posljednja aproksimacija: " << x << endl;
    cout << "Trenutna greška: " << trenutnaGreška << endl;
}
