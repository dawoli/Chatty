#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string,string> PSS;
const ll N=2e5+9;
ll n,q,num1[N],num2[N],sz[N];
char c[N];
map<PSS,ll> Rep;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int j=1;j<=n;j++){
		string Str1,Str2;
		cin>>Str1>>Str2;
		PSS P=make_pair(Str1,Str2);
		Rep[P]++;
		ll mn=1e18,mx=-1;
		for(ll i=0;i<min(Str1.size(),Str2.size());i++)
			if(Str1[i]!=Str2[i]){
				mn=min(mn,i);
				mx=max(mx,i);
			}
		num1[j]=mn,num2[j]=mx;
		if(mn<Str1.size()) c[j]=Str1[mn];
		sz[j]=Str1.size();
	}
	while(q--){
		string Ques1,Ques2;
		cin>>Ques1>>Ques2;
		if(Ques1.size()!=Ques2.size()){
			cout<<"0\n";
			continue;
		}
		ll mn=1e18,mx=-1;
		for(ll i=0;i<min(Ques1.size(),Ques2.size());i++)
			if(Ques1[i]!=Ques2[i]){
				mn=min(mn,i);
				mx=max(mx,i);
			} 
		if(Ques1.size()>1000){
			ll res=0;
			for(int i=1;i<=n;i++)
				if(num1[i]<=mn&&(sz[i]-num2[i]<=Ques1.size()-mx)&&mx-mn==num2[i]-num1[i]){
					if(c[i]==Ques1[mn]) res++; 
				}
			cout<<res<<endl;
			continue;
		}
		ll ans=0;
		string Str1="",Str2="";
		for(ll i=0;i<=mn;i++){
			Str1="";Str2="";
			for(ll j=i;j<=mx;j++){
				Str1+=Ques1[j];
				Str2+=Ques2[j];
			}
			ans+=Rep[make_pair(Str1,Str2)];
			for(ll j=mx+1;j<Ques1.size();j++){
				Str1+=Ques1[j];
				Str2+=Ques2[j];
				ans+=Rep[make_pair(Str1,Str2)];
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
}

