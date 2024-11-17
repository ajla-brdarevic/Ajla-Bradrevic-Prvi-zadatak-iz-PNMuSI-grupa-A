#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Definisanje funkcije Regula Falsi
double funkcija(double x) {
    return x * x * x - x - 2; // Primjer funkcije: x^3 - x - 2
}

// Provjera uslova za korištenje metode regula falsi
// Funkcija provjerava da li funkcija mijenja znak u granicama [a, b]
bool isValid(double a, double b) {
    return funkcija(a) * funkcija(b) < 0;
}

// Implementacija metode Regula Falsi
void regulaFalsi() {
    double a, b, tolerancija;             // Granice intervala i zadana taènost
    const int maxIteracija = 150;     // Maksimalan broj iteracija

    // Unos granica intervala i tolerancije od strane korisnika
    cout << "Unesite granicu intervala a: ";
    cin >> a;
    cout << "Unesite granicu intervala b: ";
    cin >> b;
    cout << "Unesite taènost (toleranciju): ";
    cin >> tolerancija;

    // Provjera da li su zadovoljeni uslovi za primjenu metode
    if (!isValid(a, b)) {
        cout << "Funkcija ne mijenja znak u datom intervalu. Proverite granice." << endl;
        return;
    }

    double c;          // Nova aproksimacija korijena
    double error;      // Trenutna greška
    int iteracija = 0; // Brojaè iteracija

    // Formatiranje ispisa za bolju preglednost
    cout << fixed << setprecision(6);
    cout << "Iteracija\tGranice (a, b)\tAproksimacija (c)\tF(c)\t\tGreška" << endl;

    do {
        // Izraèunavanje nove aproksimacije koristeæi formulu metode regula falsi
        c = b - (funkcija(b) * (b - a)) / (funkcija(b) - funkcija(a));
        error = fabs(funkcija(c)); // Greška je apsolutna vrijednost funkcije u c

        // Ispis rezultata trenutne iteracije
        cout << iteracija + 1 << "\t\t" << a << "\t" << b << "\t" << c << "\t"
            << funkcija(c) << "\t" << error << endl;

        // Ažuriranje granica intervala na osnovu znaka funkcije
        if (funkcija(c) * funkcija(a) < 0) {
            b = c; // Nova granica postaje c
        }
        else {
            a = c; // Nova granica postaje c
        }

        iteracija++; // Poveæanje broja iteracija
    } while (error > tolerancija && iteracija < maxIteracija);

    // Završni ispis kada je postignuta tražena taènost ili dostignut maksimalan broj iteracija
    cout << "Konaèna aproksimacija: " << c << endl;
    cout << "F(c): " << funkcija(c) << endl;
    cout << "Broj iteracija: " << iteracija << endl;
}
