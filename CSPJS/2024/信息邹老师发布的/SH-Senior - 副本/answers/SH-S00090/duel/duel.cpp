	//freopen不要注释 
	//freopen不要注释 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int r[N];
int f[N];
bool vis[N];
bool g[N];
bool k[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	int ans=0;
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++){
		int a=r[i];
		if(r[i]==a)
			f[r[i]]++;
		g[i]=1;
	}
	for(int i=1;i<=n;i++){
		while((vis[r[i]]==0)&&(f[r[i]]>=0)){
			for(int j=1;j<=n;j++){
				if((r[j]>r[i])&&g[j]==1&&(f[r[i]]>0)){
					f[r[i]]--;
					g[j]=0;
				}
			}
		vis[r[i]]=1;
		}
	
	}
	
	for(int i=1;i<=n;i++){
		k[r[i]]=1;
	}
	for(int i=1;i<=n;i++){
		if(k[r[i]]){
			ans+=f[r[i]];
		}
			
		k[r[i]]=0;
	}
	cout<<ans;
	//输出用\n 
	//记得写freopen，并且不要注释掉！！！！！
	//freopen不要注释
	//写return 0 
	return 0;
} 
