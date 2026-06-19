#include<bits/stdc++.h>
using namespace std;
long long roadmap[10005][10005];
long weizhia[1000005];
long weizhib[1000005];
long long roadmapbeifen[10005][10005];
long long a[13][10005];
long long c[13];
long n,m,k;
long long primfunc(){
	int answer = 0;
	bool is_used[10005] = {0};
	is_used[0] = true;
	long used[10005];
	vector<long> inrange[2];
	memset(used,sizeof(used),-1);
	memset(inrange,sizeof(inrange),-1);
	used[0] = 0;
	for(int i = 0;i < n;i++)
	{
		if(roadmap[0][i] != 0)
		{
			inrange[0][sizeof(inrange[0])/sizeof(int)-1] = i;
			inrange[1][sizeof(inrange[0])/sizeof(int)-1] = 0;
		}
	}
	for(long i = 1;i < n;i++)
	{
		long long minn = 1000000005;
		long minind = 10005;
		for(int j = 0;j < sizeof(inrange[0])/sizeof(int);j++)
		{
			minn = min(minn,roadmap[inrange[0][j]][inrange[1][j]]);
			if(minn == roadmap[inrange[0][j]][inrange[1][j]])
			{
				minind = inrange[0][j];
			}
		}
		answer += minn;
		used[i] = minind;
		for(int j = 0;j < n;j++)
		{
			if(roadmap[i][j] != 0 && !is_used[j])
			{
				inrange[0][sizeof(inrange[0])/sizeof(int)-1] = j;
				inrange[1][sizeof(inrange[0])/sizeof(int)-1] = i;
			}
		}
	}
	return answer;
}
int main()
{
	memset(roadmapbeifen,sizeof(roadmapbeifen),1000000005);
	//freopen("road1.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(long i = 0;i < m;i++)
	{
		int a,b;
		cin >> a >> b;
		cin >> roadmapbeifen[a][b];
		roadmapbeifen[a][b] = roadmapbeifen[b][a];
		weizhia[i] = a;
		weizhib[i] = b;
	}
	for(long i = 0;i < k;i++)
	{
		cin >> c[i];
		for(long j = 0;j < n;j++)
		{
			cin >> a[i][j];
		}
	}
	long long ans = primfunc();
	for(long i = 0;i < k;i++)
	{
		memset(roadmap,sizeof(roadmap),1000000005);
		for(long j = 0;j < m;j++)
		{
			roadmap[weizhia[j]][weizhib[j]] = min(roadmapbeifen[weizhia[j]][weizhib[j]],a[i][weizhia[j]]+a[i][weizhib[j]]);
		}
		ans = min(primfunc()+c[i],ans);
	}
	cout << ans;
	return 0;
}
