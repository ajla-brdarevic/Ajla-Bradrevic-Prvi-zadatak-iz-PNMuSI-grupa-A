#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Definišite funkciju koju želite riješiti
double f(double x) {
    return x * x * x - x - 2; // Primer funkcije
}

// Definišite prvu derivaciju funkcije
double df(double x) {
    return 3 * x * x - 1; // Derivacija f(x)
}

void newtonMethod() {
    double x0, tolerance;
    const int maxIterations = 100;

    // Unos poèetne aproksimacije i taènosti
    cout << "Unesite poèetnu aproksimaciju: ";
    cin >> x0;
    cout << "Unesite taènost (tolerance): ";
    cin >> tolerance;

    double x = x0;
    double error;

    cout << fixed << setprecision(6);
    cout << "Iteracija\tAproksimacija\tF(x)\t\tF'(x)\t\tGreška" << endl;

    for (int iteration = 0; iteration < maxIterations; iteration++) {
        double fx = f(x);
        double dfx = df(x);

        // Izraèunaj novu aproksimaciju
        if (dfx == 0) {
            cout << "Derivacija je nula, metoda ne može nastaviti." << endl;
            return;
        }

        double x_new = x - fx / dfx;
        error = fabs(x_new - x); // Greška je razlika izmeðu novih i starih aproksimacija

        // Ispis rezult ata
        cout << iteration + 1 << "\t\t" << x_new << "\t" << fx << "\t" << dfx << "\t" << error << endl;

        // Ažuriraj aproksimaciju
        x = x_new;

        // Prekinuti ako je greška manja od tolerancije
        if (error < tolerance) {
            break;
        }
    }
}