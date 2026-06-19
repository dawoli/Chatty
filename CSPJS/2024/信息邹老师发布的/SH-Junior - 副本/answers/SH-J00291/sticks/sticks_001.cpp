#include<bits/stdc++.h>
using namespace std;
int t,n;
int ans[18]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=17)cout<<ans[n]<<"\n";
		else{
			int x=n%7+7;
			if(x%7<4)x+=7;
			cout<<ans[x];
			int y=(n-x)/7;
			while(y--)cout<<8;
			cout<<"\n";
		}
	}
	return 0;
}
