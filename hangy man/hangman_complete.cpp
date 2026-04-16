#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cctype>
#include <cstdlib>

// Coduri ANSI pentru culori
const std::string RESET = "\033[0m";
const std::string GREEN = "\033[32m";
const std::string RED = "\033[31m";
const std::string YELLOW = "\033[33m";

// Funcție pentru curățarea ecranului
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Funcție pentru alegerea aleatorie a unui cuvânt
std::string chooseWord(const std::vector<std::string>& words) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, words.size() - 1);
    return words[dis(gen)];
}

// Funcție pentru desenarea spânzurătorii în funcție de greșeli
void drawHangman(int mistakes) {
    std::vector<std::string> stages = {
        "   +---+\n   |   |\n       |\n       |\n       |\n       |\n=========",
        "   +---+\n   |   |\n   O   |\n       |\n       |\n       |\n=========",
        "   +---+\n   |   |\n   O   |\n   |   |\n       |\n       |\n=========",
        "   +---+\n   |   |\n   O   |\n  /|   |\n       |\n       |\n=========",
        "   +---+\n   |   |\n   O   |\n  /|\\  |\n       |\n       |\n=========",
        "   +---+\n   |   |\n   O   |\n  /|\\  |\n  /    |\n       |\n=========",
        "   +---+\n   |   |\n   O   |\n  /|\\  |\n  / \\  |\n       |\n========="
    };
    std::cout << stages[mistakes] << std::endl;
}

// Funcție pentru afișarea interfeței
void displayInterface(const std::string& title, const std::string& display, const std::vector<char>& guessed, int chances, const std::string& message) {
    clearScreen();
    std::cout << "=====================================" << std::endl;
    std::cout << "         " << title << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << std::endl;

    drawHangman(6 - chances);
    std::cout << std::endl;

    std::cout << "Cuvant de ghicit: ";
    for (char c : display) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Litere folosite: ";
    for (char c : guessed) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << YELLOW << "Incercari ramase: " << chances << RESET << std::endl;
    std::cout << std::endl;

    if (!message.empty()) {
        std::cout << message << std::endl;
        std::cout << std::endl;
    }
}

// Funcție pentru citirea input-ului utilizatorului
char getInput() {
    char guess;
    std::cout << "Introdu o litera: ";
    std::cin >> guess;
    return std::tolower(guess);
}

// Funcție pentru verificarea dacă litera a fost deja folosită
bool isLetterUsed(char letter, const std::vector<char>& guessed) {
    return std::find(guessed.begin(), guessed.end(), letter) != guessed.end();
}

// Funcție pentru actualizarea display-ului cuvântului
void updateDisplay(std::string& display, const std::string& secret, char guess) {
    for (size_t i = 0; i < secret.size(); ++i) {
        if (secret[i] == guess) {
            display[i] = guess;
        }
    }
}

int main() {
    std::vector<std::string> words = {
        "programare", "calculator", "spanzuratoarea", "informatica", "algoritm",
        "variabila", "functie", "clasa", "obiect", "vector"
    };

    std::string secret = chooseWord(words);
    std::string display(secret.size(), '_');
    std::vector<char> guessed;
    int chances = 6;
    bool won = false;
    std::string message;

    displayInterface("SPANZURATOAREA", display, guessed, chances, "");

    while (chances > 0 && !won) {
        char guess = getInput();

        if (!std::isalpha(static_cast<unsigned char>(guess))) {
            message = RED + "Te rog introdu o litera valida." + RESET;
            displayInterface("SPANZURATOAREA", display, guessed, chances, message);
            continue;
        }

        if (isLetterUsed(guess, guessed)) {
            message = YELLOW + "Ai introdus deja litera '" + guess + "'. Incearca alta." + RESET;
            displayInterface("SPANZURATOAREA", display, guessed, chances, message);
            continue;
        }

        guessed.push_back(guess);

        bool found = false;
        for (char c : secret) {
            if (c == guess) {
                found = true;
                break;
            }
        }

        if (found) {
            updateDisplay(display, secret, guess);
            message = GREEN + "Corect! Litera '" + guess + "' este in cuvant." + RESET;
        } else {
            chances--;
            message = RED + "Gresit! Litera '" + guess + "' nu este in cuvant." + RESET;
        }

        if (display == secret) {
            won = true;
        }

        displayInterface("SPANZURATOAREA", display, guessed, chances, message);
    }

    if (won) {
        message = GREEN + "Felicitari! Ai castigat! Cuvantul era: " + secret + RESET;
    } else {
        message = RED + "Ai pierdut! Cuvantul era: " + secret + RESET;
    }

    displayInterface("SPANZURATOAREA", display, guessed, chances, message);

    return 0;
}