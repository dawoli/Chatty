#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> t;
	while(t--)
	{
		int n,m,l,v,ans = 0,cnt = 0;
		int a[100001],b[100001],c[100001],p[100001];
		int num1[80001],num2[30001];
		memset(num1,-1,sizeof(num1));
		memset(num2,-1,sizeof(num2));
		cin >> n >> m >> l >> v;
		for(int i=0;i<n;i++) cin >> a[i] >> b[i] >> c[i];
		for(int i=0;i<m;i++) cin >> p[i];
		for(int i=0;i<n;i++)
		{
			if(c[i] == 0)
			{
				if(b[i] > v)
				{
					int k = 0,q = 100001,r = 0;
					for(int j=0;j<m;j++)
					{
						if(p[j] >= a[i])
						{
							if(q > j) q = j;
							if(r < j) r = j;
							k = 1;
						}
					}
					if(q != 100001)
					{
						num1[i] = q;
						num2[i] = r;
					}
					if(k == 1) ans++;
				}
			}
			if(c[i] > 0)
			{
				if(b[i] > v)
				{
					int k = 0,q = 100001,r = 0;
					for(int j=0;j<m;j++)
					{
						if(p[j] >= a[i])
						{
							if(q > j) q = j;
							if(r < j) r = j;
							k = 1;
						}
					}
					if(q != 100001)
					{
						num1[i] = q;
						num2[i] = r;
					}
					if(k == 1) ans++;
				}
				if(b[i] == v)
				{
					int k = 0,q = 100001,r = 0;
					for(int j=0;j<m;j++)
					{
						if(p[j] > a[i])
						{
							if(q > j) q = j;
							if(r < j) r = j;
							k = 1;
						}
					}
					if(q != 100001)
					{
						num1[i] = q;
						num2[i] = r;
					}
					if(k == 1) ans++;
				}
				if(b[i] < v)
				{
					float x = float((v*v-b[i]*b[i]))/2/c[i] + a[i];
					int k = 0,q = 100001,r = 0;
					for(int j=0;j<m;j++)
					{
						if(p[j] > x)
						{
							if(q > j) q = j;
							if(r < j) r = j;
							k = 1;
						}
					}
					if(q != 100001)
					{
						num1[i] = q;
						num2[i] = r;
					}
					if(k == 1) ans++;
				}
			}
			if(c[i] < 0)
			{
				if(b[i] > v)
				{
					float x = float((v*v-b[i]*b[i]))/2/c[i] + a[i];
					int k = 0,q = 100001,r = 0;
					for(int j=0;j<m;j++)
					{
						if(p[j] >= a[i] && p[j] < x)
						{
							if(q > j) q = j;
							if(r < j) r = j;
							k = 1;
						}
					}
					if(q != 100001)
					{
						num1[i] = q;
						num2[i] = r;
					}
					if(k == 1) ans++;
				}
			}
		}
		for(int i=0;i<m;i++)
		{
			for(int j=i+1;j<m;j++)
			{
				if(num1[i] >= num1[j] && num2[i] <= num2[j])
				{
					num1[j] = -1;
					num2[j] = -1;
				}
				if(num1[j] >= num1[i] && num2[j] <= num2[i])
				{
					num1[i] = -1;
					num2[i] = -1;
					break;
				}
			}
		}
		for(int i=0;i<m;i++)
		{
			for(int j=i+1;j<m;j++)
			{
				if(num1[i] == -1) break;
				if(num1[j] == -1) continue;
				if(num1[i] <= num1[j] && num1[j] <= num2[i] && num2[i] <= num2[j])
				{
					num1[i] = num1[j];
					num1[j] = -1;
					num2[j] = -1;
					continue;
				}
				if(num2[i] >= num2[j] && num2[j] >= num1[i] && num1[i] >= num1[j])
				{
					num2[i] = num2[j];
					num1[j] = -1;
					num2[j] = -1;
					continue;
				}
			}
		}
		for(int i=0;i<m;i++)
		{
			if(num1[i] != -1) cnt++;
		}
		cout << ans << " " << m-cnt << endl;
	}
	return 0;
} 
