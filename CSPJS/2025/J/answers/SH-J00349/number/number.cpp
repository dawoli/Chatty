#include<bits/stdc++.h>
using namespace std;
const int N=1000007;
int mp[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int l=a.length();
	for(int i=0;i<l;i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			mp[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)if(mp[i]!=0)
	{
		while(mp[i]>0)
		{
			cout<<i;
			mp[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//#Shang4Shan3Ruo6Shui4
