#include <bits/stdc++.h>

using namespace std;

const int N = 5000;

int mapr[N][N];
int che[N],used[N];

int n=0,m=0,k=0,ua=0,ub=0,uc=0,bucos=0,curcos=0,nu,ans=0;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>ua>>ub>>uc;
		mapr[ua][ub]=uc;
		mapr[ub][ua]=uc;
	}
	nu=n+1;
	for(int i=0;i<k;i++){
		cin>>bucos;
		che[nu]+=curcos;
		for(int j=1;j<=n;j++){
			cin>>curcos;
			mapr[nu][j]=curcos;
			mapr[j][nu]=curcos;
		}
		nu++;
	}
	for(int o=1;o<=n;o++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(che[o]!=0){
					used[o]+=1;
				}
				if(che[i]!=0){
					used[i]+=1;
				}
				if(che[j]!=0){
					used[j]+=1;
				}
				mapr[i][j]=min(mapr[i][j],mapr[i][o]+mapr[o][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans+=mapr[i][j];
		}
	}
	for(int i=0;i<k;i++){
		if(used[n+k]!=0){
			ans+=che[n+k];
		}
	}
	cout<<ans;
	return 0;
}
