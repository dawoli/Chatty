#include <iostream>
#include <map>
using namespace std;
map<char,int>c12i;
map<char,int>c22i;
bool cnt[105];
void init()
{
	c12i['D']=0;
	c12i['C']=1;
	c12i['H']=2;
	c12i['S']=3;
	c22i['A']=0;
	c22i['2']=1;
	c22i['3']=2;
	c22i['4']=3;
	c22i['5']=4;
	c22i['6']=5;
	c22i['7']=6;
	c22i['8']=7;
	c22i['9']=8;
	c22i['T']=9;
	c22i['J']=10;
	c22i['Q']=11;
	c22i['K']=12;
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	init();
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		char c1,c2;
		cin>>c1>>c2;
		cnt[c12i[c1]*13+c22i[c2]]=true;
	}
	int ans=0;
	for (int i=0;i<=51;i++)
	{
		if (!cnt[i]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
