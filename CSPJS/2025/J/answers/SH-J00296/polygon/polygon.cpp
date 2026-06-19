#include<bits/stdc++.h>
using namespace std;

int N;
int l[5505];
int cnt;

int search(int lev, int targetOver, int amChose, int currv)
{
	if(lev==targetOver)
	{
		if(currv>l[targetOver]&&amChose>=2) return 1;
		return 0;
	}
	return search(lev+1,targetOver,amChose+1,currv+l[lev])+search(lev+1,targetOver,amChose,currv);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>N;
	for(int i=0;i<N;i++) cin>>l[i];
	sort(l,l+N);
	for(int i=2;i<N;i++)
	{
		cnt+=search(0,i,0,0);
	}
	cout<<cnt;
	return 0;
}
