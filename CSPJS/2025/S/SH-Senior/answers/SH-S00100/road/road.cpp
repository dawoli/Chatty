#include<bits/stdc++.h>
using namespace std;
int n,m,t,f[1000005];
int linjie[10005][10005];
struct node{
	int x,y,len;
}r[1000005];
bool cmp(node x,node y){
	return x.len<y.len;
}
int father(int x){
	if(f[x]==x)return f[x];
	else return f[x]=father(f[x]);
}
void bing(int x,int y){
	f[father(y)]=father(x);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,len;
		cin>>x>>y>>len;
		if(linjie[x][y]==0)linjie[x][y]=len;
		else linjie[x][y]=min(linjie[x][y],len);
	}
	int mon;
	for(int i=1;i<=t;i++){
		cin>>mon;
		int jindao[100005]={};
		for(int j=1;j<=n;j++){
			cin>>jindao[j];
		}
		for(int k=1;k<=n;k++){
			for(int j=k+1;j<=n;j++){
				if(linjie[k][j]==0)linjie[k][j]=jindao[k]+jindao[j];
				else linjie[k][j]=min(linjie[k][j],jindao[k]+jindao[j]);
			}
		}
	}
	int linshi=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(linjie[i][j]){
				linshi++;
				r[linshi].x=i;
				r[linshi].y=j;
				r[linshi].len=linjie[i][j];
			}
		}
	}
	int ans=0,ans2=0;
	sort(r+1,r+linshi+1,cmp);
	for(int i=1;i<=linshi;i++){
		if(father(r[i].x)==father(r[i].y)){
			continue;
		}
		ans+=r[i].len;
		bing(r[i].x,r[i].y);
	}
	cout<<ans;
	return 0;
}

