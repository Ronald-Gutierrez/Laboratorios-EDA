#ifndef BRUTEFORCE_HPP
#define BRUTEFORCE_HPP

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Bruteforce{
private:
    int dim;
    int pos;
    vector<vector<T>> points;
public:
    Bruteforce(int max_size, int dim){
        this->pos = 0;
        this->dim = dim;
        this->points.resize(max_size, vector<T>(dim));        
    }

    //insert a point to the tree
    void insert(vector<T> point){
        points[pos++] = point;
    }

    //search a point in the tree
    bool search(vector<T> point){
        for(int i = 0; i < points.size(); i++){
            if(points[i] == point){
                return true;
            }
        }
        return false;
    }
};
class Distance
{
    private:
        std::vector<double> point;
        double dist;
    public:
        Distance(std::vector<double> point, double dist)
        {
            this->point = point;
            this->dist = dist; 
        }
        int distancia(int x1,int y1, int z1, int x2,int y2, int z2,)
        {
            return sqrt(pow(x2-x1,2)+pow(y2-y1,2)+pow(z2-z1,2))
        }
};
#endif