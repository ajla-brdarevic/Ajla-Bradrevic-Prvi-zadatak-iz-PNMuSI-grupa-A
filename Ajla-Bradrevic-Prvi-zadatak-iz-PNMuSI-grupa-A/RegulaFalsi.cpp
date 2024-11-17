#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Definišite funkciju koju želite riješiti
double f(double x) {
    // Na primjer, rješavamo f(x) = x^3 - x - 2
    return x * x * x - x - 2;
}

// Proverava da li se uslovi za korišæenje metode regula falsi ispunjavaju
bool isValid(double a, double b) {
    return f(a) * f(b) < 0;
}

int main() {
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
        return 1;
    }

    double c; // Nova aproksimacija
    double error; // Greška
    int iteration = 0;

    cout << fixed << setprecision(6);
    cout << "Iteracija\tGranice (a, b)\tAproksimacija (c)\tF(c)\t\tGreška" << endl;

    do {
        // Izraèunaj novu aproksimaciju
        c = b - (f(b) * (b - a)) / (f(b) - f(a));
        error = fabs(f(c)); // Greška je apsolutna vrednost f(c)

        // Ispis rezultata
        cout << iteration + 1 << "\t\t" << a << "\t" << b << "\t" << c << "\t" << f(c) << "\t" << error << endl;

        // Ažuriraj granice
        if (f(c) * f(a) < 0) {
            b = c; // c je u intervalu [a, b]
        }
        else {
            a = c; // c je u intervalu [c, b]
        }

        iteration++;
    } while (error > tolerance && iteration < maxIterations);

    // Ispis konaène aproksimacije
    cout << "Konaèna aproksimacija: " << c << endl;
    cout << "F(c): " << f(c) << endl;
    cout << "Broj iteracija: " << iteration << endl;

    return 0;
}