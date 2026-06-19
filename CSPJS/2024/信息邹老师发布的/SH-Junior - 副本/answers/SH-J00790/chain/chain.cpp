#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	cout << (t%2?0:1) << endl;
	return 0;
}
