#include <bits/stdc++.h>
using namespace std;

int vis[6][15];//DCHS //A123456789TJQK
const char H[]={'0','D','C','H','S'};
const char N[]={'0','A','2','3','4','5','6','7','8','9','T','J','Q','K'};

int n,ans;
string s;
char a,b;

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	while (n--)
	{
		cin >> s;
		a=s[0];
		b=s[1];
		int num1,num2;
		for (int i=1;i<=4;i++)
			if (H[i]==a)
				num1=i;
		for (int i=1;i<=13;i++)
			if (N[i]==b)
				num2=i;
		vis[num1][num2]=1;
	}
	for (int i=1;i<=4;i++)
		for (int j=1;j<=13;j++)
			ans+=(!vis[i][j]);
	cout << ans << endl;
	return 0;
}
