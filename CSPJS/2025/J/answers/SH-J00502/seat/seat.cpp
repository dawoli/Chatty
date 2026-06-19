#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m,k;
pair<int,int> work(int v1)
{
	int w1=v1/m,w2=v1%m;
//	cout<<w1<<" "<<w2<<endl;
	if(w1%2==0) return make_pair(w1+1,w2+1);
	return make_pair(w1+1,m-w2);
}
pair<int,int> ans;
int cnt=0;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>k;
	n*=m; n--;
	while(n--)
	{
		int a;
		cin>>a;
		cnt+= a>k;
	}
//	cout<<cnt<<endl;
	ans=work(cnt);
	cout<<ans.first<<" "<<ans.second<<endl;
	return 0;
}
