#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <ctime>
#include <vector>
#include <string>
#include <chrono>
using namespace std;


void shellSort(std::vector <int> &array);

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
    shellSort(numeros);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration <float, std::milli> duration = end - start;
    cout<<"Duracion -- "<<duration.count()<<" ms"<<std::endl;

    // cout<<"Vector ordenado"<<endl;
    // for (const auto & i : numeros) {
    //     cout << i <<endl;
    // }

    return 0;
}

void shellSort(std::vector <int> &array) 
{
    int tam = array.size();
    for (int k = tam / 2; k > 0; k /= 2) {
        for (int i = k; i < tam; i++) {
            int temp = array[i];
            for (int j = i; j >= k; j -= k) {
                if(temp < array[j-k])
                    swap(array[j] ,array[j - k]);
                else break;
            }
        }
    }
}
