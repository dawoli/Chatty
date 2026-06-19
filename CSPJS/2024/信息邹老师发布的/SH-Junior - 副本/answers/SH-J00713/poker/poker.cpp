#include<iostream>
#include<map>
using namespace std;
map<string,bool> a;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,cnt=0;
	string s;
	cin>>n;
	while(n--)
	{
		cin>>s;
		if(a[s]==0) cnt++;
		a[s]=1;
	}
	cout<<52-cnt<<'\n';
	return 0;
}
