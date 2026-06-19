#include<bits/stdc++.h>
using namespace std;
int n,r[100005],ans=0,t=1,i;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++)cin>>r[i];
	sort(r,r+n);
	for(i=0;i<n;i++){
	    if(r[i]==r[i+1])while(r[i+t]==r[i])t++;
	    if(ans<t)ans=t;
	    i+=t-1;
		t=1;
	}
	cout<<ans;
	return 0;
}
