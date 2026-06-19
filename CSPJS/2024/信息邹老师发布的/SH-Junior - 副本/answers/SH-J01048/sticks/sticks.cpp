#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x,ans,a[14]{0,-1,1,7,4,2,6,8,10,18,25,20,28,68};
signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>n;
	while (n--){
		cin>>x;
		while(x>=14)x-=7,ans++;
		cout<<a[x];
		while(ans>0&&ans--)cout<<8;
		cout<<endl;
	}
	return 0;
}
