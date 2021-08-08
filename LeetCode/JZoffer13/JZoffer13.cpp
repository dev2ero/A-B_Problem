class Solution {
    int getBSun(int num) {
        int sum = num%10;
        while(num != 0) {
            num /= 10;
            sum += num;
        }        
        return sum;
    }
public:
    int movingCount(int m, int n, int k) {
        if(k == 0)  return 1;

        vector<vector<int>> visited(m, vector(n, 0));
        queue<pair<int, int>> point;
        int dx[2] = {1, 0};
        int dy[2] = {0, 1};

        point.push(make_pair(0, 0));
        visited[0][0] = 1;

        int ans = 1;
        while(!point.empty()) {
            auto [x, y] = point.front(); point.pop();
            for(int i = 0; i < 2; ++i) {
                int next_x = x + dx[i], next_y = y + dy[i];
                if(next_x == m || next_y == n || visited[next_x][next_y] || getBSun(next_x) + getBSun(next_y) > k) continue;
                point.push(make_pair(next_x, next_y));
                visited[next_x][next_y] = 1;
                ans += 1;
            }
        }
        return ans;
    }
};
