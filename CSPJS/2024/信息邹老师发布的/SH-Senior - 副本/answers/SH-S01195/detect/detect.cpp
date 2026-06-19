#include<bits/stdc++.h>
using namespace std;
const int N=20000;
int n,m,V,s,L,d[N],q[N],v[N],t,cnt,a[N],c[N][N],c1[N],c2[N],m1,n1,ans;
void so(int n,int m){
	for(int j=1;j<=n;j++){
		if(v[j]==d[j]==a[j]==0)continue;
			for(int k=1;k<=m;k++){
				if(q[k]>d[j]){
					s=sqrt(v[j]*v[j]+2*a[j]*(q[k]-d[j]));
					if(s>V)c[j][k]=1,c1[k]++,c2[j]++;
				}
			}
		}
	
}
int main(){
	freopen("detect.in","t",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>L>>V;
		for(int j=1;j<=n;j++)
			cin>>d[j]>>v[j]>>a[j];
		for(int j=1;j<=m;j++)cin>>q[i];
		so(n,m);
		for(int j=1;j<=n;j++)if(c1[j]!=0)cnt++;
		cout<<cnt<<endl;
		for(int j=1;j<=n;j++)
			if(c1[j]==0)d[j]=v[j]=v[i]=0;
		for(int k=1;k<=m;k++)
			if(c2[k]==0)q[k]=0,ans++;
		cout<<m-ans<<endl; 
	}	
} 
