#include<iostream>
using namespace std;
int n,r[100005],emp=0,ans=0,empty;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=r[0];
	for(int i=0;i<n;i++){
		cin>>empty;
		r[empty]++;
		ans=max(ans,r[empty]);
	}
	cout<<ans<<endl;
	return 0;
}
