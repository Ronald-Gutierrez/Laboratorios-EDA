#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <ctime>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

void insertionSort(std::vector<int> &lista);

int main()
{
    ifstream archivo("archivo_millon.txt");
    std::vector<int> numeros;
    while (!archivo.eof()) {
        int tmp;
        archivo >> tmp;
        numeros.push_back(tmp);
    }
    //Cout<<"Vector sin ordenar"<<endl;
    // for (const auto & i : numeros) {
    //     cout << i <<endl;
    // }

    cout<<"Ordenando..."<<endl;
    auto start = std::chrono::system_clock::now();
    insertionSort(numeros);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration <float, std::milli> duration = end - start;
    cout<<"Duracion -- "<<duration.count()<<" ms"<<std::endl;

    //cout<<"Vector ordenado"<<endl;
    // for (const auto & i : numeros) {
    //     cout << i <<endl;
    // }

    return 0;
}
void insertionSort(vector<int> &lista)
{
    for (int i = 1; i < lista.size(); i++) 
    {
        int key = lista[i];
        int j = i - 1;
        while (j >= 0 && lista[j] > key) 
        {
            lista[j + 1] = lista[j];
            j--;
        }
        lista[j + 1] = key;
    }
}
