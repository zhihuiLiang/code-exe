#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& vec){
    for (size_t i = 0; i < vec.size(); ++i){
        out << vec[i] << " ";
    }
    out << endl;
    return out;
}