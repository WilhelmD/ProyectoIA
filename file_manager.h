#ifndef PROYECTOIA_FILE_MANAGER_H
#define PROYECTOIA_FILE_MANAGER_H

#endif //PROYECTOIA_FILE_MANAGER_H

#include <vector>

using namespace std;

int** build_map(char* filename);

int* get_shape(char* filename);

vector<vector<int>> get_coordinates(char* filename);