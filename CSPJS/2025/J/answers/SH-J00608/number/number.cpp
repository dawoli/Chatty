#include<bits/stdc++.h>
using namespace std;

// 他明白 
int nums[10];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++)if(s[i]>='0'&&s[i]<='9')nums[s[i]-'0']++;
    for(int i=9;i>=0; i--)for(int j=1; j<=nums[i]; j++)cout<<i;
    return 0;
}
// 他明白 
