class Solution {
public:
    int fib(int N) {
        if(N == 0 || N == 1)    return N;
        vector<int> vec(N+1, 0);
        vec[1] = 1;
        for(int i = 2; i <=N; ++i) 
            vec[i] = vec[i-1] + vec[i-2];
        return vec[N];
    }
};
