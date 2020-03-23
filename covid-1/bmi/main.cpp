#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Get BMI
    float weight, height, bmi;
    cout << "Zadejte hmotnost (kg):";
    cin >> weight;
    cout << "Zadejte vysku (m):";
    cin >> height;
    bmi = weight / (height * height);

    // Get rating
    string rating;
    if (bmi < 18.5)
        rating = "podváha";
    else if (bmi > 25)
        rating = "nadváha";
    else
        rating = "ideální váha";

    // Write to file
    ofstream file;
    file.open("zprava-pro-lekare.txt");

    file << "Výška pacienta: " << height << " m" << endl;
    file << "Hmotnost pacienta: " << weight << " kg" << endl << endl;
    file << "Hodnota BMI: " << bmi << endl;
    file << "Hodnocení: " << rating << endl;

    file.close();
    return 0;
}