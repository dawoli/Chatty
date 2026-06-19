freopen("club.in","r","stdin");
freopen("club.out","w","stdout");
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6;
int n,m,k;
struct rod{
	int u;
	int v;
	int w;
}a[MAXN];
int sums=0;
int h[10000][10000]; 
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=k;j++){
			cin>>h[i][j];
		}
	}
	for(int j=1;j<=n;j++){
		for(int k=1;k<=n;k++){
			if(a[j].w>a[k].w){
				int temp=a[j].w;
				a[j].w=a[k].w;
				a[k].w=temp;
				int temp2=a[j].u;
				a[j].u=a[k].u;
				a[k].u=temp;
				int temp3=a[j].v;
				a[j].v=a[k].v;
				a[k].v=temp;
			}
		}
	}	
	for(int i=1;i<=n/2;i++){
		sums+=a[i].w;
	}
	cout<<sums;
	return 0;
}
fclose(stdin);
fclose(stdout);
