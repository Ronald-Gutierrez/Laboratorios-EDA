#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <ctime>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

void heapsort(std::vector<int> &array);
void heapify(std::vector<int> &array, int N, int raiz);
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
    heapsort(numeros);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration <float, std::milli> duration = end - start;
    cout<<"Duracion -- "<<duration.count()<<" ms"<<std::endl;

    //cout<<"Vector ordenado"<<endl;
    // for (const auto & i : numeros) {
    //     cout << i <<endl;
    // }

    return 0;
}
void heapsort(std::vector<int> &array)
{
    int n = array.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}
void heapify(std::vector<int> &array, int N, int raiz)
{
    int mayor = raiz;
    int izq = 2 * raiz + 1;
    int der = 2 * raiz + 2;
    if (izq < N && array[izq] > array[mayor])  mayor = izq;
    if (der < N && array[der] > array[mayor])  mayor = der;

    if (mayor != raiz) {
        swap(array[raiz], array[mayor]);
        heapify(array, N, mayor);
    }
}