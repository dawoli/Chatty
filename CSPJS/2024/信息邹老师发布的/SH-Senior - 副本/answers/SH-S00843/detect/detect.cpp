#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
const double S = 0.0000000001;
struct car{
	int d,v,a;
};
struct Node{
	double l,r;
	int pl,pr;
	int flag;
};
int n,m,ml,mv;
car c[N];
Node node[N];
int p[N];

bool cmp1(Node a , Node b)
{
	if(a.l == b.l) return a.r < b.r;
	return a.l < b.l;
}

bool cmp2(Node a , Node b)
{
	if(a.r == b.r) return a.l > b.l;
	return a.r > b.r;
}

bool cmp3(Node a , Node b)
{
	if(a.pr == b.pr) return a.pl < b.pl;
	return a.pr < b.pr;
}

int main()
{
	freopen("detect.in" , "r" , stdin);
	freopen("detect.out " , "w" , stdout);
	int t;
	scanf("%d" , &t);
	while(t--)
	{
		scanf("%d%d%d%d" , &n , &m , &ml , &mv);
		int res1 = 0;
		int res2 = 0;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d%d%d" , &c[i].d , &c[i].v , &c[i].a);
		}
		for(int i = 1;i <= m;i++)
		{
			scanf("%d" , &p[i]);
		}
		sort(p+1 , p+m+1);
		for(int i = 1;i <= n;i++)
		{
			if(c[i].a == 0)
			{
				if(c[i].v > mv)
				{
					if(c[i].d <= p[m]) 
					{
						node[i].flag = 1;
						node[i].l = (double)c[i].d-0.1;
						node[i].r = (double)p[m]+0.1;
					}else
					{
						node[i].flag = 0;
						node[i].l = (double)p[1]-0.1;
						node[i].r = (double)p[m]+0.1;
					}
				}else
				{
					node[i].flag = 0;
					node[i].l = (double)p[1]-0.1;
					node[i].r = (double)p[m]+0.1;
				}
			}
			if(c[i].a > 0)
			{
				int len = ml-c[i].d;
				long long ans = (long long)2*c[i].a*len + (long long)c[i].v * c[i].v;
				double maxv = sqrt(ans);
				if(maxv <= mv)
				{
					node[i].flag = 0;
					node[i].l = (double)p[1]-0.1;
					node[i].r = (double)p[m]+0.1;
				}else
				{
					long long ans = (long long)mv*mv-(long long)c[i].v*c[i].v;
					double num = (double)ans/(2*c[i].a) + double(c[i].d) + S;
					if(num > p[m]) 
					{
						node[i].flag = 0;
						node[i].l = (double)p[1]-0.1;
					}else{
						node[i].flag = 1;
						node[i].l = num;
					}
					node[i].r = (double)p[m]+0.1;
				}
			}
			if(c[i].a < 0)
			{
				if(c[i].v <= mv) 
				{
					node[i].flag = 0;
					node[i].l = (double)p[1]-0.1;
					node[i].r = (double)p[m]+0.1;
				}else{
					node[i].flag = -1;
					node[i].l = (double)c[i].d-0.1;
					long long ans = (long long)c[i].v * c[i].v - (long long)mv*mv;
					node[i].r = min((double)c[i].d + (double)ans/abs(2*c[i].a)-S , double(ml));
				}
			}
		}
		sort(node+1 , node+n+1 , cmp1);
		int x = 1;
		for(int i = 1;i <= n;i++)
		{
			while(p[x] < node[i].l) x++;
			node[i].pl = x;
		}
		int y = m;
		sort(node+1 , node+n+1 , cmp2);
		for(int i = 1;i <= n;i++)
		{
			while(p[y] > node[i].r) y--;
			node[i].pr = y;
		}
		for(int i = 1;i <= n;i++)
		{
			if(node[i].flag == 0) continue;
			if(node[i].flag == 1) res1++;
			if(node[i].flag == -1 && node[i].pl <= node[i].pr) 
			{
				res1++;
				node[i].flag = 1;
			}else if(node[i].flag == -1)
			{
				node[i].flag = 0;
				node[i].pl = 1;
				node[i].pr = m;
			}
		}
		sort(node+1 , node+n+1 , cmp3);
		int cont = 0;
		if(res1 == 0) {
			cout << res1 << ' ' << m << endl;
			continue;
		}
		for(int i = 1;i <= n;i++)
		{
			if(cont < node[i].pl)
			{
				cont = node[i].pr;
				res2++;
			}
		}
		cout << res1 << ' ' << m-res2 << endl;
	}
	return 0;
} 
