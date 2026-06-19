#include <bits/stdc++.h>
using namespace std;

const int N=1e5+7;

int T;

int sec(int a1,int a2,int a3)
{
	int sec1;
	if (a1>=a2&&a1>=a3)
		sec1=max(a2,a3);
	else if (a2>=a1&&a2>=a3)
		sec1=max(a1,a3);
	else if (a3>=a2&&a3>=a1)
		sec1=max(a1,a2);
	return sec1;
}

struct node
{
	int a1,a2,a3;
	bool operator<(const node &B) const
	{
		int sec1=sec(a1,a2,a3),sec2=sec(B.a1,B.a2,B.a3);
		return max({a1,a2,a3})-sec1<max({B.a1,B.a2,B.a3})-sec2;
		
	}
}a[N],b1[N],b2[N],b3[N];

void solve()
{
	int n,ans=0,num1=0,num2=0,num3=0;
	cin >> n;
	for (int i=1;i<=n;i++)
		cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
	for (int i=1;i<=n;i++)
	{
		if (a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3)
			num1++,ans+=a[i].a1,b1[num1]={a[i].a1,a[i].a2,a[i].a3};
		else if (a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3)
			num2++,ans+=a[i].a2,b2[num2]={a[i].a1,a[i].a2,a[i].a3};
		else if (a[i].a3>=a[i].a2&&a[i].a3>=a[i].a1)
			num3++,ans+=a[i].a3,b3[num3]={a[i].a1,a[i].a2,a[i].a3};
	}
	if (max({num1,num2,num3})>n/2)
	{
		if (num1>=num2&&num1>=num3)
		{
			sort(b1+1,b1+num1+1);
			for (int i=1;i<=num1-n/2;i++)
				ans-=b1[i].a1-max(b1[i].a2,b1[i].a3);
		}
		if (num2>=num1&&num2>=num3)
		{
			sort(b2+1,b2+num2+1);
			for (int i=1;i<=num2-n/2;i++)
				ans-=b2[i].a2-max(b2[i].a1,b2[i].a3);
		}
		if (num3>=num2&&num3>=num1)
		{
			sort(b3+1,b3+num3+1);
			for (int i=1;i<=num3-n/2;i++)
				ans-=b3[i].a3-max(b3[i].a2,b3[i].a1);
		}
		
	}
	cout << ans << endl;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}
