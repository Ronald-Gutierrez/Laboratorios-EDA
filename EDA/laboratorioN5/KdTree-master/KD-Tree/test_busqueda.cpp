
#include "KdTree.cpp"
#include <chrono>
#include <ctime>
int main() {
    int vcount = 0;
    double vlist[3000][3];

    const char* filename = "1000.txt";
    // const char* filename = "10000.txt";
    // const char* filename = "20000.txt";

    cout << "Opening " << filename << endl;
    ifstream inFile;
    inFile.open(filename);
    if (!inFile.is_open()) {
        cout << "We cannot find your file " << filename << endl;
        exit(1);
    }

    string line;
    int i, j;
    bool firstVertex = 1;
    double currCood;
    
    while (getline(inFile, line)) {
        if ((line[0] == 'v' || line[0] == 'f') && line[1] == ' ') {
            if (line[0] == 'v') {
                vcount++;
                i = 1;
                const char* linec = line.data();
                for (int k = 0; k < 3; k++) { // k is 0,1,2 for x,y,z
                    while (linec[i] == ' ') i++;
                    j = i;
                    while (linec[j] != ' ') j++;
                    currCood = vlist[vcount][k] = atof(line.substr(i, j - i).c_str());
                    i = j;
                }

                firstVertex = 0;
            }
        }
    }
    // Tomamos el tiempo de insercion en el KD-Tree
    KdTree* tree = new KdTree();

    for (int i = 1; i <= vcount; i++) {
        tree->P[i - 1] = Point(i - 1, vlist[i][0], vlist[i][1], vlist[i][2]);
        tree->T[i - 1].l = tree->T[i - 1].r = tree->T[i - 1].p = NIL;
    }
    int root = tree->makeKDTree(0, vcount, 0);

    int q;
    double x1 = 2.6 ,y1 = 0, z1 = 1.2 , r = 0;
    Point ans;

    //Tiempo de busqueda de un punto
    auto start = std::chrono::system_clock::now();
    tree->nearst_find(root, x1, y1, z1, r, 0, ans);
    cout<<"Tiempo de Busqueda del punto"<<endl;
    ans.print();  
     auto end = std::chrono::system_clock::now();
    std::chrono::duration <float, std::milli> duration = end - start;
    cout<<"Duracion -- "<<duration.count()<<" ms"<<std::endl;


    return 0;
}