#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<deque>

#define ll long long
using namespace std;
 
int main() {
    int t;
    cin>> t;
    while(t--){
        int n;
        cin>>n;
        unordered_map <char, int> m;
        string s;
        cin>> s;
        for(auto c: s){
            m[c]++;
        }
        cout<<abs(m['+']-m['-'])<<endl;
    }
    return 0;
}
