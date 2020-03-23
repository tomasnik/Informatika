#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file;
    file.open("cisla.txt");
    for (int i = 0; i < 30; i++)
    {
        file << i << endl;
    }
    file.close();
    return 0;
}
