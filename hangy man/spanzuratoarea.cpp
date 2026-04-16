#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

void afiseazaStare(const string& ascuns, int greseli) {
    cout << "Cuvant: " << ascuns << endl;
    cout << "Greseli: " << greseli << " din 6" << endl;
}

char citesteLitera() {
    char litera;
    cout << "Introdu o litera: ";
    cin >> litera;
    return toupper(litera);
}

bool verificaLitera(const string& cuvant, string& ascuns, char litera) {
    bool gasit = false;
    for (size_t i = 0; i < cuvant.size(); i++) {
        if (cuvant[i] == litera) {
            ascuns[i] = litera;
            gasit = true;
        }
    }
    return gasit;
}

int main() {
    string cuvinte[] = {"PROGRAM", "INFORMATICA", "SPANZURATOAREA", "CARTE", "SCOALA", "ELEV"};
    int numarCuvinte = sizeof(cuvinte) / sizeof(cuvinte[0]);

    srand(static_cast<unsigned int>(time(NULL)));
    int index = rand() % numarCuvinte;
    string cuvant = cuvinte[index];
    string ascuns(cuvant.size(), '-');
    int greseli = 0;

    cout << "Bine ai venit la Spanzuratoarea!" << endl;
    cout << "Trebuie sa ghicesti un cuvant ales aleatoriu." << endl;

    while (greseli < 6 && ascuns != cuvant) {
        afiseazaStare(ascuns, greseli);
        char litera = citesteLitera();

        if (!verificaLitera(cuvant, ascuns, litera)) {
            cout << "Litera nu este in cuvant." << endl;
            greseli++;
        } else {
            cout << "Corect!" << endl;
        }
        cout << endl;
    }

    if (ascuns == cuvant) {
        cout << "Felicitari! Ai ghicit cuvantul: " << cuvant << endl;
        return 0;
    } else {
        cout << "Ai pierdut. Cuvantul era: " << cuvant << endl;
    }

    return 0;
}