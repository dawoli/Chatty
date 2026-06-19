#include<iostream>
using namespace std;
string s[60];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int cnt = 0;
	string c;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> c;
		bool f = 0;
		for(int j=0;j<60;j++)
		{
			if(s[j]==c)
			{
				f = 1;
				break;
			}
		}
		if(f==0)
		{
			s[cnt] = c;
			cnt++;
		}
	}
	cout << 52-cnt << endl;
	return 0;
} 
