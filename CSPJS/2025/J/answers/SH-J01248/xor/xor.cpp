#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5*1e5 + 10;
int num[N] = {};
int n,k;
int er(int x)//将数转化为二进制
{
	stack <int> s;
	int ans = 0;
	while (x!=0)
	{
		s.push(x%2);
		x/=2;
	}
	while (!s.empty())
	{
		ans*=10;
		ans+=s.top();
		s.pop();
	}
	return ans;
 } 
int axor(int a,int b)
{
	if (a == 0||b == 0)
	{
		return a+b;
	}
	int aa = er(a);
	int bb = er(b);
	stack <int> s;
	while (aa!=0&&bb!=0)
	{
		int la = aa%10;
		aa/=10;
		int lb = bb%10;
		bb/=10;
		if ((la == 0&&lb == 1)||(la == 1&&lb == 0))//异或定义：只有一个为1才是1，否则为0 
		{
			s.push(1);
		}
		else
		{
			s.push(0);
		}
	}
	//若a非空，继续输入
	while (aa!=0)
	{
		int la = aa%10;
		aa/=10;
		s.push(la);
	}
	//若b非空，继续输入 
	while (bb!=0)
	{
		int lb = bb%10;
		bb/=10;
		s.push(lb);
	}
	int ans = 0;
	while (!s.empty())
	{
		ans*=10;
		ans+=s.top();
		s.pop();
	}
	queue <int> k;
	while (ans!=0)
	{
		k.push(ans%10);
		ans/=10;
	}
	int aans = 0;
	int cimi = 1;
	while (!k.empty())
	{
		aans+=k.front()*cimi;
		k.pop();
		cimi*=2;
	}
	return aans;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	int ans = 0;
	for (int i=1;i<=n;i++)
	{
		if (num[i] == k)
		{
			ans++;
			num[i] = -1;
			i++;
		}
		int ip = num[i];
		for (int j = i+1;i<=n;j++)
		{
			if (num[j] == -1) break;
			ip = axor(ip,num[j]);
			if (ip == k)
			{
				ans++;
				for (int u=i;u<=j;u++)
				{
					num[u] = -1;
				}
				i = j+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
