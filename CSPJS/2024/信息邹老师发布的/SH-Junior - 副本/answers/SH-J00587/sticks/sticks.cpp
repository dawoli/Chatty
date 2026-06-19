#include<bits/stdc++.h>
using namespace std;
int t,n[51],maxn;
struct NODE{int v,w;}f[100001];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		maxn=max(maxn,n[i]);
	}
	memset(f,-1,sizeof(f));
	f[2].v=1,f[3].v=7,f[4].v=4,f[5].v=2,f[6].v=0,f[7].v=8;
	f[2].w=f[3].w=f[4].w=f[5].w=f[6].w=f[7].w=1;
	for(int i=8;i<=maxn;i++){
		int minn=1E9,mini;
		for(int j=2;j<=7;j++)
			if(f[i-j].v!=-1&&minn>f[j].v*pow(10,f[i-j].w)+f[i-j].v){
				minn=f[j].v*pow(10,f[i-j].w)+f[i-j].v;
				mini=f[i-j].w+1;
			}
		if(minn!=1E9)f[i].v=minn,f[i].w=mini;
	}
	for(int i=1;i<=t;i++){
		int minn=1E9;
		if(n[i]<=7){
			if(n[i]==6)cout<<6<<endl;
			else cout<<f[n[i]].v<<endl;
			continue;
		}
		for(int j=2;j<=7;j++){
			if(f[n[i]-j].v!=-1){
				if(j==6)minn=min(minn,int(6*pow(10,f[n[i]-j].w)+f[n[i]-j].v));
				else minn=min(minn,int(f[j].v*pow(10,f[n[i]-j].w)+f[n[i]-j].v));
			}
		}
		cout<<minn<<endl;
	}
	return 0;
}
