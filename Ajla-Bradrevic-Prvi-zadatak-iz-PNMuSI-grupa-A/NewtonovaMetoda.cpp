#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Definicija funkcije f(x) koja se rješava
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
    double x0, tolerancija;          // Poèetna aproksimacija i tolerancija greške
    const int maxIteracija = 100; // Maksimalan broj iteracija

    // Unos poèetne aproksimacije i tolerancije od strane korisnika
    cout << "Unesite poèetnu aproksimaciju: ";
    cin >> x0;
    cout << "Unesite taènost (tolerancija): ";
    cin >> tolerancija;

    double x = x0;  // Trenutna aproksimacija korijena
    double error;   // Trenutna greška

    // Formatiranje ispisa za bolju preglednost
    cout << fixed << setprecision(6);
    cout << "Iteracija\tAproksimacija\tF(x)\t\tF'(x)\t\tGreška" << endl;

    // Glavna petlja za iterativni postupak
    for (int iteracija = 0; iteracija < maxIteracija; iteracija++) {
        double fx = f(x);   // Vrijednost funkcije f(x) u trenutnoj aproksimaciji
        double dfx = df(x); // Vrijednost derivacije f'(x) u trenutnoj aproksimaciji

        // Provjera da li je derivacija nula (metoda ne može nastaviti)
        if (dfx == 0) {
            cout << "Derivacija je nula, metoda ne može nastaviti." << endl;
            return;
        }

        // Izraèunavanje nove aproksimacije koristeæi formulu Newtonove metode
        double x_new = x - fx / dfx;

        // Izraèunavanje greške kao apsolutne razlike izmeðu nove i stare aproksimacije
        error = fabs(x_new - x);

        // Ispis rezultata trenutne iteracije
        cout << iteracija + 1 << "\t\t" << x_new << "\t" << fx << "\t" << dfx << "\t" << error << endl;

        // Ažuriranje trenutne aproksimacije
        x = x_new;

        // Provjera zaustavnog kriterijuma: ako je greška manja od tolerancije, prekini iteracije
        if (error < tolerancija) {
            break;
        }
    }
}
