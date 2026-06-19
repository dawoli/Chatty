#include<bits/stdc++.h>

using namespace std;
int t; 
int d[100007];
int v[100007];
int a[100007];
int p[100007];
int cnt;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cnt=0;
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		for(int j=1;j<=n;j++){
			cin>>d[j]>>v[j]>>a[j];
			if(v[j]>V){
				cnt++;
			}
		}
		for(int j=1;j<=m;j++){
			cin>>p[j]; 
		}
		cout<<cnt<<" "<<cnt;
	}
	return 0;
}
