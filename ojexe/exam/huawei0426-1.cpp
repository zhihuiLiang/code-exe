#include <queue>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    unordered_map<int, int> depends_num;
    unordered_map<int, vector<int>> depended;
    queue<int> no_depend;

    for(int i = 1; i <= n; ++i){
        int num = 0;
        cin >> num;
        depends_num[i] = num;
        if (num == 0){
            no_depend.push(i);
        }
        for (int j = 0; j < num; ++j){
            int k;
            cin >> k;
            depended[k].push_back(i);
        }
    }

    int cnt = 0, cntN = 0;
    while(!no_depend.empty()){
        int top = no_depend.front();
        no_depend.pop();
        vector<int> tmp_vec;
        tmp_vec.push_back(top);
        while(!no_depend.empty() && depends_num[top] == 0){
            tmp_vec.push_back(top);
            top = no_depend.front();
            no_depend.pop();
        }
        ++cnt;
        for (int j = 0; j < tmp_vec.size(); ++j){
            cntN++;
            auto vec = depended[tmp_vec[j]];
            for (int i = 0; i < vec.size(); ++i){
                depends_num[vec[i]]--;
                if (depends_num[vec[i]] == 0){
                    no_depend.push(vec[i]);
                }
            }
        }

    }
    if (cntN < n){
        std::cout << -1 << std::endl;
    }else{
        std::cout << cnt << std::endl;
    }

    return 0;
}