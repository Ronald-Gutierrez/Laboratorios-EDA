#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <ctime>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

void merge(std::vector<int> &array,int p, int q, int r)
{
    int i, j, k;

    int n1 = r - p + 1; //mitad de datos para n1
    int n2 = q - r;     //mitad de datos para n2

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[p + i];

    for (j = 0; j < n2; j++)
        R[j] = array[r + 1 + j];


    i = 0;
    j = 0;
    k = p;  //inicia k en la posicion izquierda del arreglo.

    while (i < n1 && j < n2)  // comparamos el arreglo izquierdo y derecho hasta que haya solo un elemento
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    //los arreglos no tocados se agregan al final tanto para el derecho e izquierdo
    while (i < n1)  
    {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<int> &array, int p, int r)
{
    if (p < r)
    {
        int q = (p + r)/2;
        merge_sort(array, p, q);
        merge_sort(array, q + 1, r);
        merge(array, p, r, q);
    }
}

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
    int n = numeros.size();
    cout<<"Ordenando..."<<endl;
    auto start = std::chrono::system_clock::now();
    merge_sort(numeros, 0, n-1);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration <float, std::milli> duration = end - start;
    cout<<"Duracion -- "<<duration.count()<<" ms"<<std::endl;

    // cout<<"Vector ordenado"<<endl;
    // for (const auto & i : numeros) {
    //     cout << i <<endl;
    // }

    return 0;
}