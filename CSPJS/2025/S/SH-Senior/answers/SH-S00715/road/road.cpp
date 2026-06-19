#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
struct node
{
	int u,v,w;
	void in() {cin >> u >> v >> w;}
}road[1040010],in[1040010];
int n,m,k,c[10][10010],ans = 100000000000000000,f[10020],num,sum[10020];
void init(int n)
{
	for(int i = 1;i <= n;i++)
	{
		f[i] = i;
		sum[i] = 1;
	}
	num = n;
}
int find(int x)
{
	if(f[x] == x) return x;
	else return (f[x] = find(f[x]));
}
bool cmp(node a,node b) {return a.w < b.w;}
void solve(int mm,int res,int nn)
{
	for(int i = 1;i <= mm;i++) road[i] = in[i];
	//cout << mm << '~' << res << '~' << nn << endl;
	init(nn);
	sort(road + 1,road + mm + 1,cmp);
	for(int i = 1;i <= mm;i++)
	{
		int x = road[i].u,y = road[i].v;
		x = find(x);
		y = find(y);
		if(x != y)
		{
			if(sum[x] > sum[y]) swap(x,y);
			f[x] = y;
			res += road[i].w;
			if(res >= ans) return;
			num--;
			//cout << x << ' ' << y << ' ' << res << endl;
			if(num == 1) break;
		}
	}
	//cout << mm << ' ' << res << ' ' << nn << endl;
	ans = res;
}
void dfs(int x,int now,int mm,int nn,bool ggod)
{
	if(now >= ans) return;
	if(x > k) solve(mm,now,nn);
	else
	{
		if(ggod)
		{
			nn++;
			for(int i = 1;i <= n;i++) in[++mm] = {i,nn,c[x][i]};
			now += c[x][0];
			dfs(x + 1,now,mm,nn,ggod);
			return;
		}
		bool god = rand() % 2;
		if(god)
		{
			dfs(x + 1,now,mm,nn,ggod);
			nn++;
			for(int i = 1;i <= n;i++) in[++mm] = {i,nn,c[x][i]};
			now += c[x][0];
			dfs(x + 1,now,mm,nn,ggod);
		}
		else
		{
			int ynow = now,ymm = mm,ynn = nn;
			nn++;
			for(int i = 1;i <= n;i++) in[++mm] = {i,nn,c[x][i]};
			now += c[x][0];
			dfs(x + 1,now,mm,nn,ggod);
			dfs(x + 1,ynow,ymm,ynn,ggod);
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	srand(time(0));
	for(int i = 1;i <= m;i++) in[i].in();
	bool flag = true;
	for(int i = 1;i <= k;i++)
	{
		cin >> c[i][0];
		if(c[i][0]) flag = false;
		bool have = false;
		for(int j = 1;j <= n;j++)
		{
			cin >> c[i][j];
			if(!c[i][j]) have = true;
		}
		flag = flag && have;
	}
	if(flag) dfs(1,0,m,n,1);
	else
	{
		solve(m,0,n);
		dfs(1,0,m,n,0);
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
