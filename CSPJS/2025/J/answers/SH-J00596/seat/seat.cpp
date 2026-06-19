#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int arr[N];

bool cmp(int abc, int bcd)
{
	return abc > bcd;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int nah, mal;
	cin>>nah>>mal;
	int sc = 0, loc = 0;
	for(int ini = 1; ini <= nah*mal; ini++)
	{
		cin>>arr[ini];
	}
	sc = arr[1];
	sort(arr+1, arr+1+nah*mal, cmp);
	for(int ini = 1; ini <= nah*mal; ini++)
	{
		if(arr[ini] == sc)
		{
			loc = ini;
			break ;
		}
	}
	int ansx = 0, ansy = 0;
	if(loc % nah == 0)
	{
		ansx = loc/nah;
	}
	else
	{
		ansx = loc/nah+1;
	}
	if(ansx % 2 == 1)
	{
		if(loc % nah == 0)
		{
			ansy = nah; 
		}
		else
		{
			ansy = loc % nah;
		}
	}
	else
	{
		ansy = loc % nah + 1;
	}
	cout<<ansx<<' '<<ansy;
	return 0; 
}
