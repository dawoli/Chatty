#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int u[1000010],v[1000010],w[1000010];
int b[10][10010]={1};
int c[10];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int sum=0,count1=0,sum1=0;;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int z=1;z<=m;z++){
			cin>>a[z];
			if(a[z]==0){
				count1++;
			}
		}
	}
	if(k==0){
		for(int i=1;i<=m;i++){
			sum+=u[i];
		}
		cout<<sum<<endl;
	}
	if(count1==m){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				b[i][j]=0;
			}
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(b[i][j]!=0){
					for(int x1=1;x1<=m;x1++){
						if(u[x1]==i && v[x1]==j){
							sum1+=w[x1];
						}
					}
				}
			}
		}
		cout<<sum1;
	}
	return 0;
}
