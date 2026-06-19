#include<iostream>
using namespace std;
int n;
//int sch(int a[],int i,int sum,int mx){
//	if(i==n){
//		if(sum>2*mx)return 1;
//		else return 0;
//	}
//	return (sch(a,i+1,sum+a[i],max(mx,a[i]))+sch(a,i+1,sum,mx))%998244353;
//}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[n];
	int s=0,m=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s+=a[i];
		m=max(m,a[i]);
	}
//	cout<<sch(a,0,0,0);
	int f[n+1][s+1][m+1];
	for(int i=1;i<=s;i++)for(int j=1;j<=m;j++)f[n][i][j]=i>2*j;
	f[n][0][0]=0;
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<=s;j++){
			for(int k=0;k<=m;k++){
				if(j+a[i]<=s)f[i][j][k]=(f[i+1][j+a[i]][max(k,a[i])]+f[i+1][j][k])%998244353;
				else f[i][j][k]=(f[i+1][j][k])%998244353;
			}
		}
	}
	cout<<f[0][0][0]; 
	return 0;
}

