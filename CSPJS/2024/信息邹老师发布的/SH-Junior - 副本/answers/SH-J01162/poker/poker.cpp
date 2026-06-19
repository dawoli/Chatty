#include <bits/stdc++.h>
using namespace std;
const int N = 60;
int n;
map <string,int> mp;
int main()
{			
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int t = 0;t < n;t++)
	{
		string s;
		cin >> s;
		mp[s]++;
	}
	int ans = 52 - mp.size();
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
