#include<bits/stdc++.h>
using namespace std;
struct road{
	long long u,v,w;
} rd[1000007];
bool cmp(road a,road b)
{
	return a.w<b.w;
}
long long n,m,k,c[11][10006],ans;
long long conc[10007],cst[1000007][11];
long long find(long long pt)
{
	cerr<<111<<endl;
	if(conc[pt] == pt) return pt;
	else conc[pt] = find(conc[pt]);
}
int main()
{
	//aim:12pts
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++) cin>>rd[i].u>>rd[i].v>>rd[i].w;
	for(int i = 1;i<=k;i++) for(int j = 1;j<=n;j++) cin>>c[i][j];
	sort(rd+1,rd+m+1,cmp);
	for(int i = 1;i<=n;i++) conc[i] = i;
	//c[i][j] 城j到乡i最小花费 
	for(int i = 1;i<=m;i++)
	{
		conc[rd[i].u] = find(rd[i].u);
		conc[rd[i].v] = find(rd[i].v);
//		for(int j = 1;j<=n;j++) cout<<conc[j]<<' ';
//		cout<<endl;
		
		if(conc[rd[i].u]==conc[rd[i].v]) continue;
		else
		{
			conc[conc[rd[i].u]] = conc[rd[i].v];
			ans += rd[i].w;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
4 6 0
1 2 1
1 3 1
1 4 1
2 3 1
2 4 1
3 4 1

*/
