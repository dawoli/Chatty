#include <bits/stdc++.h>
using namespace std;
int n,r[100002],m,ll,rr,w,s,v[100002]{0},k;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	m=n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	w=1;
	s=0;
	while(w<n){
		ll=w;
		k=w;
		w+=w-s;
		w=min(w,n);
		rr=w;
		while(ll>=1&&rr>k){
			if(v[ll]==1){
				ll-=1;
				continue;
			}
			if(r[rr]>r[ll]){
				rr-=1;
				s+=1;
				m-=1;
				v[ll]=1;
			}
			ll-=1;
		}
	}
	cout<<m;
	return 0;
}
