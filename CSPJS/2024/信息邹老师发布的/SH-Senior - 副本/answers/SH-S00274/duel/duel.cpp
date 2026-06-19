#include<bits/stdc++.h>
using namespace std;
int n,r[100010],k[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int i,ma=-1;
	cin>>n;
	for(i=1;i<=n;i++) cin>>r[i];
	for(i=1;i<=n;i++) k[r[i]]++;
	for(i=1;i<=100000;i++) ma=max(ma,k[i]);
	cout<<ma<<endl;
	return 0;
}
