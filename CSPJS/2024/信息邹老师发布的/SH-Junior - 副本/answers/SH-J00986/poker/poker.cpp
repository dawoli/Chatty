#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
ll n,ans;
char color,num;
map<pair<char,char>,bool> Poker;
signed main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	if(n==1)
	{
		cout<<51;
		return 0;
	}
	for(ll i=1;i<=n;i++)
	{
		cin>>color>>num;
		Poker[make_pair(color,num)]=1;
	}
	for(ll i=1;i<=13;i++)
	{
		if(i==1)num='A';
		else if(i==10)num='T';
		else if(i==11)num='J';
		else if(i==12)num='Q';
		else if(i==13)num='K';
		else num='0'+i;
		if(Poker[make_pair('D',num)]==0)ans++;
		if(Poker[make_pair('C',num)]==0)ans++;
		if(Poker[make_pair('H',num)]==0)ans++;
		if(Poker[make_pair('S',num)]==0)ans++;
	}
	cout<<ans;
	return 0;
}

