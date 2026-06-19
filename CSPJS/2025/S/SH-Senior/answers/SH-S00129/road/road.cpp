#include <bits/stdc++.h>
using namespace std;
struct road{
	int a,b,c;
}gi[100005];
struct improve{
	int d,e,f,g,h;
}im[100005];
bool cmp(int a3,int b3)
{
	return gi[a3].c<gi[b3].c;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,cnt=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>gi[i].a>>gi[i].b>>gi[i].c;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>im[i].d>>im[i].e>>im[i].f>>im[i].g>>im[i].h;
	}
	for(int i=1;i<=n-1;i++)
	{
		cnt+=gi[i].c;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
