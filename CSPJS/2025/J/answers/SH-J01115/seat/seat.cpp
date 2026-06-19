#include<bits/stdc++.h>
using namespace std;

int n,m;
int cnt,sc,cur;
int ansx,ansy;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cnt = 0;
	cin>>sc;
	for(int i=1;i<=n*m-1;i++)
	{
		cin>>cur;
		if(cur > sc) cnt++;
	}
	
	ansx = (cnt / n) + 1;
	ansy = (cnt % n) + 1;
	
	if(ansx % 2 == 0) ansy = n - ansy + 1;
	
	cout<<ansx<<" "<<ansy;
	
	return 0;
}
