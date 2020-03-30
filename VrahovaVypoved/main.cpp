#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Open files
    ifstream source("VYPOVED.TXT");
    ofstream file("SKUTECNE.TXT");

    // Read source
    char text[999];
    if (source.is_open())
    {
       for (int i = 0; ((text[i] = source.get()) != EOF); i++);
    }
    // Write to file
    for (int i = 0; text[i] != EOF; i++)
    {
        if (text[i] == ' ' && text[i + 1] == 'n' && text[i + 2] == 'e')
        {
            file << text[i];
            i += 3;
        }
        file << text[i];
    }
    source.close();
    file.close();
    return 0;
}
