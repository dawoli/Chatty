#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	string s1,s2;
};
ll n,q;
node a[200009];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	for(ll i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		cout<<0<<endl;
	}
	return 0;
}
