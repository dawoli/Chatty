#include<bits/stdc++.h>
using namespace std;
int l[1005][1005];
char q[1005];
int p[8]={0,1,1,0,0,-1,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	long long t;
	cin>>t;
	for(int i=1;i<=t;i++){
		long long m,n;
		long long w;
		cin>>m>>n>>w;
		int a,b,f;
		cin>>a>>b>>f;
		for(int j=1;j<=m;j++){
			cin>>q;
			for(int k=0;k<n;k++){
				if(q[k]=='.'){
					l[j][k+1]=0;
				}
				else{
					l[j][k+1]=-1;
				}
			}
		}
		l[a][b]=1;
		for(int j=1;j<=w;j++){
			long long a1=a+p[f*2];
			long long b1=b+p[f*2+1];
			if(a1>=1&&a1<=m&&b1>=1&&b1<=n&&l[a1][b1]!=-1){
				a=a1;
				b=b1;
				l[a][b]=1;
			}
			else{
				f=(f+1)%4;
			}
		}
		long long cnt=0;
		for(int j=1;j<=m;j++){
			for(int k=1;k<=n;k++){
				if(l[j][k]==1){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
