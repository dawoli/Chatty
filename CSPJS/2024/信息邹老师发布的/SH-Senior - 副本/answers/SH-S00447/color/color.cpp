#include<bits/stdc++.h>
#define ll long long
#define N 200009
#define NUM 1000009
using namespace std;

int T,n;
int a[N];
int last_num[NUM];
int last[N];
ll f[N],jp_f[N]; 

void clear()
{
	for(int i=0;i<=NUM-5;i++)last_num[i]=0;
}

void input()
{
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		last[i]=last_num[a[i]];
		last_num[a[i]]=i;
	}
}

void solve()
{
	f[0]=0;
	jp_f[0]=0;
	//记录 隔开至少一个 获得的C 
	for(int r=1;r<=n;r++)
	{
		//往左匹配
		if(last[r])
		{
			int l=last[r];
			if(r-l>1)//中间隔开了1个数字 
			{
				if(a[r]-(jp_f[r-1]-jp_f[l+1]) > 0) //获得当前数字 比 配对中间小块好 
				{
					f[r]=f[r-1]-(jp_f[r-1]-jp_f[l+1])+a[r];
					//jp_f[r-1]=jp_f[l+1]; 
					jp_f[r]=jp_f[l+1]+a[r]; //中间染同色，不再跳跃配对 
				}
			}
			else  //相邻 
			{
				f[r]=f[r-1]+a[r];
				jp_f[r]=jp_f[r-1];
			}
		}
		else
		{
			jp_f[r]=jp_f[r-1];
			f[r]=f[r-1];
		}
	}
	cout<<f[n]<<endl;
}

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>T;
	while(T--)
	{
		cin>>n;
		clear();
		input();
		solve();
	}
	return 0;
} 
