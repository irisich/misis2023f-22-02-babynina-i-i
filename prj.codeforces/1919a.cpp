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

  int n;
  cin>>n;
  
  while(n--){
    int x,y;
    cin>>x>>y;
    int z = (x+y);
    if(z%2 == 0){
      cout<<"Bob"<<endl;
    }
    else{
      cout<<"Alice"<<endl;
    }
  }
  return 0;
}
