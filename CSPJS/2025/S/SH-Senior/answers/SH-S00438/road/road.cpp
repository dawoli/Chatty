#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int v[1000020][2];
int w[1000020];
int a[16][10010];
int c[16];
long long money=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>v[i][0]>>v[i][1]>>w[i];
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;i++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int x=0,b=INT_MAX,bp;
			for(int l=0;l<m;l++){
				if(v[l][0]==i&&v[l][1]==j||v[l][1]==i&&v[l][0]==j){
					x=w[l];
				}
			}
			for(int l=0;l<k;l++){
				if(b>a[l][i]+a[l][j]){
					b=a[l][i]+a[l][j];
					bp=l;
				}
			}
			if(b+c[bp]>x){
				money+=x;
			}
			else{
				money+=b+c[bp];
				c[bp]=0;
			}
		}
	}
	cout<<money;
	return 0;
}
