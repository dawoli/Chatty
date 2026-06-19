#include <iostream>
#include <string>
#include <map>
using namespace std;

int n,ans;
string in;
map<char ,int> color;
map<char ,int> p;
char s[14] = {0,'A','2','3','4','5','6','7','8','9','T','J' ,'Q','K'};
char c[5] = {0 , 'D', 'C','H','S'};

int card[5][14];

void __init()
{
	for(int i = 1;i<=13;i++)
	{
		p[s[i]] = i;
	}

	for(int i = 1;i<=4;i++)
	{
		color[c[i]] = i;
	}
}
int main()
{
	freopen("poker.in" , "r" ,stdin);
	freopen("poker.out" , "w" , stdout);
	cin >> n;
	__init();
	for(int i =1;i<=n;i++)
	{
		cin >> in;
		card[color[in[0]]][p[in[1]]] = 1;
	}

	for(int i =1;i<=4;i++)
	{
		for(int j = 1;j<=13;j++)
		{
			if(!card[i][j]) ans++;
		}
	}

	cout << ans;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
