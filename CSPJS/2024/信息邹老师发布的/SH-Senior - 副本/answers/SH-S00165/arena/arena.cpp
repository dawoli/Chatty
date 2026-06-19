#include<bits/stdc++.h>
using namespace std;
int t,a1[100010],a[100010],c[100010],d[1010][1010],n,m;
bool check(){
	for(int i=1;i<=m;i++){
		int t=c[i],flag=0;
		for(int j=1;j<=20;j++){
			int ji;
			for(int k=1;k<=j;k++)  ji*=2;
			if(ji!=t)  flag=1;  
		}
		if(flag==1)  return false;
	}
	return true;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a1[i];
	for(int i=1;i<=m;i++)  cin>>c[i];
	int k;
	for(int i=1;i<=20;i++){
		int ji;
		for(int j=1;j<=i;j++)  ji*=2;
		if(ji>=n){
			k=i;
			break;
		}
	}
	for(int i=1;i<=k;i++){
		int ji;
		for(int j=1;j<=k-i;j++)  ji*=2;
		for(int j=1;j<=ji;j++)  cin>>d[i][j];
	}
	cin>>t;
	while(t--){
		int x[10];
		for(int i=0;i<4;i++)  cin>>x[i];
		for(int i=1;i<=n;i++){
			int j=i%4;
			a[i]=a1[i]^x[j];
		}
		if(n<=8&&m<=8){
			for(int i=1;i<=m;i++){
				if(c[i]==1)  cout<<1<<endl;
			}
		}
	}
	return 0;
}
