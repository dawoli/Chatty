#include <bits/stdc++.h>
using namespace std;
int cnt[10]={6,2,5,5,4,5,6,3,7,6};
int ans,tmp,n,minn=1e9,sum;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	int t;
	cin >> t;
	while (t--)
	{
		ans=0;
		cin >> n;
		if (n<2)
		{
			cout<<-1<<endl;
			continue;
		}
		else if (n<=7)
		{
			for (int i = 1;i<=7;i++)
			{
				if (n==i)cout << i << endl;
			}
		}
		else
		{
			
			n-=7;
			string s;
			s="8";
			for (int i = 1;i<=n/6;i++)
			{
				s='0'+s;
			}
			n%=6;
			for (int i = 1;i<=9;i++)
			{
				if (n==cnt[i])
				{
					s=char(i+'0')+s;
					cout << s << endl;
					break;
				}
			}
		}
	}
	
	fclose(stdin);
	fclose(stdin);
	return 0;
}
