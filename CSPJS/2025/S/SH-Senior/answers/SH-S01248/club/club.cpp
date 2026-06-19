#include <bits/stdc++.h>

using namespace std;

int a[1000001][4];
int maxf;
int t,n;

void ds(int x,int y,int z,int ct,int nb)
{
	if(ct==n) return;
	if(x+1<=n/2) {maxf=max(maxf,nb+a[ct+1][1]);ds(x+1,y,z,ct+1,nb+a[ct+1][1]);}
	if(y+1<=n/2) {maxf=max(maxf,nb+a[ct+1][2]);ds(x,y+1,z,ct+1,nb+a[ct+1][2]);}
	if(z+1<=n/2) {maxf=max(maxf,nb+a[ct+1][3]);ds(x,y,z+1,ct+1,nb+a[ct+1][3]);}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	memset(a,0,sizeof(a));
	maxf=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		maxf=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			int a1,a2,a3;
			cin>>a1>>a2>>a3;
			a[j][1] = a1;
			a[j][2] = a2;
			a[j][3] = a3;
		}
		ds(0,0,0,0,0);
		cout<<maxf<<endl;
	}
	
	return 0;
}
