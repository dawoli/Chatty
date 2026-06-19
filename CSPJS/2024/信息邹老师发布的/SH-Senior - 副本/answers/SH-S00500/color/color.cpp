#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int n,a[N],T,res,sum[N];

void dfs(int p,int lr,int lb,int sc){
	if(sc>res)res=sc;
	if(p>=n||sc+sum[p]<=res)return;
	dfs(p+1,p,lb,sc+(lr==-1?0:(a[lr]==a[p]?a[p]:0)));
	dfs(p+1,lr,p,sc+(lb==-1?0:(a[lb]==a[p]?a[p]:0)));
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		sum[n]=0;
		for(int i=n-1;i>=0;i--)sum[i]=sum[i+1]+a[i];
		res=0;
		dfs(0,-1,-1,0);
		cout<<res<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

