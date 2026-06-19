#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=20;
ll a[N]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string x;
	cin>>x;
	ll s;
	for(s=0;s<x.size();s++){
		
//		cout<<"Case "<<s<<endl;
		if(x[s]<='9' && x[s]>='0'){
			a[(ll)(x[s]-'0')]++;
		}
	}
	for(s=9;s>=0;s--){
		ll s1;
		for(s1=1;s1<=a[s];s1++){
			cout<<s;
		}
	}
	return 0;
}  
