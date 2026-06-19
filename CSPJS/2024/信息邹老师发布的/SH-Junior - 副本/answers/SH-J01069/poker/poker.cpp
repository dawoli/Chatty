#include <iostream>
#include <cstdio>
using namespace std;
int d[14],c[14],h[14],s[14];
const char poke[14] = {'0','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		char p[2];
		cin >> p;
		for(int i = 1;i <= 13;i++)
		{
			if(p[1] == poke[i])
			{
				if(p[0] == 'D')
					d[i]++;
				else if(p[0] == 'C')
					c[i]++;
				else if(p[0] == 'H')
					h[i]++;
				else
					s[i]++; 
			}
		}
	}
	int cnt = 0;
	for(int i = 1;i <= 13;i++)
	{
		if(d[i] == 0)
			cnt++;
		if(c[i] == 0)
			cnt++;
		if(h[i] == 0)
			cnt++;
		if(s[i] == 0)
			cnt++; 
	}
	cout << cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
