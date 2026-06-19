#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;

int a[N];

int main(){
	freopen("duel4.in","r",stdin);
	freopen("duel4.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int k=1,ans=n;
	for(int i=2;i<=n;i++){
		if(a[i]>a[k])ans--,k++;
	} 
	cout<<ans<<'\n';
	return 0;
} 
