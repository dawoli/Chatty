#include<bits/stdc++.h>
using namespace std;
int n,r[100009],t[100009],da=0,rem=0,cut=0,k;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		t[r[i]]++;
		da=max(da,r[i]);
	}
	da++;
	for(int i=1;i<=da;i++){
		if(t[i]==0) continue;
//		cout<<"Now it's i=="<<i<<" and t=="<<t<<endl;
		if(rem==0){
			rem+=t[i];
		}
		else if(t[i]<=rem){
			cut+=t[i];
		}
		else if(t[i]>rem){
			cut+=rem;
			rem=t[i];
		}
//		cout<<"Now it's cut=="<<cut<<endl;
	}
	k=n-cut;
	cout<<k<<endl;
	return 0;
}
