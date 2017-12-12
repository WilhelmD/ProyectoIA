#ifndef PROYECTOIA_GBJ_H
#define PROYECTOIA_GBJ_H

#endif //PROYECTOIA_GBJ_H

#include <vector>

using namespace std;

struct node {
    vector<int> sol_x;
    vector<int> sol_y;
    double distancia;
    node (vector<int> x, vector<int> y, int x1, int y1, double dist) {

        sol_x = x;
        sol_x.push_back(x1);
        sol_y = y;
        sol_y.push_back(y1);
        distancia += dist;
    }
};

void gbj(vector<int> x, vector<int> y, int x1, int y1, int x2, int y2, double dist, bool** &visitados);