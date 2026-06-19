#include<bits/stdc++.h>
using namespace std;
int n,r[100005],rr[100005],Rr[100005],top,rmax=-1,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int ri;cin>>ri;
		rmax=max(rmax,ri);
		r[ri]++;
	}
	for(int i=1;i<=rmax;i++){
		if(r[i]){
			Rr[top]=r[i];
			rr[top++]=r[i];
		}
	}
	int i=0,j=1;
	while(j<top){
		if(i==j){
			j++;
			continue;
		}
		if(Rr[j]>rr[i]){
			ans+=rr[i];
			Rr[j]-=rr[i];
			i++;
			continue;
		}else if(Rr[j]==rr[i]){
			ans+=rr[i];
			i++;j++;
			continue;
		}else if(Rr[j]<rr[i]){
			ans+=Rr[j];
			rr[i]-=Rr[j];
			j++;
			continue;
		}
	}
	cout<<n-ans;
	return 0;
}
