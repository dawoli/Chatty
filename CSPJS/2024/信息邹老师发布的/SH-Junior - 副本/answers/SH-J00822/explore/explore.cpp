#include<bits/stdc++.h>

using namespace std;

int maplist[1500][1500]; 
int T,n,m,k;
int posx,posy,d,nums;
bool check(int x,int y)
{
	if(x > 0 && x <= n && y > 0 && y <= m)
	{
		int f = maplist[x][y];
		if(f == 1)
		{
			return false; 
		}
		if(f == 2)
		{
			return true; 
		} 
		nums++; 
		return true; 
	}
	return false; 
} 
void Function()
{
    memset(maplist,0,sizeof(maplist));
	cin >> n >> m >> k >> posx >> posy >> d; 
	//maplist[posx][posy] = 2; 
	nums = 0; 
	for(int i = 1;i <= n;i ++)
	{
		for(int l = 1;l <= m;l++)
		{
			char t;
			cin >> t;
			switch(t){
				case '.':
					maplist[i][l] = 0;
				    break;
				case 'x':
					maplist[i][l] = 1;
					break; 
			} 			
		} 
	} 
	if(maplist[posx][posy] == 0)
	{
		nums++;
		maplist[posx][posy] = 2;
	} 
	for(int i = 0;i < k;i++)
	{
		int newx;
		int newy;
		switch(d)
		{
			case 0:
				newx = posx;
		        newy = posy + 1;
			   break; 
			case 1:
			    newx = posx + 1;
		        newy = posy;
			   break; 
			case 2:
				newx = posx;
		        newy = posy-1;
			   break; 
			case 3:
				newx = posx - 1;
		        newy = posy;
			   break; 
		}
		if(check(newx,newy))
				{
				 	maplist[newx][newy] = 2;
					posx = newx;
					posy = newy; 
				}
				else
				{
					d = (d+1)%4; 
				} 
	}
	cout << nums << endl; 
} 

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T; 
	for(int i = 0;i < T;i++)
	{
		Function(); 
	} 
	return 0; 
} 
