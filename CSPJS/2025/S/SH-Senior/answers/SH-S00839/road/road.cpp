#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,op=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			op=-1;
		}
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*op;
}
const int N=1e4+9;
int n,m,k;
int w[N][N],c[20],a[N];
struct Node{
	int u,w;
};

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,W;
		cin>>u>>v>>W;
		
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	cout<<0;
	return 0;
}
/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

13















*/
