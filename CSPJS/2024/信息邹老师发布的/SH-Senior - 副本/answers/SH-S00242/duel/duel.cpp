#include<bits/stdc++.h>
using namespace std;
int n,pos=1,a[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) if(a[i]>a[pos]) pos++;
	cout<<n-pos+1<<"\n";
	return 0;
}
