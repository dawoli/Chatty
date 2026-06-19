// Problem URL: https://iai.sh.cn/problem/1220
// Finish Time: 2026/5/4 17:15:03 AC
// Finish Time: 2026/5/4 17:09:46 WA
// Start Time: 2026/5/4 16:42:42

#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long int ll;
int n,k,l=1,range,add,start=1;
pair<int,int> pos;
enum Direction { Right,Down,Left,Up };
Direction dir=Right;
auto move(pair<int,int> &pos,const Direction &dir)
{
	switch(dir)
	{
	case Right:pos.x++;break;
	case Down:pos.y++;break;
	case Left:pos.x--;break;
	case Up:pos.y--;break;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	add=n-1;
	while(1)
	{
		range=4*add;
		if(start<=k&&k<=start+range-1)break;
		add-=2;
		start+=range;
		l++;
	}
	//cout<<l<<" "<<range<<" "<<start<<" "<<add<<endl;
	pos={l,l};
	while(start!=k)
	{
		move(pos,dir);
		start++;
		if((dir==Up&&pos.y==l)||(dir==Right&&pos.x==l+add)||(dir==Down&&pos.y==l+add)||(dir==Left&&pos.x==l))
			dir=(Direction)((dir+1)%4);
	}
	cout<<pos.y<<" "<<pos.x;
	return 0;
}