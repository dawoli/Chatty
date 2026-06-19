#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6;
int n,m,k;
int a[MAXN];
long long cnt;
bool s[MAXN];
struct map_
{
	int u,v,w;
	int cst;
}f[MAXN];
bool cmp(map_ x,map_ y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(a[x]==x)
		return x;
	else
		return a[x]=find(a[x]);
}
bool pd()
{
	bool flag = false;
	for (int i = 2;i<=n;i++)
	{
		if (a[i]!=a[i-1])
			flag = true;
	}
	if (flag==true) return true;
	else return false;
	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i<=n+k*n;i++)
		a[i]=i;
	for (int i = 1;i<=m;i++)
	{
		int u1,v1,w1;
		//scanf("%d %d %d",&u1,&v1,&w1);
		cin >> u1 >> v1 >>w1;
		f[i].u=u1;
		f[i].v=v1;
		f[i].w=w1;
	}
	int p = m + 1;
	for (int i = m+1;i<=m+k;i++)
	{
		int rd,o;
		cin >> o;
		for (int j = 1;j<=n;j++)
		{
			cin >> rd;
			f[p].u=i;
			f[p].v=j;
			f[p].w=rd;
			f[p].cst=o;
			p++;
		}
	}
	int l = 1;
	sort(f+1,f+m+k*n+1,cmp);
	while (pd()==true)
	{
		for (int i = 1;i<=n;i++)
			cout <<a[i] << " ";
		cout <<endl;
		int x = find(f[l].u),y = find(f[l].v);
		if (x!=y)
		{
			a[x] = y;
			if (f[l].cst!=0)
				cnt += f[l].cst;
			cnt+=f[l].w;
			cout << f[l].u << " " <<f[l].v <<endl;
		}
		else
			continue;
		l++;
	}
	cout << cnt;
	//while (cnt!=n-1)
//	{
	//	int minn = 1e5,mini=-1;
//		for (int i = 1;i<=n+k;i++)
//		{
//			if (tr == i||f[tr][i]==0) continue;
	//		if (f[tr][i]<minn&&s[i]==false)
//			{
//				minn = f[tr][i];
	//			mini = i;
	//		}
	//		
//		}
//		s[mini]=true;
	//	tr = mini;
	//	ans += minn;
//		if (mini>n)
//		{
//			ans += cst[mini];
//		}
//		if (mini<=n)
//			cnt++;
//	}
	return 0;
} 
