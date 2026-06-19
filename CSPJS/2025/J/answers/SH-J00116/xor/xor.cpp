#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll a[N];
string s[N];
struct Node{
	ll start,end;
}z[N];
bool cmp(Node x,Node y){
	return x.start<y.start;
}
int main(){
	freopen("xor.in", "r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		while(1){
			if(a[i]%2==1){
				s[i]=s[i]+"1";
			}else{
				s[i]=s[i]+"0";
			}
			a[i]/=2;
			if(a[i]==0){
				break;
			}
		}
		if(s[i][s[i].size()-1]=='0'){
			s[i]+="1";
		}
	}
	ll d=0; 
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			string x=s[i],y;
			for(ll k=i+1;k<=j;k++){
				for(ll h=0;h+1<min(s[k].size(),x.size());h++){
					if(x[h]==s[k][h]){
						y+="0";
					}
					else{
						y+="1";
					}
				}
				string q="";
				if(s[k].size()<=x.size()){
					q=x;
				}else{
					q=s[k];
				}
				for(ll h=min(s[k].size(),x.size())-1;h<q.size();h++){
					if(q[h]=='1'){
						y+="1";
					}else if(q[h]=='0'){
						y+="0";
					}
				}
				x=y;
				y="";
			}
			ll ans=0;
			for(ll k=0;k<x.size();k++){
				ll p=1;
				for(ll h=1;h<=k;h++){
					p*=2;
				}
				ans+=(x[k]-'0')*p;
			}
			if(ans==k){
				d++;
				z[d].start=i;
				z[d].end=j;
			}
		}
	}
	sort(z+1,z+d+1,cmp);
	ll f=d;
	ll t=0;
	d=1;
	ll ans=0;
	while(d<=f){
		if(z[d].start<=t){
			d++;
			continue;
		}
		for(ll i=d;;i++){
			if(z[i].end<z[i+1].end){
				ans++;
				d=i+1;
				t=z[i].end;
				break;
			}
		}
		
	}
	cout<<ans;
	return 0;
}
