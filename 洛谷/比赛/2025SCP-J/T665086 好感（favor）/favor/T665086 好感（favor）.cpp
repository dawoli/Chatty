#include<bits/stdc++.h>
using namespace std;
namespace Soaring_Wings
{
	int n;
	void Soar()
	{
		string s;
		cin>>s;
		bitset<1000002> bit(s);
		bool cag;
		unsigned long long cnt[2]={0,0},ans=0;
		for(int i=0;i<n;i++)
		{
			cnt[bit[i]]+=i+1;
		}
		if(cnt[0]>cnt[1])cag=0;
		else cag=1;
		if(bit[0]!=cag)
		{
			ans++;
			bit[0]=cag;
		}
		while(cag?bit.all():bit.none())
		{
			int now;
			for(int i=n-1;i>=0;i--)
			{
				if(bit[i]==cag)
				{

				}
			}
		}
	}
}
int main()
{
	Soaring_Wings::Soar();
	return 0;
}