#include<bits/stdc++.h>
using namespace std;
int f[25]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888};
int t;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		int n; cin>>n;
		if(n<=21){
			cout<<f[n]<<endl;
			continue;
		}
		string ans="";
		for(int i=1;i<=(n-1)/7+1;i++) ans=ans+'8';
		int k=ans.size()*7-n;
		if(k>=5){
			k-=5; ans[0]='1';
			for(int i=1;i<=k;i++)
				ans[i]='0';
		}
		else if(k>=1&&k<=4){
			if(k==1) ans[0]='6';
			if(k==2) ans[0]='2';
			if(k==3) ans[0]='2',ans[1]='0';
			if(k==4) ans[0]='2',ans[1]='0',ans[2]='0';
		}
		cout<<ans<<endl;
	}
	return 0;
}
