#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main() {
    int loop;
    cin >> loop;
    while(loop--) {
        
        // create map
        int comp_num, coop_num;
        cin >> comp_num >> coop_num;

        vector<vector<int>> costs(comp_num+1, vector<int>(comp_num+1, INT_MAX));

        for(int i = 1; i <= comp_num; ++i) {
            cin >> costs[0][i];
            costs[i][0] = costs[0][i];
        }
        for(int i = 0; i < coop_num; ++i) {
            int a, b, cost;
            cin >> a >> b >> cost;
            costs[a][b] = min(costs[a][b], cost);
            costs[b][a] = min(costs[b][a], cost);
        }

        // prim
        vector<int> vertex(comp_num+1, 0);
        vector<int> lowest(comp_num+1);
        for(int i = 0; i < comp_num+1; ++i) lowest[i] = costs[0][i];

        int sumCost = 0;

        vertex[0] = 1;
        for(int i = 0; i < comp_num; ++i) {
            int index = -1;
            for(int j = 0; j < comp_num+1; ++j) {
                if(!vertex[j] && (index == -1 || lowest[index] > lowest[j])) {
                    index = j;
                }
            }
            vertex[index] = 1;
            sumCost += lowest[index];
            for(int j = 0; j < comp_num+1; ++j) {
                if(lowest[j] > costs[index][j]) {
                    lowest[j] = costs[index][j];
                }
            }
        }
        cout << sumCost << endl;

    }
    return 0;
}
