#include <iostream>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;
int main(){
    set<int> resources;
    int start, end;
    cin >> start >> end;
    for (int i = start; i <= end; ++i){
        resources.insert(i);
    }
    int opts_num = 0;
    cin >> opts_num;
    for (int i = 0; i < opts_num; ++i){
        int opt_type, opt_id;
        cin >> opt_type >> opt_id;
        switch (opt_type)
        {
        case 1:
            while(!resources.empty() && opt_id > 0){
                resources.erase(resources.begin());
            }
            break;
        case 2:
            resources.erase(opt_id);
            break;
        case 3:
            if (!resources.count(opt_id)){
                resources.insert(opt_id);
            }
            break;
        default:
            break;
        }
    }
    std::cout << *resources.begin() << std::endl;
    return 0;
}