#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k,sum=0,tmpw;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int uvw[m][3],c[k],a[k][n],wealth[m];
	for(int i=0;i<m;i++) cin>>uvw[i][0]>>uvw[i][1]>>uvw[i][2];
	for(int j=0;j<k;j++){
		cin>>c[j];
		for(int i=0;i<n;i++) cin>>a[j][i];
	}
	if(c[0]!=0){
		for(int i=0;i<m;i++) wealth[i]=uvw[i][2];
		sort(wealth,wealth+m);
		for(int i=0;i<n-1;i++) sum+=wealth[i];
		cout<<sum;
	}
	else cout<<0;
	return 0;
}
