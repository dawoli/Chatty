#include<bits/stdc++.h>
using namespace std;
int n,r[100009],lst,nw,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	ans=n;
	for(int i=1;i<=n;i++){
		if(r[i]!=r[i+1]){
			nw++;
			if(lst<=nw){
				ans-=lst;
			    lst=nw;
			    nw=0;
			}else{
				ans-=nw;
				nw=0;
			}
		}else{
			nw++;
		}
	}
	cout<<ans;
	return 0;
} 
