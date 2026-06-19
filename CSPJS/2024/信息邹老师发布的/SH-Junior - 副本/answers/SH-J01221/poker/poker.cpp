#include<bits/stdc++.h>
using namespace std;
bool f[50][50];
string a;
int n,res=52;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		if (!f[a[0]][a[1]])
		{
			f[a[0]][a[1]]=1;
			res--;
		}
	}
	cout<<res<<endl;
	return 0;
}
