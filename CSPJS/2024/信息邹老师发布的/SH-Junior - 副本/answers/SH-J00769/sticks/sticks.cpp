#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[12]={
//0 1 2 3 4 5 6 7 8  9  10 11
-1,-1,1,7,4,2,6,8,10,18,22,20};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;//    _         _
		// 1<=b<=11;| b<=4:1-4, \
		//          \_b>=5:5-11_|
		int a=(n-5)/7,b=(n-5)%7+5;
		cout<<ans[b];
		for(int i=1;i<=a;i++) cout<<8;
		cout<<endl;
	}
	return 0;
}

