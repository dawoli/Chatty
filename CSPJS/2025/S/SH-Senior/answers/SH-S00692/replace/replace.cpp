#include<bits/stdc++.h>
using namespace std;
string a[1145][7];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i][1]>>a[i][2];
	}
	for(int err=1;err<=q;err++)
    {
    	string x,y;cin>>x>>y;
    	int ans=0;
    	for(int i=0;i<x.size();i++)
    	{
    		for(int j=1;j<=n;j++)
    		{
    			if(x.substr(i,a[j][1].size())==a[j][1])
    			{
    				string p=x;
    				p.replace(i,a[j][1].size(),a[j][2]);
    				if(p==y)ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
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


