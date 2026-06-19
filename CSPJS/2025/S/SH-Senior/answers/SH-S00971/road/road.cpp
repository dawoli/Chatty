#include<bits/stdc++.h>
using namespace std;
//int a[1015][1015],dis[1110];//
int s[11],fa[1105];
bool book[1110];/*
int find(int x,int cnt){
	if(book[fa[x]])return cnt;
	book[x]=1;
	cnt+=a[fa[x]][x];
}*/
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	memset(dis,0x3f,sizeof dis);
	int n,m,k,cnt=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		cnt+=w;
	}
	int cnt2=INT_MAX;
	for(int i=1;i<=k;i++){
		int w,cnt3;
		cin>>s[i];
		for(int j=1;j<=n;j++){
			cin>>w;
//			a[1000+i][j]=a[j][1000+i]=w; //
			cnt3+=w;
		}
		cnt2=min(cnt2,cnt3+s[i]);
	}
/*
		int i=q.front();
		book[i]=1;
		q.pop();
		for(int j=1;j<=n+k;j++){
			if(dis[j]<dis[i]+a[i][j]){
				dis[j]=dis[i]+a[i][j];
				q.push(j);
				fa[j]=i;
			}
		}
	}
	for(int i=1;i<=k;i++){
		dis[1000+i]+=s[i];
	}
	int cnt4=0;
	memset(book,0,sizeof book);
	for(int i=1;i<=n;i++){
		cnt4+=find(i,0);
	}*/
	cout<<min(cnt,cnt2);
	return 0;
}

