class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.size(), l2 = num2.size();
        vector<int> res(l1+l2,0);

        for(int i = l1-1; i>=0; i--)
            for(int j = l2-1; j>=0; j--) {
                int mul = (num1[i]-'0') * (num2[j]-'0');
                int sum = mul + res[i+j+1];
                res[i+j] += sum/10;	res[i+j+1] = sum%10;
            }

        int i = 0;
        string str;
        while( i<res.size() && res[i]==0 )	i++;
        for(; i<res.size(); i++)  str.push_back('0' + res[i]);
        return str.size()==0 ? "0" : str;
    }
};
