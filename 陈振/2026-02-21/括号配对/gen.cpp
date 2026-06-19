#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
/*__________Functions_________*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1,100);
	uniform_int_distribution<> quot(1,4);
	int i=1;
	while(i)
	{
		i=0;
		int n=dis(gen);
		for(int i=1;i<=n;i++)
		{
			switch(quot(gen))
			{
			case 1:
				cout<<'(';break;
			case 2:
				cout<<')';break;
			case 3:
				cout<<'[';break;
			case 4:
				cout<<']';break;
			}
		}
	}
	return 0;
}