#include<bits/stdc++.h>
using namespace std;

int T;
int n[21],m[21],L[21],V[21];
int d[1000001][21],v[1000001][21],a[1000001][21];
int p[1000001][21];bool bp[1000001][21];
int le[1000001][21],ri[1000001][21];//超速区间 
int sum = 0;//记录高贵的超速车辆数量 
int summ = 0;

void checkIf(int bd,int bv,int ba,int pret,int pred)
{
	if(bv > V[pret] && ba >= 0)
	{
		le[pred][pret] = bd;
		ri[pred][pret] = 0X3f3f3f3f;
		return;
	}
	if(bv <= V[pret] && ba <= 0)
	{
		le[pred][pret] = 0X3f3f3f3f;
		ri[pred][pret] = 0X3f3f3f3f;
		return;
	}
	if(bv > V[pret])
	{
		le[pred][pret] = bd;
		ri[pred][pret] = (V[pret] * V[pret] - bv * bv) / (2 * ba) + le[pred][pret] + 0.99999;
		if(le[pred][pret] > ri[pred][pret])swap(le[pred][pret],ri[pred][pret]);
	}
	if(bv <= V[pret])
	{
		le[pred][pret] = bd + (V[pret] * V[pret] - bv * bv) / (2 * ba) + 0.99999;
		ri[pred][pret] = 0X3f3f3f3f;
		return;
	}
}

int cI(int pret)
{
	int summm = 0;
	for(int i = 0;i < m[pret];i++)//遍历测速器 
	{
		for(int j = 0;j < n[pret];j++)
		{
			if(left[j][pret] < p[i][pret] && ri[j+1][pret] > p[i][pret])
			{
				summm++;
			}
		}//遍历所有车子 
	}
	return summm;
}

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	memset(le,0,sizeof(le));
	memset(ri,0,sizeof(ri));
	memset(p,0,sizeof(p));
	memset(n,0,sizeof(n));
	memset(m,0,sizeof(m));
	memset(L,0,sizeof(L));
	memset(V,0,sizeof(V));
	memset(d,0,sizeof(d));
	memset(v,0,sizeof(v));
	memset(a,0,sizeof(a));
	memset(bp,0,sizeof(bp));
	cin >> T;
	for(int i = 0;i < T;i++)
	{
		cin >> n[i] >> m[i] >> L[i] >> V[i];
		for(int j = 0; j < n[i];j++)
		{
			cin >> d[j][i] >> v[j][i] >> a[j][i];
		}
		for(int j = 0;j < m[i];j++)
		{
			cin >> p[j][i];
		}
		for(int j = 0;j < n[i];j++)
		{
			checkIf(d[j][i],v[j][i],a[j][i],i,j);
		}
	}
	for(int i = 0;i < T;i++)
	{
		for(int j = 0;j < n[i];j++)
		{
			for(int k = 0;k < m[i];k++)
			{
				if(p[k][i] >= le[j][i] && p[k][i] <= ri[j][i])
				{
					sum++;
					break;
				}
			}
		}
		cout << sum << " ";
		summ = cI(i);
		cout << summ << endl;
		sum = 0;
		summ = 0;
	}
	return 0; 
} 
