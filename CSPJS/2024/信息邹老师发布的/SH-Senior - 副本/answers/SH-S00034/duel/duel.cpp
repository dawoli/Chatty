#include<bits/stdc++.h>
using namespace std;
int n,a[100005],cnt;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	cnt=n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int be_atked=1;
	for(int i=2;i<=n;i++)
		if(a[i]>a[be_atked])
		{
			cnt--;
			be_atked++;
		}
	cout<<cnt<<endl;
	return 0;
}
