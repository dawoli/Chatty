#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int nums[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto i:s)if('0'<=i&&i<='9')nums[i-'0']++;
	for(int i=9;i>=0;i--)for(int j=1;j<=nums[i];j++)cout<<i;
	return 0;
}
