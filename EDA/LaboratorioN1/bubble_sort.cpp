#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <ctime>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

void bubble_sort(std::vector<int> &array);

int main()
{
    ifstream archivo("archivo_cien_mil.txt");
    std::vector<int> numeros;
    while (!archivo.eof()) {
        int tmp;
        archivo >> tmp;
        numeros.push_back(tmp);
    }
    //cout<<"Vector sin ordenar"<<endl;
    // for (const auto & i : numeros) {
    //     cout << i <<endl;
    // }

    cout<<"Ordenando..."<<endl;
    auto start = std::chrono::system_clock::now();
    bubble_sort(numeros);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration <float, std::milli> duration = end - start;
    cout<<"Duracion -- "<<duration.count()<<" ms"<<std::endl;

    //cout<<"Vector ordenado"<<endl;
    // for (const auto & i : numeros) {
    //     cout << i <<endl;
    // }

    return 0;
}

void rellenar_archivo()
{
    ofstream archivo;
    archivo.open("archivo.txt", ios::out);
    if(archivo.fail())
    {
        cout<<"Error"<<endl;
    }    
    else
    {
        srand( (unsigned)time(NULL));
        for(int i=1;i<=10;i++)
        {
            archivo<<rand()%10000<<endl;
        }
        archivo.close();
    }
}
void bubble_sort(std::vector<int> &array)
{
    for(int i=0;i<array.size();i++)
    {
        for(int j=0;j<array.size()-1;j++)
        {
            if(array[j]>array[j+1])
            {
                swap(array[j],array[j+1]);
            }
        }
    }
}