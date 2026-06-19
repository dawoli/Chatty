#include<bits/stdc++.h>
using namespace std;
int a[60];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string s,e,T[60]={"","DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK","CA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK","HA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK","SA"};int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{    
	    cin>>s;
		for(int j=1;j<=52;j++)
		{
			if(s==T[j])a[j]=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=52;i++)
	{
		if(!a[i])cnt++;
	}
	cout<<cnt;
	return 0;
}

