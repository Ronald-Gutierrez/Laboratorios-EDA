#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <ctime>
#include <vector>
#include <string>
using namespace std;
void generar_archivo(int);

int main()
{
    int tamanio= 1000000;
    generar_archivo(tamanio);
    return 0;
}

void generar_archivo(int size)
{
    ofstream archivo;
    archivo.open("archivo_millon.txt", ios::out);
    if(archivo.fail())
    {
        cout<<"Error"<<endl;
    }    
    else
    {
        srand( (unsigned)time(NULL));
        for(int i=1;i<=size;i++)
        {
            archivo<<rand()%100000<<endl;
        }
        archivo.close();
    }
}
