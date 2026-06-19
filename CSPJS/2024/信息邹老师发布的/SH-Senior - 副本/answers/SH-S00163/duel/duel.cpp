#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,r[100000],a=0,b=0;
	cin>>n;
	for(int i=0;i<n;i++)cin>>r[i];
	for(int i=0;i<n;i++){
		if(r[n]==1)a++;
		else b++;
	}
	if(a<b) cout<<b<<endl;
	else cout<<a<<endl;
	return 0;
}
