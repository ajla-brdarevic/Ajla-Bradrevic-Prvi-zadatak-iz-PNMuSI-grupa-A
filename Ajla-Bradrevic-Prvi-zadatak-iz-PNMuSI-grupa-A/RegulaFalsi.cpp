#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Defini�ite funkciju koju �elite rije�iti
double f(double x) {
    // Na primjer, rje�avamo f(x) = x^3 - x - 2
    return x * x * x - x - 2;
}

// Proverava da li se uslovi za kori��enje metode regula falsi ispunjavaju
bool isValid(double a, double b) {
    return f(a) * f(b) < 0;
}

int main() {
    double a, b, tolerance;
    const int maxIterations = 150;

    // Unos granica intervala i ta�nosti
    cout << "Unesite granicu intervala a: ";
    cin >> a;
    cout << "Unesite granicu intervala b: ";
    cin >> b;
    cout << "Unesite ta�nost (tolerance): ";
    cin >> tolerance;

    // Proverava ispunjenost uslova
    if (!isValid(a, b)) {
        cout << "Funkcija ne menja znak u datom intervalu. Proverite granice." << endl;
        return 1;
    }

    double c; // Nova aproksimacija
    double error; // Gre�ka
    int iteration = 0;

    cout << fixed << setprecision(6);
    cout << "Iteracija\tGranice (a, b)\tAproksimacija (c)\tF(c)\t\tGre�ka" << endl;

    do {
        // Izra�unaj novu aproksimaciju
        c = b - (f(b) * (b - a)) / (f(b) - f(a));
        error = fabs(f(c)); // Gre�ka je apsolutna vrednost f(c)

        // Ispis rezultata
        cout << iteration + 1 << "\t\t" << a << "\t" << b << "\t" << c << "\t" << f(c) << "\t" << error << endl;

        // A�uriraj granice
        if (f(c) * f(a) < 0) {
            b = c; // c je u intervalu [a, b]
        }
        else {
            a = c; // c je u intervalu [c, b]
        }

        iteration++;
    } while (error > tolerance && iteration < maxIterations);

    // Ispis kona�ne aproksimacije
    cout << "Kona�na aproksimacija: " << c << endl;
    cout << "F(c): " << f(c) << endl;
    cout << "Broj iteracija: " << iteration << endl;

    return 0;
}