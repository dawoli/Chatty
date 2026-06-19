#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
const int N=1e6+10;
struct road{
	int st,gt,fei;
} r[N];
int n,m,k,sum;
int fa[N];
int arr[N];
int xiangcun[N];
int find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	fa[x]=find(x);
	return fa[x];
}
bool cmp(road a,road b)
{
	return a.fei<b.fei;
}
bool cmp2(int a,int b)
{
	return a<b;
}
void uniun(int a,int b)
{
	int Fa=find(a),Fb=find(b);
	fa[Fb]=Fa;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>r[i].st>>r[i].gt>>r[i].fei;
	}
	sort(r+1,r+n+1,cmp);
	if(k==0)
	{
		for(int i=1;i<n;i++)
		{
			sum=sum+r[i].fei;
		}
		cout<<sum;
		return 0;
	}
	int minx=INT_MAX,minx2=INT_MAX;
	for(int i=1;i<=k;i++)
	{
		int temp;
		cin>>temp;
		for(int j=1;j<=n;j++)
		{
			cin>>xiangcun[j];
		}
		sort(xiangcun+1,xiangcun+n+1,cmp2);
		int res=xiangcun[1]+xiangcun[2];
		minx=min(minx,res);
		minx2=min(minx2,temp);
	}
	for(int i=1;i<n-1;i++)
	{
		sum+=r[i].fei;
	}
	sum=sum+minx+minx2;
	cout<<sum;
	return 0;
}
