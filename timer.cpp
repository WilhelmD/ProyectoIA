#include "timer.h"
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

long time(void (*func)(vector<int> , vector<int> , int, int, int, int, double, bool**&),vector<int> x, vector<int> y, int x1, int y1, int x2, int y2, double dist,  bool** &visitados) {

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    func(x, y,x1, y1, x2, y2, dist, visitados);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    long duration = duration_cast<microseconds>(t2 - t1).count();
    return duration;
}
