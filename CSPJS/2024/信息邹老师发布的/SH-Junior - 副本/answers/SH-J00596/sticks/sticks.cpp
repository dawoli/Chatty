#include<bits/stdc++.h>
using namespace std;
map<int,int>a;
int k[19]={0,2,3,4,5,6,7};
long long ans[10009],s[19];
long long num(int n,int p){
	if(n==0){
		s[1]=min(s[1],ans[p-1]);
		//cout<<endl;
		return 1;
	}
	if(n>0){
		for(int i=1;i<=6;i++){
			if(n-k[i]>=0&&n-k[i]!=1){
				ans[p]=ans[p-1]*10+a[k[i]];
				if(ans[p]==0) ans[p]=6;
				//cout<<ans[p]<<" ";
				num(n-k[i],p+1);
			}
		}
	}
	return 0;
}
int main(){
	
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	a[6]=0;
	a[2]=1;
	a[3]=7;
	a[5]=2;
	a[4]=4;	
	a[7]=8;
	int T;
	cin>>T;
	while(T--){
		ans[10009]={};
		for(int i=1;i<=10009;i++)
			s[i]=1e9;
		int m;
		cin>>m;
		num(m,1);
		if(s[1]==1e9||s[1]==0)
			cout<<-1<<endl;
		else
			cout<<s[1]<<endl;
	}
		
	return 0;
}
