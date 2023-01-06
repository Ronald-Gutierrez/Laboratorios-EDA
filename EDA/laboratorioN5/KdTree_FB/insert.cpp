#include <bits/stdc++.h>
#include "kd_tree_FB.cpp"
#include "csv.h"
#include <chrono>
#include <ctime>

using namespace std;

const int ms = 1000000;

void insertionBruteforce(){
    ofstream outInsert1;
    outInsert1.open("./docs/outInsertFB.txt");
    int max_cant = 11;

    int cant[11] = {100, 500, 1000, 5000, 10000, 20000, 100000, 200000, 350000, 500000, 1000000};
    vector<string> nameFiles(max_cant);
    for(int i=0; i<max_cant; i++) nameFiles[i] = "data/test" + to_string(cant[i]) + ".csv";

    vector<vector<long double>> points(ms);

    for(int i=0; i<max_cant; i++){
        
        io::CSVReader<4> in(nameFiles[i]);
        in.read_header(io::ignore_extra_column,"", "x", "y", "z");
        int pos; long double x, y, z;
        while(in.read_row(pos, x, y, z)){
            points[pos] = {x, y, z};
        }

        Bruteforce<long double> bf(cant[i], 3);

        //start timer here
        auto start = chrono::high_resolution_clock::now();
        for(int j=0; j<cant[i]; j++){
            bf.insert(points[j]);
        }
        //end timer here
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        outInsert1 << cant[i] << " " << duration.count() << endl;

    }

    outInsert1.close();
}