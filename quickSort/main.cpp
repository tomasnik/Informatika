#include <iostream>

using namespace std;

void quickSort(int l, int p, int pole[]) {
    int pivot, i, j, pom;
    i = l; j=p; pivot = pole[(l+p)/2];
    do {
        while(pole[i] < pivot) i++;
        while(pivot < pole[j]) j--;
        if(i<=j) {
            pom = pole[i];
            pole[i] = pole[j];
            pole[j] = pom;
            i++; j--;
        } 
    } while(i<=j);
    if(l<j) quickSort(j, j, pole);
    if(i<p) quickSort(i, p, pole);
}

int main(int argc, const char * argv[]) {
    int n;
    cout << "Zadej počet prvků:";
    cin >> n;
    int *policko;
    policko = new int[n];

    for(int i=0;i<=n;i++) policko[i]=rand()%100;
    for(int i=0;i<=n-1;i++) cout << policko[i] << " ";
    cout << endl << endl;

    int cas1 = time(NULL);
    quickSort(0, n-1, policko);
    int cas2 = time(NULL);

    for(int i=0;i<=n-1;i++) cout << policko[i]<< " ";
    cout << endl << endl;
    delete[] policko;
    cout << cas2-cas1;
    return 0;
}