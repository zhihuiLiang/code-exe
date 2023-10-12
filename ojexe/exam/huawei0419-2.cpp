#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <memory>
#include <set>
#include <unordered_map>

using namespace std;

struct Node{
    int index;
    std::shared_ptr<Node> parent;
    int len;

    Node() = default;
    Node(int i, std::shared_ptr<Node> p, int l) : index(i), parent(p), len(l){}
};


int main(){
    int n_node  = 0, n_edge = 0;
    cin >> n_node;
    cin >> n_edge;
    
    vector<vector<int>> map(n_node, vector<int>(n_node));
    set<int> obs;
    
    for (int i = 0; i < n_edge; ++i){
        int beg = 0, end = 0;
        cin >> beg >> end;
        map[beg][end] = 1;
        map[end][beg] = 1;
    }

    int nobs = 0;
    cin >> nobs;
    for (int i = 0; i < nobs; ++i){
        int p = -1;
        cin >> p;
        obs.insert(p);
    }
    
    queue<std::shared_ptr<Node>> que;
    set<int> used;
    auto p_node = std::make_shared<Node>(0, nullptr, 0);
    que.push(p_node);
    used.insert(0);

    std::shared_ptr<Node> end(nullptr);
    while(!que.empty()){
        auto top = que.front();
        que.pop();

        int p_len = top->len;
        int p_idx = top->index;

        bool is_leaf = true;       
        for (int i = 0; i < n_node; ++i){
            if (map[p_idx][i] == 1 && used.count(i) == 0){
                is_leaf = false;
                if (obs.count(i) == 0){
                    int len = p_len + 1;
                    auto next_node = std::make_shared<Node>(i, top, len);
                    used.insert(i);
                    que.push(next_node);
                }
            }
        }
        
        if (is_leaf){
            end = top;
            break;
        }
    }
    

    vector<int> ans;
    while(end){
        ans.push_back(end->index);
        end = end->parent;
    }

    for (int i = ans.size() - 1; i >= 0; --i){
        if (i  == 0) {
            std::cout << ans[i] << std::endl;
        }
        std::cout << ans[i] << "->";
    }

    return 0;
}