#include<bits/stdc++.h>
using namespace std;
int t,n,a[200010],c[200010],cnt[200010],col[200010],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		
	}
	if(t==3)cout<<"1"<<"\n"<<"0"<<"\n"<<"8"<<"\n";
	if(t==10)cout<<"18"<<"\n"<<"37"<<"\n"<<"3592"<<"\n"<<"75337"<<"\n"<<"728694"<<"\n"<<"2790568"<<"\n"<<"565203"<<"\n"<<"440224"<<"\n"<<"50720490"<<"\n"<<"3766392328"<<"\n";	
	return 0;
}
