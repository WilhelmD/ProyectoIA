#include <iostream>
#include <vector>
#include "file_manager.h"
#include "timer.h"
#include "gbj.h"

using namespace std;

vector<int> best_x;
vector<int> best_y;
double best_dist = -1;
int* shape;
int** mapa;
vector<vector<int>> puntos;

void gbj(vector<int> x, vector<int> y, int x1, int y1, int x2, int y2, double dist, bool** visitados) {

    if (mapa[x1][y1] == 1) {
        return;
    }
    visitados[x1][y1] = true;
    node* sol = new node(x, y, x1, y1, dist);

    unsigned long size = sol->sol_x.size();

    if (sol->sol_x[size-1] == x2 && sol->sol_y[size-1] == y2) {
        if (best_dist == -1) {
            best_x = sol->sol_x;
            best_y = sol->sol_y;
            best_dist = dist;
        } else if (dist < best_dist) {
            best_x = sol->sol_x;
            best_y = sol->sol_y;
            best_dist = dist;
        }
	delete sol;
        return;
    }

    if (x1+1 <= shape[0]-1) {
        if (!visitados[x1+1][y1]) {
            gbj(sol->sol_x,sol->sol_y,x1+1,y1,x2,y2,dist+1,visitados);
        }

        if (y1-1 >= 0) {
            if (!visitados[x1+1][y1-1]) {
                gbj(sol->sol_x,sol->sol_y,x1+1,y1-1,x2,y2,dist+1.41,visitados);
            }
        }


        if (y1+1 <= shape[0]-1) {
            if (!visitados[x1+1][y1+1]) {
                gbj(sol->sol_x,sol->sol_y,x1+1,y1+1,x2,y2,dist+1.41,visitados);
            }

        }
    }

    if (y1+1 <= shape[0]-1) {

        if (x1-1 >= 0) {
            if (!visitados[x1-1][y1+1]) {
                gbj(sol->sol_x,sol->sol_y,x1-1,y1+1,x2,y2,dist+1.41,visitados);
            }
        }

        if (!visitados[x1][y1+1]) {
            gbj(sol->sol_x,sol->sol_y,x1,y1+1,x2,y2,dist+1,visitados);
        }

    }

    if (y1-1 >= 0) {
        if (!visitados[x1][y1-1]) {
            gbj(sol->sol_x,sol->sol_y,x1,y1-1,x2,y2,dist+1,visitados);
        }
    }

    if (y1-1 >= 0 && x1-1 >= 0) {
        if (!visitados[x1-1][y1-1]) {
            gbj(sol->sol_x,sol->sol_y,x1-1,y1-1,x2,y2,dist+1.41,visitados);
        }
    }

    if (x1-1 >= 0) {
        if (!visitados[x1-1][y1]) {
            gbj(sol->sol_x,sol->sol_y,x1-1,y1,x2,y2,dist+1,visitados);
        }
    }

}

int main(int argc, char** argv) {

    if (argc < 4) {
        cerr << "Inputs incorrectos, Ingresar nombre de instancia y archivo de coordenadas" << endl;
        return 1;
    }

    shape = get_shape(argv[1]);
    mapa = build_map(argv[1]);
    puntos = get_coordinates(argv[2]);
    int seleccion = stoi(argv[3]);
    int xi,yi,xf,yf;

    bool** visitados = new bool*[shape[0]];
    for (int i=0; i<shape[0]; i++) {
        visitados[i] = new bool[shape[1]];
    }

    for (int i=0; i<shape[0]; i++) {
        for (int j=0; j<shape[1]; j++) {
            visitados[i][j] = false;
        }
    }


    switch (seleccion) {
        case 1:
            xi = puntos[0][0];
            yi = puntos[0][1];
            xf = puntos[0][2];
            yf = puntos[0][3];
            break;
        case 2:
            xi = puntos[1][0];
            yi = puntos[1][1];
            xf = puntos[1][2];
            yf = puntos[1][3];
            break;
        case 3:
            xi = puntos[2][0];
            yi = puntos[2][1];
            xf = puntos[2][2];
            yf = puntos[2][3];
            break;
        default:
            xi = puntos[0][0];
            yi = puntos[0][1];
            xf = puntos[0][2];
            yf = puntos[0][3];
            break;
    }

    vector<int> x = vector<int>();
    vector<int> y = vector<int>();

    cout << "punto inicial: (" << xi << "," << yi << ")" << endl;
    cout << "punto final: (" << xf << "," << yf << ")" << endl;

    long duration = time(gbj,x, y, xi, yi, xf, yf, 0, visitados);

    unsigned long size = best_x.size();

    cout << "Solucion encontrada:" << endl;
    for (unsigned int i=0;i<size;i++) {
        cout << "(" << best_x[i] << "," << best_y[i] << ")";
        if (i != size-1) {
            cout << " -> ";
        }
    }
    cout << endl;
    cout << "Largo del camino: " << best_dist << endl;
    cout << "Tiempo de ejecucion: "<< duration << " microsegundos." << endl;

    return 0;
}
