#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int f[1005][1005];
int main(){
	int n,m,p;
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		for(int j=m;j>=b;j--)
			for(int k=p;k>=c;k--)
				f[j][k]=max(f[j][k],f[j-b][k-c]+a);
	}
	cout<<f[m][p];
	return 0;
} 
