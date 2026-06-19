#include <bits/stdc++.h>
using namespace std;
int c1[30];
int c2[30];
int c3[30];
int a[1005];
int num[1005][1005];
bool flag[1005];
int n , k;
int cnt;
int maxn = 0;
struct node
{
	int a,b;
};
node v[100005];
bool cmp(node x,node y)
{
	
	return x.b<y.b;
}
void tentotwo1(int a)
{
	int cnt = 0;
	while(a>0)
	{
		cnt++;
		c1[cnt] = a%2;
		a/=2; 
	}
	c1[0] = cnt;
}
void tentotwo2(int a)
{
	int cnt = 0;
	while(a>0)
	{
		cnt++;
		c2[cnt] = a%2;
		a/=2; 
	}
	c2[0] = cnt;
}
//ok;
int yihuo(int a,int b)
{
	memset(c1,0,sizeof(c1));
	memset(c2,0,sizeof(c2));
	memset(c3,0,sizeof(c3));
	if(a==b)
	{
		return 0;
	}
	tentotwo1(a);
	tentotwo2(b);
	c3[0] = max(c1[0],c2[0]);
	for(int i = 1; i <= max(c1[0],c2[0]); i++)
	{
		if(c1[i] ==1&&c2[i]==1)
		{
			c3[i] = 0;
		}
		else
		{
			c3[i] = 1;
		}
	}
	int ans = 0;
	for(int i = c3[0]; i >= 1; i--)
	{
		ans= ans*2+c3[i];
	}
	return ans;
}
//ok; 
void findans()
{
	sort(v+1,v+cnt+1,cmp);
	for(int i = 1; i <= cnt; i++)
	{
		//cout << v[i].a<<" "<<v[i].b<<endl;
	}	
	maxn++;
	int now = v[1].b;
	for(int i = 2; i <= cnt; i++)
	{
		if(v[i].a<= now)
		{
			continue;
		}
		maxn++;
		now = v[i].b;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			num[i][j] =-1;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	//开始挨个异或 
	for(int i = 1; i <= n; i++)
	{
		int now = a[i];
		num[i][i] = now;
		for(int j = i+1; j <=n;j++)
		{
			now = yihuo(now,a[j]);
			num[i][j] = now;
		}
	}
	//ok;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			//cout << num[i][j]<<" ";
			if(num[i][j] == k)
			{
				cnt++;
				v[cnt].a = i;
				v[cnt].b = j;
			}
		}
		//cout << endl;
	}

	findans();
	cout << maxn;
	return 0;
}
