#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Definišite funkciju koju želite riješiti
double funkcija(double x) {
    return x * x * x - x - 2; // Primer funkcije
}

// Proverava da li se uslovi za korišæenje metode regula falsi ispunjavaju
bool isValid(double a, double b) {
    return funkcija(a) * funkcija(b) < 0;
}

void regulaFalsi() {
    double a, b, tolerance;
    const int maxIterations = 150;

    // Unos granica intervala i taènosti
    cout << "Unesite granicu intervala a: ";
    cin >> a;
    cout << "Unesite granicu intervala b: ";
    cin >> b;
    cout << "Unesite taènost (tolerance): ";
    cin >> tolerance;

    // Proverava ispunjenost uslova
    if (!isValid(a, b)) {
        cout << "Funkcija ne menja znak u datom intervalu. Proverite granice." << endl;
        return;
    }

    double c; // Nova aproksimacija
    double error; // Greška
    int iteration = 0;

    cout << fixed << setprecision(6);
    cout << "Iteracija\tGranice (a, b)\tAproksimacija (c)\tF(c)\t\tGreška" << endl;

    do {
        // Izraèunaj novu aproksimaciju
        c = b - (funkcija(b) * (b - a)) / (funkcija(b) - funkcija(a));
        error = fabs(funkcija(c)); // Greška je apsolutna vrednost f(c)

        // Ispis rezultata
        cout << iteration + 1 << "\t\t" << a << "\t" << b << "\t" << c << "\t" << funkcija(c) << "\t" << error << endl;

        // Ažuriraj granice
        if (funkcija(c) * funkcija(a) < 0) {
            b = c; // c je u intervalu [a, b]
        }
        else {
            a = c; // c je u intervalu [c, b]
        }

        iteration++;
    } while (error > tolerance && iteration < maxIterations);

    // Ispis konaène aproksimacije
    cout << "Konaèna aproksimacija: " << c << endl;
    cout << "F(c): " << funkcija(c) << endl;
    cout << "Broj iteracija: " << iteration << endl;
}