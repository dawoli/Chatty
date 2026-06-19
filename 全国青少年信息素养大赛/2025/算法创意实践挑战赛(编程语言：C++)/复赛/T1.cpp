#include<bits/stdc++.h>
using namespace std;
int n;
string s;
struct Move
{
	int x=0,a=1;//a是1朝正，-1朝负
	void W()
	{
		x+=a;
	}
	void S()
	{
		x-=a;
	}
	void AD()
	{
		if(a==1)a=-1;
		else a=1;
	}
}m;
int main()
{
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='W')m.W();
		else if(s[i]=='S')m.S();
		else m.AD();
	}
	cout<<m.x;
	return 0;
}
