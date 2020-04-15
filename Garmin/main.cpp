#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Open TCX file
    ifstream input("activity_318109582.tcx");
    // Read file
    string text;
    int total_calories = 0;
    while (getline(input, text))
    {
        // Find line beginning with <Calories>
        if (text.find("<Calories>") != string::npos)
        {
            // Strip tags
            for (int i = 0; i < text.length(); i++)
            {
                if (text[i] == '<')
                {
                    for (int j = i; j < text.length(); j++)
                    {
                        if (text[j] == '>')
                        {
                            text.erase(i, (j - i + 1));
                            break;
                        }
                    }
                }
            }
            // Add to total_calories
            total_calories += stoi(text);
        }
    }
    cout << "Celkovy pocet spalenych kalorii: " << total_calories << endl;
    cout << "Pro doplneni kalorii je potreba snist " << total_calories / 510.0 << " hamburgeru Big Mac";
    return 0;
}
