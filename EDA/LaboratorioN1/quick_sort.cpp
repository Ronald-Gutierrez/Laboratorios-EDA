#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <ctime>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

int particion(vector<int> & array,int inicio, int fin){
    int pivote = array[inicio];
    int i = inicio + 1;
    for(int j = i; j <= fin; j++){
        if(array[j] < pivote){
            swap(array[i],array[j]);
            i++;
        }
    }
    swap(array[inicio],array[i-1]);
    return i-1;
}

void quickSort(vector<int>&array, int inicio, int fin){
    if(inicio < fin){
        int pivote = particion(array,inicio,fin);
        quickSort(array,inicio,pivote-1);
        quickSort(array,pivote+1,fin);
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
    quickSort(numeros, 0, n-1);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration <float, std::milli> duration = end - start;
    cout<<"Duracion -- "<<duration.count()<<" ms"<<std::endl;

    // cout<<"Vector ordenado"<<endl;
    // for (const auto & i : numeros) {
    //     cout << i <<endl;
    // }

    return 0;
}