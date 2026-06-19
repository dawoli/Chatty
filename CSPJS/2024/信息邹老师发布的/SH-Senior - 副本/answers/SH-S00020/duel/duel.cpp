#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int t[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,mx;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(mx<a)mx=a;
		t[a]++;
	}
	int ans=0;
	for(int i=1;i<=mx;i++)
	    if(ans<t[i])ans=t[i];
	cout<<ans<<endl;
	return 0;
}
