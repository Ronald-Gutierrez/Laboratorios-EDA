#include<bits/stdc++.h>
using namespace std;

#define MS 10000

class Bruteforce{
private:
    int dim;
    int pos;
    vector<vector<double>> points;
public:
    Bruteforce(int max_size, int dim){
        this->pos = 0;
        this->dim = dim;
        this->points.resize(max_size, vector<double>(dim));        
    }

    //insert a point to the tree
    void insert(vector<double> point){
        points[pos++] = point;
    }

    //search a point in the tree
    bool search(vector<double> point){
        for(int i = 0; i < points.size(); i++){
            if(points[i] == point){
                return true;
            }
        }
        return false;
    }

};

int main(int argc, char const *argv[])
{
    Bruteforce bf(10, 3);
    bf.insert({1, 2, 3});
    bf.insert({4, 5, 6});
    bf.insert({7, 8, 9});
    (bf.search({7, 8, 9}) == 1) ? cout << "Yes" << endl : cout << "No" << endl;

    vector<vector<double>> points;
    vector<Distance> dists;
    vector<double> target // punto objetivo
    // Insertas los puntos en points
    //...
    
    for (auto a: points)
    {
        int dst = distancia(a,target);
        dists.push_back(Distance(a,dst));
    }

    dists.sort() // ordenas de acuerdo a las dist

    for (int i = 0; i < k; i++)
    {
        cout<<dists[i]<<" "<<endl;
    }
    return 0;
}