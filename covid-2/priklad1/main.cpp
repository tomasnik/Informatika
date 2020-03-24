#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int main() {
    // Reading file
    ifstream file;
    file.open("hodnoty.txt");
    // Get values
    int num, sum = 0, count = 0, min = INT_MAX, max = 0;
    while (file >> num)
    {
        sum += num;
        count++;
        if (num > max)
        {
            max = num;
        }
        else if (num < min)
        {
            min = num;
        }
    }
    float avg = (float) sum / (float) count;
    // Printing values
    cout << "Pocet hodnot: " << count << endl;
    cout << "Minimalni hodnota: " << min << endl;
    cout << "Maximalni hodnota: " << max << endl;
    cout << "Prumer: " << avg << endl;
    return 0;
}
