#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <ctime>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

void selectionSort(std::vector <int> &array);

int main()
{
    ifstream archivo("archivo_cien_mil.txt");
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
    selectionSort(numeros);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration <float, std::milli> duration = end - start;
    cout<<"Duracion -- "<<duration.count()<<" ms"<<std::endl;

    //cout<<"Vector ordenado"<<endl;
    // for (const auto & i : numeros) {
    //     cout << i <<endl;
    // }

    return 0;
}
void selectionSort(std::vector <int> &array)
{
    int min;
    for (int i = 0; i < array.size(); i++)
    {
        min = i;
        for (int j = i + 1; j < array.size(); j++)
            if (array[j] < array[min])  min = j;

        if (min != i)  swap(array[i], array[min]);

    }
}