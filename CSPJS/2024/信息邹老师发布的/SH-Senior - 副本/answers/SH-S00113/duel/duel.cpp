#include<bits/stdc++.h>
using namespace std;
int n,c[100005],t,lef[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> t;
		c[t]++;
		lef[t]++;
	}
	for(int i=1;i<=100000;i++){
		for(int j=i+1;j<=100000&&c[i]>0;j++){
			int a=min(c[i],lef[j]);
			c[i]-=a;
			lef[j]-=a;
		}
	}
	int ans=0;
	for(int i=1;i<=100000;i++) ans+=c[i];
	cout << ans;
	return 0;
} 
