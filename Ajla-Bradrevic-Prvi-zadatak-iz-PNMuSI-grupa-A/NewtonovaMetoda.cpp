#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Defini�ite funkciju koju �elite rije�iti
double f(double x) {
    return x * x * x - x - 2; // Primer funkcije
}

// Defini�ite prvu derivaciju funkcije
double df(double x) {
    return 3 * x * x - 1; // Derivacija f(x)
}

void newtonMethod() {
    double x0, tolerance;
    const int maxIterations = 100;

    // Unos po�etne aproksimacije i ta�nosti
    cout << "Unesite po�etnu aproksimaciju: ";
    cin >> x0;
    cout << "Unesite ta�nost (tolerance): ";
    cin >> tolerance;

    double x = x0;
    double error;

    cout << fixed << setprecision(6);
    cout << "Iteracija\tAproksimacija\tF(x)\t\tF'(x)\t\tGre�ka" << endl;

    for (int iteration = 0; iteration < maxIterations; iteration++) {
        double fx = f(x);
        double dfx = df(x);

        // Izra�unaj novu aproksimaciju
        if (dfx == 0) {
            cout << "Derivacija je nula, metoda ne mo�e nastaviti." << endl;
            return;
        }

        double x_new = x - fx / dfx;
        error = fabs(x_new - x); // Gre�ka je razlika izme�u novih i starih aproksimacija

        // Ispis rezult ata
        cout << iteration + 1 << "\t\t" << x_new << "\t" << fx << "\t" << dfx << "\t" << error << endl;

        // A�uriraj aproksimaciju
        x = x_new;

        // Prekinuti ako je gre�ka manja od tolerancije
        if (error < tolerance) {
            break;
        }
    }
}