#include <bits/stdc++.h>
using namespace std;
int n;
int r[100005];
bool fg = 1;
//
void check_one_two()
{
	for(int i = 1 ; i<=n ; i++)
		if(r[i] != 2 && r[i] != 1) fg = 0;
}
//
bool flag = 1;
void check_num_inr()
{
	sort(r+1,r+n+1);
	for(int i = 2 ; i<=n ; i++)
		if(r[i] == r[i-1]) flag = 0;
}
//
int qwe = 0;
check_ot()
{
	sort(r+1,r+n+1);
	for(int i = 2 ; i<=n ; i++)
	{
		if(r[i] != r[i-1]) qwe++;
	}
	qwe+=1;
}
//
void solve1()
{
	int mo = 0;
	int mt = 0;
	for(int i = 1 ; i<=n ; i++)
	{
		if(r[i] == 1)
		{
			mo++;
		}
		else if(r[i] == 2)
		{
			mt++;
		}
	}
	if(mt >= mo)
	{
		cout<<mt<<endl;
	}
	else if(mo > mt)
	{
		int ans = n;
		ans-=mt;
		cout<<ans<<endl;
	}
}
//
void solve2()
{
	cout<<1<<endl;
}
int ch[100005];
int cn[100005];
void solve3()
{
	int sum = 0;
	sort(r+1,r+n+1);
	for(int i = 1 ; i<=n ; i++) cn[r[i]]++;
	for(int i = 2 ; i<=n ; i++)
	{
		for(int j = 1 ; j<=i ; j++)
		{
			if(ch[r[j]] < cn[r[j]] && r[j] < r[i])
			{
				ch[r[j]]+=1;
				sum++;
				break;
			}
		}
	}
	cout<<n-sum<<endl;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i = 1 ; i<=n ; i++) cin>>r[i];
	check_one_two();
	check_num_inr();
	check_ot();
	if(fg == 1)
	{
		solve1();
		return 0;
    }
	if(qwe == 2)
	{
		solve1();
		return 0;
	}
	if(n <= 10 && flag == 1)
	{
		solve2();
		return 0;
	}
	else if(n <= 10)
	{
		solve3();
		return 0;
	}
	else if(n <= 30)
	{
		solve3();
		return 0;
	}
	else
	{
		solve3();
		return 0;
	}
	
	
	
	return 0;
}
