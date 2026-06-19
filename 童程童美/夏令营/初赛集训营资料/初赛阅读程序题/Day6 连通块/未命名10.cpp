#include <iostream>
#include <algorithm>
using namespace std;
int count1(int x)
{
	int re=0;
	while(x)
	{
		if(x%10==1) re++;
		x/=10;
	}
	return re;
}
int main()
{
	int n,sum=0; cin>>n;
	for(int i=1;i<=n;i++)
	{
		sum+=count1(i);
	}
	cout << sum << endl;
	return 0;
}

