#include <iostream>

struct ZAMEST {
    char prijmeni[30];
    char jmeno[30];
    int plat;
};

class SeznamZamestnancu {
public:
    SeznamZamestnancu();

    void nactiZamestnance();

    void tiskniZamestnance();

private:
    ZAMEST zamestnanci[50];
    int index{};
};

SeznamZamestnancu::SeznamZamestnancu() {
    index = 0;
}

void SeznamZamestnancu::nactiZamestnance() {
    std::cout << "Prijmeni: ";
    std::cin >> zamestnanci[index].prijmeni;

    std::cout << "Jmeno: ";
    std::cin >> zamestnanci[index].jmeno;

    std::cout << "Plat: ";
    std::cin >> zamestnanci[index].plat;

    index++;
}

void SeznamZamestnancu::tiskniZamestnance() {
    for (int i = 0; i < index; i++) {
        std::cout << "Prijmeni: " << zamestnanci[i].prijmeni << std::endl;
        std::cout << "Jmeno: " << zamestnanci[i].jmeno << std::endl;
        std::cout << "Plat: " << zamestnanci[i].plat << std::endl << std::endl;
    }
}

int main() {
    SeznamZamestnancu seznamZamestnancu;
}