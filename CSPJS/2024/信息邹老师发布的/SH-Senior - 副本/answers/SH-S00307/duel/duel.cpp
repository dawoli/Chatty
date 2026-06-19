#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,r[N];
int cnt=0;

int main()
{
	freopen("duel.in","r",stdin);//***
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)	cin >> r[i];
	sort(r+1,r+n+1);
	int minn=1;
	for(int duel=1;duel<=n;duel++)
	{
		if(r[minn] < r[duel])
		{
			cnt++;
			minn++;
		}
	}
	cout << n-cnt << endl;
	return 0;
}

