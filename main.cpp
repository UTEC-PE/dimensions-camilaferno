#include <cstdlib>
#include <iostream>

#include "vector.h"

using namespace std;

template <typename T>
struct Dimensions {
    int operator()(int* coordinates, int* sizes, int dimensions) {
        int d_pos = 0;
        for(int i=dimensions-1; i>=0; i--){
          d_pos *= sizes[i];
          d_pos += coordinates[i];
        }
        return d_pos;
    }
};

struct Integer {
       typedef int T;
       typedef Dimensions<T> Operation;
};

int main(int argc, char *argv[]) {
    int dimsizes[]={3,3};
    int coords[]={0,1};
    Vector<Integer> v(sizeof(dimsizes)/sizeof(*dimsizes), dimsizes);
    v.set(7,coords);
    cout << v.get(coords);

    return EXIT_SUCCESS;
}
