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

    KdTree* tree = new KdTree();

    for (int i = 1; i <= vcount; i++) {
        tree->P[i - 1] = Point(i - 1, vlist[i][0], vlist[i][1], vlist[i][2]);
        tree->T[i - 1].l = tree->T[i - 1].r = tree->T[i - 1].p = NIL;
    }
    int root = tree->makeKDTree(0, vcount, 0);

    int q;
    double x1 = 2.6;
    double y1 = 0;
    double z1 = 1.2 ;
    double r = 500;
    Point ans;
    //Tiempo de busqueda al punto mas cercano
    auto start = std::chrono::system_clock::now();
    cout<<endl;
    cout<<"Los mas cercanos al punto ("<<x1<<","<<y1<<","<<z1<<") son :"<<endl;
    tree->nearst_find(root, x1, y1, z1, r, 0, ans);
    ans.print(); 
    vector<Point> ans1;

    tree->region_find(root, -1, 1, -5, 5, -1, 3, 0, ans1);

    for (int i = 0; i < ans1.size(); i++) {
        ans1[i].print();
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration <float, std::milli> duration = end - start;
    cout<<"Duracion -- "<<duration.count()<<" ms"<<std::endl;


    return 0;
}

