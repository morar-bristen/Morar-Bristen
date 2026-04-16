#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

void afiseazaStare(const string& ascuns, int greseli) {
    cout << "Cuvant: " << ascuns << endl; // afisez starea curenta a cuvantului
    cout << "Greseli: " << greseli << " din 6" << endl; // afisez numarul de greseli
}

char citesteLitera() {
    char litera; // variabila in care retin litera introdusa
    cout << "Introdu o litera: "; // cer litera de la utilizator
    cin >> litera; // citesc litera
    return toupper(litera); // convertesc la majuscula si o returnez
}

bool verificaLitera(const string& cuvant, string& ascuns, char litera) {
    bool gasit = false; // presupun ca litera nu exista in cuvant
    for (size_t i = 0; i < cuvant.size(); i++) { // parcurg fiecare litera din cuvant
        if (cuvant[i] == litera) { // daca litera corespunde
            ascuns[i] = litera; // actualizez cuvantul ascuns
            gasit = true; // marcheaza gasirea literei
        }
    }
    return gasit; // returnez daca am gasit litera
}

int main() {
    char optiune = 'N'; // optiunea pentru a repeta jocul

    do {
        string cuvinte[] = {"PROGRAM", "INFORMATICA", "SPANZURATOAREA", "CARTE", "SCOALA", "ELEV"}; // lista de cuvinte disponibile
        int numarCuvinte = sizeof(cuvinte) / sizeof(cuvinte[0]); // numarul de cuvinte din lista

        srand(static_cast<unsigned int>(time(NULL))); // initializez generatorul pentru numere aleatoare
        int index = rand() % numarCuvinte; // aleg un index aleator din liste
        string cuvant = cuvinte[index]; // aleg cuvantul secret
        string ascuns(cuvant.size(), '-'); // construiesc cuvantul ascuns cu '-'
        int greseli = 0; // initializez contorul de greseli

        cout << "Bine ai venit la Spanzuratoarea!" << endl; // mesaj de bun venit
        cout << "Trebuie sa ghicesti un cuvant ales aleatoriu." << endl; // explicarea jocului
        cout << endl; // linie goala pentru separatie

        while (greseli < 6 && ascuns != cuvant) { // jocul continua pana la 6 greseli sau pana se ghiceste cuvantul
            afiseazaStare(ascuns, greseli); // afisez starea curenta a jocului
            char litera = citesteLitera(); // citesc litera de la utilizator

            if (!verificaLitera(cuvant, ascuns, litera)) { // verific daca litera nu se gaseste in cuvant
                cout << "Litera nu este in cuvant." << endl; // afisez mesaj de eroare
                greseli++; // cresc numarul de greseli
            } else {
                cout << "Corect!" << endl; // afisez mesaj de succes
            }
            cout << endl; // linie goala pentru separatie
        }

        if (ascuns == cuvant) { // daca jucatorul a ghicit cuvantul
            cout << "Felicitari! Ai ghicit cuvantul: " << cuvant << endl; // afisez mesaj de castig
        } else {
            cout << "Ai pierdut. Cuvantul era: " << cuvant << endl; // afisez mesajul de pierdere si cuvantul corect
        }

        cout << endl; // linie goala inainte de optiune
        cout << "Vrei sa joci din nou? (D/N): "; // intreb daca jucatorul doreste sa repete jocul
        cin >> optiune; // citesc optiunea utilizatorului
        optiune = toupper(optiune); // convertesc optiunea la majuscula
        cout << endl; // linie goala pentru separatie
    } while (optiune == 'D'); // daca optiunea este D, jocul se reia

    return 0; // termin programul
}
