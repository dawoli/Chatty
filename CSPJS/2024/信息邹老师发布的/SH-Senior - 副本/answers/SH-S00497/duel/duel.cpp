#include<bits/stdc++.h>
using namespace std;
long long a[100005],n,cnt=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int b;
		cin>>b;
		a[b]++;
	}
	for(int i=1;i<=100000;i++)
	{
		if(a[i]==0) continue;
		cnt=max(cnt,a[i]);
	}
	cout<<cnt<<endl;
	return 0;
} 
