class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int l = 0, r = n-1, t = 0, b = n-1;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int num = 1, fin = n*n;

        while(num<=fin) {
            for(int i=l; i<=r; i++) matrix[t][i] = num++;
            t++;
            for(int i=t; i<=b; i++) matrix[i][r] = num++;
            r--;
            for(int i=r; i>=l; i--) matrix[b][i] = num++;
            b--;
            for(int i=b; i>=t; i--) matrix[i][l] = num++;
            l++;
        }

        return matrix;
    }
};
