#include <iostream>

struct ZAMEST {
    char prijmeni[30];
    char jmeno[30];
    int plat;
};

ZAMEST nactiZamestnance();
void tiskniZamestnance(ZAMEST zam);

int main() {

    return 0;
}

ZAMEST nactiZamestnance() {
    ZAMEST zam;

    std::cout << "Prijmeni: ";
    std::cin >> zam.prijmeni;

    std::cout << "Jmeno: ";
    std::cin >> zam.jmeno;

    std::cout << "Plat: ";
    std::cin >> zam.plat;

    return zam;
}