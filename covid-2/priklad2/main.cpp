#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Get name of file
    cout << "Zadejte nazev souboru: ";
    string file_name;
    cin >> file_name;
    // Open file
    ifstream file;
    file.open(file_name);
    // Get text
    char text;
    if (file.is_open())
    {
        while ((text=file.get()) != EOF)
        {
            cout << text;
        }
        file.close();
    }
    else
    {
        cout << "Soubor se nepodarilo otevrit.";
    }
    return 0;
}
