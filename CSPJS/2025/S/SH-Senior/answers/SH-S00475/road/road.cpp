#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road1.in","r",stdin);
	//freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int>> a(n+1,vector<int>(n+1,0));
	int sum=0;
	vector<int> fi;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(a[u][v]==0){
			a[u][v]=w;
			a[v][u]=w;
			fi.push_back(w);
		}
		else{
			int x=min(a[u][v],w);
			a[u][v]=x;
			a[v][u]=x;
			if(x!=a[u][v]) fi.push_back(x);
		}
	}
	sort(fi.begin(),fi.end());
	vector<int> fei;
	int l=1;
	for(l;l<=3;l++){
		fei.push_back(fi[l]);
		sum+=fi[l];
	}
	for(int i=0;i<k;i++){
		int c;
		cin>>c;
		vector<int> ac(n+1,0);
		int ifc=1;
		for(int j=1;j<=n;j++){
			cin>>ac[j];
			for(int l=j-1;l>=1;l--){
				if(fei[l-1]>=ac[l]+ac[j]+c){
					sum=sum-(fei[l-1]-ac[l]-ac[j]);
					ifc++;
					fei[l-1]=ac[i]+ac[j]+c;
					sort(fei.begin(),fei.end());
				}
			}
		}
		if(ifc>1) sum-=c*ifc;
	}
	cout<<sum;
	return 0;
}
