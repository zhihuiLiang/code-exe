#include <iostream>
#include <map>
#include <vector>


int main(){
    int n_in = 0;
    std::cin >> n_in;
    
    std::map<int, int> m;
    for (int i = 0; i < n_in; ++i){
        int b = 0, e = 0;
        std::cin >> b >> e;

        m[b]++;
        m[e + 1]--;
    }

    int n_task = 0, cost = 0, pre_num = 0, c = 0;
    for (auto it = m.begin(); it != m.end(); ++it){
        cost += (it->first - pre_num) * c;
        n_task += it->second;
        if (n_task == 0){
            c = 1;
        }else if (n_task == 1){
            c = 3;
        }else{
            c = 4;
        }
        pre_num = it->first;

    }
    std::cout << cost;
}