#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int num[100010];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,ans = 0;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int x;
		cin >> x;
		num[x]++;
		ans = max(ans,num[x]); 
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
