#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Open input
    ifstream input("VYPOVED.TXT");
    ofstream output("SKUTECNE.TXT");
    // Read input
    string text;
    while (getline(input, text))
    {
        for (int i = 0; i < text.length(); i++)
        {
            // If 'ne' is on the beginning of a line
            if ((i == 0 && text[i] == 'n' && text[i + 1] == 'e'))
            {
                i += 2;
            }
            // If 'ne' is after a whitespace
            else if (text[i] == ' ' && text[i + 1] == 'n' && text[i + 2] == 'e')
            {
                output << text[i];
                i += 3;
            }
            // Write text
            output << text[i];
        }
        // Linebreak
        output << endl;
    }
    input.close();
    output.close();
    return 0;
}
