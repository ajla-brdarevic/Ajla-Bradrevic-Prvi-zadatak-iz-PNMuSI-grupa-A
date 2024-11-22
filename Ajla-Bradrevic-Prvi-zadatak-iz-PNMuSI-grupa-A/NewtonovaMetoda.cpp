#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Definicija funkcije f(x) koja se rje�ava
double f(double x) {
    return x * x * x - x - 2; // Primjer funkcije: x^3 - x - 2
}

// Definicija prve derivacije funkcije f'(x)
// Ovo je derivacija funkcije definisane u f(x)
double df(double x) {
    return 3 * x * x - 1; // Derivacija funkcije: 3x^2 - 1
}

// Implementacija Newtonove metode
void newtonMetoda() {
    double x0, tolerancija;          // Po�etna aproksimacija i tolerancija gre�ke
    const int maxIteracija = 100; // Maksimalan broj iteracija

    // Unos po�etne aproksimacije i tolerancije od strane korisnika
    cout << "Unesite po�etnu aproksimaciju: ";
    cin >> x0;
    cout << "Unesite ta�nost (tolerancija): ";
    cin >> tolerancija;

    double x = x0;  // Trenutna aproksimacija korijena
    double error;   // Trenutna gre�ka

    // Formatiranje ispisa za bolju preglednost
    cout << fixed << setprecision(6);
    cout << "Iteracija\tAproksimacija\tF(x)\t\tF'(x)\t\tGre�ka" << endl;

    // Glavna petlja za iterativni postupak
    for (int iteracija = 0; iteracija < maxIteracija; iteracija++) {
        double fx = f(x);   // Vrijednost funkcije f(x) u trenutnoj aproksimaciji
        double dfx = df(x); // Vrijednost derivacije f'(x) u trenutnoj aproksimaciji

        // Provjera da li je derivacija nula (metoda ne mo�e nastaviti)
        if (dfx == 0) {
            cout << "Derivacija je nula, metoda ne mo�e nastaviti." << endl;
            return;
        }

        // Izra�unavanje nove aproksimacije koriste�i formulu Newtonove metode
        double x_new = x - fx / dfx;

        // Izra�unavanje gre�ke kao apsolutne razlike izme�u nove i stare aproksimacije
        error = fabs(x_new - x);

        // Ispis rezultata trenutne iteracije
        cout << iteracija + 1 << "\t\t" << x_new << "\t" << fx << "\t" << dfx << "\t" << error << endl;

        // A�uriranje trenutne aproksimacije
        x = x_new;

        // Provjera zaustavnog kriterijuma: ako je gre�ka manja od tolerancije, prekini iteracije
        if (error < tolerancija) {
            break;
        }
    }
}
