#include <iostream>
#include <ciostd>
#include <string>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	int a=0;
	string cards[55];
	for(int i=1;i<=n;i++)
	{
		cin >> cards[i];
		for(int j=2;j<=i;j++)
		{
			if(cards[i][0]==cards[j][0]&&cards[i][1]==cards[j][1])
			{
				a++;	
			}
		}
	}
	cout << 52-a;
	return 0;	
}
