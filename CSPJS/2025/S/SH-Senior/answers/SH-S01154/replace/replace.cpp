#include <bits/stdc++.h>

using namespace std;


const int MaxN = 2*1e5;
int n,q;
string a[MaxN][4];
string asks[MaxN][1];

void solve(string s, string  ss)
{
	
	int ans = 0;
	for(int i =0 ; i < s.length(); i++)
	{
		for(int j = 1; j <= n; j++)
		{
			string target = a[j][1];
			string replace = a[j][2];
			if(s[i] == target[0])
			{
				bool success = true;
				for(int k = 1; k < target.length(); k++)
				{
					if(target[k] != s[i+k])success = false;
				}
				if(success)
				{
					string news="";
//					cout << "x from" << 0 << "to"<<i<<"\n";
					string x=s.substr(0,i);
					string z = s.substr(i+target.length(),s.length()-1);
					news += x;
//					cout << x << "+"<<replace<<"+"<<z<<"\n";
					news= x+replace+z;
					
//					cout << "Æ´³öÁË£º"<<news << "\n";
					if(news==ss)
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	
	
	return;
}


int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	scanf("%d%d",&n,&q);
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i][1]>>a[i][2];
	}
	for(int i = 1; i <= q; i++)
	{
		cin >> asks[i][1]>>asks[i][2];
		solve(asks[i][1],asks[i][2]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
