#include<bits/stdc++.h>
using namespace std;

vector<int> vtr;

const int N=1e2+5;

int st[N];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int h,l,ans,hans,lans,pl;
	cin>>h>>l; 
	for(int i=1;i<=h*l;i++)
	{
		cin>>st[i];
	}
	ans=st[1];
	sort(st+1,st+h*l+1);
//	for(int i=h*l;i>=1;i--)
//	{
//		cout<<st[i]<<' ';
//	}	
//	cout<<'\n';
	for(int i=h*l;i>=1;i--)
	{
		if(st[i]==ans)
		{
			hans=h*l-i+1;
			lans=h*l-i+1;
			break;
		}
	}
//	cout<<hans<<'\n';
	if(lans%h==0)
	{
		cout<<lans/h;
		pl=lans/h;
	}
	else
	{
		cout<<lans/h+1;
		pl=lans/h+1;
	}
	cout<<' ';
	if(hans%h==0&&pl%2==0)
	{
		cout<<1;
	}
	else if(hans%h==0&&pl%2)
	{
		cout<<h;
	}
	else if(pl%2)////pl%2==0ÔòÎªµ¹Ðò 
	{
		cout<<hans%h;
	}
	else
	{
		cout<<h+1-hans%h;
	}

	fclose(stdin);
	fclose(stdout);		
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92

3 4
1 2 3 4 5 6 7 8 9 10 11 12

3 4
5 1 2 3 4 6 7 8 9 10 11 12
*/
