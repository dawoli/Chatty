#include <iostream>
using namespace std;
string b[52];
bool check(string a)
{
	for(int i=0;i<52;i++)
	{
		if(b[i]==a)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n,cnt=0;
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		string a;
		cin >> a;
		if(check(a))
		{
			b[cnt]=a;
			cnt++;
		}
	}
	cout <<52-cnt;
}
