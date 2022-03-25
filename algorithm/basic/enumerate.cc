// 一个数组中的数互不相同，求其中和为0的数对的个数

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    int temp;

    while(cin >> temp) v.push_back(temp);

    int sum = 0;
    for(int i = 0; i < v.size(); i++)
	for(int j = 0; j < i; j++)
	    if( v[i] + v[j] == 0 )
		sum++;

    cout << sum << endl;
}
