#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
int t;
int cnt[5];
struct stu
{
	int x,y,z;
	int a,b,c;
}f[MAXN];
bool cmp1(stu n,stu m)
{
	return (n.b>m.b)||(n.a>m.a||n.c>m.c);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--)
	{
		for (int i = 1;i<=4;i++) cnt[i]=0;
		int n;
		long long ans = 0;
		cin >> n;
		for (int i = 1;i<=n;i++)
		{
			int x,y,z;
			cin >> f[i].x >> f[i].y >> f[i].z;
			ans += f[i].x;
			cnt[1]++;
			f[i].a = f[i].y-f[i].x;
			f[i].b = f[i].z-f[i].x;
			f[i].c = f[i].z-f[i].x;
		}
		sort(f+1,f+n+1,cmp1);
		for (int i = 1;i<=n;i++)
		{
			//cout << "p:" << f[i].x <<" "<<f[i].y<<" "<<f[i].z << "\n";
			//cout << "l:" << f[i].a <<"    "<<f[i].c<< "\n";
		}
		int k = 1;
		while (cnt[1]>n/2||((f[k].a>0&&cnt[2]+1<n/2)||(f[k].c>0&&cnt[3]+1<n/2)))
		{
			if (f[k].a+f[k+1].c>f[k].c+f[k+1].a&&(f[k].a<f[k].c&&f[k+1].c>f[k+1].a)&&cnt[2]+1<=n/2&&cnt[3]+1<=n/2)
			{
				cnt[2]++;
				cnt[3]++;
				cnt[1]-=2;
				ans += f[k].a + f[k].c;
			}
			else if (f[k].a+f[k+1].c<f[k].c+f[k+1].a&&(f[k].a>f[k].c&&f[k+1].c<f[k+1].a)&&cnt[2]+1<=n/2&&cnt[3]+1<=n/2)
			{
				cnt[2]++;
				cnt[3]++;
				cnt[1]-=2;
				ans += f[k].a + f[k].c;
			}
			else if ((f[k].a>f[k].c)&&cnt[2]+1<=n/2)
			{
				cnt[1]--;
				cnt[2]++;
				ans += f[k].a;
			}
			else if (f[k].c>f[k].a&&cnt[3]+1<=n/2)
			{
				cnt[1]--;
				cnt[3]++;
				ans += f[k].c;
			}
			k++;
		}
		//cout << "//lk " << cnt[1] << " " << cnt[2] << " " << cnt[3] << endl;
		cout << ans << "\n";
	}
	return 0;
} 
