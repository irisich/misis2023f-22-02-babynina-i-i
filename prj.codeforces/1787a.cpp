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

using namespace std;
 
int main() {
 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n%2!=0)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<1<<" "<<n/2<<endl;
		}
 
	}
 
	return 0;
}
 
 
 
