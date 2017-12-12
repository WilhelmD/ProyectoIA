#ifndef PROYECTOIA_TIMER_H
#define PROYECTOIA_TIMER_H

#endif //PROYECTOIA_TIMER_H

#include <vector>

using namespace std;

long time(void (*func)(vector<int> , vector<int> , int, int, int, int, double, bool**&),vector<int> x, vector<int> y, int x1, int y1, int x2, int y2, double dist, bool** &visitados);
