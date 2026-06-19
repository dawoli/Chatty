#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k;
struct node{
	int head;
	int cc;
} g[N];
int a[N][N],c[N];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>g[i].head>>g[i].cc;
	}
	bool flag1=true,flag2[N]={false},flag3=true;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag1=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0) flag2[i]=true;
		}
		if(!flag2[i]) flag3=false;
	}
	int ans=0;
	if(flag1&&flag3){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=k;j++){
				for(int z=1;z<=n;z++){
					if(a[j][z]==0&&g[i].head==z) ans+=0;
					else ans+=g[i].cc;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
