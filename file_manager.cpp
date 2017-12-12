#include "file_manager.h"
#include <iostream>
#include <fstream>

using namespace std;

int** build_map(char* filename) {
    ifstream file;
    file.open(filename);

    //Obtener ancho y alto

    int n, m;
    file >> n >> m;

    //Crear mapa de obstaculos

    int** obstaculos = new int*[n];
    for (int i=0; i<n; i++) {
        obstaculos[i] = new int[m];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            file >> obstaculos[j][i];
        }
    }

    file.close();

    return obstaculos;
}

int* get_shape(char* filename) {
    ifstream file;
    file.open(filename);

    //Obtener ancho y alto

    int n, m;
    file >> n >> m;

    //Crear mapa de obstaculos

    int* shape = new int[2];
    shape[0] = n;
    shape[1] = m;

    file.close();

    return shape;
}

vector<vector<int>> get_coordinates(char* filename) {
    ifstream file;
    file.open(filename);

    //Guardar puntos en un arreglo

    vector<vector<int>> puntos(3, vector<int>(3));

    for (int i=0;i<3;i++) {
        for (int j=0;j<4;j++) {
            file >> puntos[i][j];
        }
    }

    file.close();

    return puntos;
}
