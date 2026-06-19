#include<bits/stdc++.h>
using namespace std;
int r[100001]={0};
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int maxx=0;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		r[t]++;
		if(t>maxx)maxx=t;
	}
	int l=0,ri=n;int ans=n;
	for(int t=1;t<=maxx;t++){
		if(r[t]){
			l+=r[t];ri=min(n-l,ri);
			if(r[t]<ri){
				ans-=r[t];
				ri-=r[t];
			}else{
				ans-=ri;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
