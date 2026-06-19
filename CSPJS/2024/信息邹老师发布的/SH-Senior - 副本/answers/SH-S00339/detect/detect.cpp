#include<bits/stdc++.h>
using namespace std;
double overdis[2][100000];
int dect[100000];
vector<vector<int>> viscar[100000][1];
vector<int> cars;
int maxd ;
int main()
{
	freopen("detect3.in","r",stdin);
	//freopen("detect.out","w",stdout);
	int T = 0;
	cin >> T;
	for(int x = 0;x < T;x++)
	{
		int m,n,L,V;
		cin >> n >> m >> L >> V;
		for(int i = 0;i < n;i++)
		{
			
			int d,v,a;
			cin >> d >> v >> a;
			if(a == 0)
			{
				if(v > V)
				{
					overdis[0][i] = d+1;
					overdis[1][i] = L;
				}
			}else if(a > 0)
			{
				if(v>V)
				{
					overdis[0][i] = d;
					overdis[1][i] = L+1;
				}
				else
				{
					double dis = (V*V-v*v);
					dis /=(2*a);
					if(dis < L)
					{
						overdis[0][i] = dis;
						overdis[1][i] = L+1;
					}
				}
			}else
			{
				if(v>V)
				{
					double dis = (V*V-v*v);
					dis /=(2*a);
					overdis[0][i] = d-1;
					overdis[1][i] = dis;
				}
			}
		}
		for(int i = 0;i < m;i++)
		{
			cin >> dect[i];
			maxd = max(maxd,dect[i]);
		}
		int ans1 = 0;
		for(int i = 0;i < n;i++)
		{
			if(overdis[0][i] <= maxd)
			{
				ans1 ++;
			}
		}
		cout << ans1 << ' ' << m-1 << "\n";
	} 
	return 0;
} 
