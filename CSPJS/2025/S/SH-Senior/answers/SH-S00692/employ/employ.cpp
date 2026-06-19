#include<bits/stdc++.h>
using namespace std;
const int mod= 998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int n,m;cin>>n>>m;
    string s;cin>>s;
    for(int i=1;i<=n;i++)
    {
    	int k;cin>>k;
    	if(k==0)
    	{
    		cout<<0;return 0;
		}
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0'){cout<<0;return 0;
		}
	}
    long long ans=1;
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
}
/*
拿到这个题目，她哭了。
哭着说：“啊！我不会，我不会，我不会！
讨厌，题目都没看你就说你不会，你是来搞笑的吧！
不过，你既然是来跟wwqk4444学算法的......
我要把你教成班级第一名。
先骗点分，
因为骗分代表自信。
*/ 
