#include <bits/stdc++.h>
using namespace std;
int n,ans,maxr;
int r[100005];
int b[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		maxr=max(maxr,r[i]);
		b[r[i]]++;
	}
	int i=1;
	int lasti=1;
	while(i<=maxr){
		if(b[i]>0&&lasti<i){
			if(b[i]>=b[lasti]){
				ans+=b[lasti];
			}else{
				ans+=b[i];
				b[i]=b[lasti];
			}
			lasti=i;
		}
		i++;
	}
	cout<<n-ans;
	return 0;
}
