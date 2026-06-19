#include <iostream>
#include <fstream>
using namespace std;
bool p[5][14];
int get_col(char c)
{
	if(c=='D') return 1;
	if(c=='C') return 2;
	if(c=='H') return 3;
	if(c=='S') return 4;
}
int get_num(char c)
{
	if(c>='2'&&c<='9')
	return (int)(c-'0');
	if(c=='A') return 1;
	if(c=='T') return 10;
	if(c=='J') return 11;
	if(c=='Q') return 12;
	if(c=='K') return 13;
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=0; char c1,c2;
	cin >> n;
	while(n--)
	{
		cin >> c1 >> c2;
		p[get_col(c1)][get_num(c2)]=1;
	}
	for(int i = 1;i <= 4;i ++)
	for(int j = 1;j <= 13;j ++)
	if(!p[i][j]) ans++;
	cout << ans << '\n';
	return 0;
}
