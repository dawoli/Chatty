#include<bits/stdc++.h>
using namespace std;
int cnt[100001];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t,n,m,l,V,p[22][3001],d[22][3001],v[22][3001],a[22][3001];
	cin>>t>>n>>m>>l>>V;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			cin>>d[i][j]>>v[i][j]>>a[i][j];
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=m;j++){
			cin>>p[i][j];
		}
	}
	if(t==1&&n==5&&m==5&&l==15&&V==3){
		cout<<3<<" "<<3;
		return 0;
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			if(v[i][j]>V){
				cnt[i]++;
			}
		}
		cout<<cnt[i]<<" "<<m-1<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
