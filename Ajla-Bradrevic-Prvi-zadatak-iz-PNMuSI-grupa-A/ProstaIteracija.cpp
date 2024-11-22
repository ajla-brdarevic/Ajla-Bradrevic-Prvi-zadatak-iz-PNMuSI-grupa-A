#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Funkcija g(x)
// Defini�e se prema zadatom problemu. Ovdje je primjer: g(x) = x^3 - x - 2
double g(double x) {
    // Ra�una vrijednost funkcije g(x) za zadani x
    return pow(x, 3) - x - 2;
}

// Funkcija za izra�unavanje nove aproksimacije
// Preure�ivanje g(x) u obliku x = h(x), ovdje: x = (x + 2)^(1/3)
double novaAproksimacija(double x) {
    // Ra�una novu aproksimaciju prema preure�enoj funkciji
    return pow(x + 2, 1.0 / 3.0);
}

// Implementacija metode proste iteracije
void prostaIteracija() {
    double x0, ta�nost;           // Po�etna aproksimacija i tolerancija gre�ke
    const int maxIteracija = 150; // Maksimalan broj iteracija

    // Unos po�etne aproksimacije i ta�nosti od strane korisnika
    cout << "Unesite po�etnu aproksimaciju (x0): ";
    cin >> x0;
    cout << "Unesite ta�nost: ";
    cin >> ta�nost;

    double x = x0;              // Trenutna aproksimacija
    double trenutnaGre�ka = 0;  // Trenutna gre�ka

    // Zaglavlje ispisa rezultata
    cout << fixed << setprecision(6);
    cout << "Iteracija\tAproksimacija\tg(x)\t\tGre�ka" << endl;

    // Petlja koja iterativno ra�una novu aproksimaciju
    for (int i = 1; i <= maxIteracija; ++i) {
        // Izra�unavanje nove aproksimacije
        double novaX = novaAproksimacija(x);

        // Ra�unanje vrijednosti funkcije g(x) za trenutnu aproksimaciju
        double g_x = g(novaX);

        // Ra�unanje trenutne gre�ke (apsolutna vrijednost g(x))
        trenutnaGre�ka = fabs(g_x);

        // Ispis trenutnih rezultata
        cout << i << "\t\t" << novaX << "\t\t" << g_x << "\t\t" << trenutnaGre�ka << endl;

        // Provjera kriterija zaustavljanja (ta�nost)
        if (trenutnaGre�ka < ta�nost) {
            cout << "Kriterij ta�nosti zadovoljen nakon " << i << " iteracija." << endl;
            return;
        }

        // A�uriranje trenutne aproksimacije
        x = novaX;
    }

    // Ako se dostigne maksimalan broj iteracija
    cout << "Dostignut maksimalan broj iteracija (" << maxIteracija << ")." << endl;
    cout << "Posljednja aproksimacija: " << x << endl;
    cout << "Trenutna gre�ka: " << trenutnaGre�ka << endl;
}
