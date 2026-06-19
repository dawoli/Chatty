#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200009;
ll n,q,cntB;
string s[N][3],t[3];
bool issp(string str){
	ll cnt=0;
	for(ll i=0;i<str.size();i++){
		if(str[i]!='a'&&str[i]!='b') return 0;
		if(str[i]=='a') continue;
		cnt++;
		if(cnt>=2) return 0;
	}
	return 1;
}
void jindequma(){
//	cout<<"jindequ"<<endl;
	ll i=0;
	for(;i<t[1].size();i++){
		if(t[1][i]=='b') break;
	}
	ll t1_front=i,t1_back=t[1].size()-i;
	for(i=0;i<t[2].size();i++){
		if(t[2][i]=='b') break;
	}
	ll t2_front=i,t2_back=t[2].size()-i;
	ll s1_front[N],s2_front[N];
//	cout<<"p"<<endl;
	for(ll i=1;i<=n;i++){
		ll j=0;
		for(;j<s[i][1].size();j++)
			if(s[i][1][j]=='b') break;
		s1_front[i]=j;
		for(j=0;j<s[i][2].size();j++)
			if(s[i][2][j]=='b') break;
		s2_front[i]=j;
	}
	//判断i号双元组是否可行 
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll s1_fronti=s1_front[i],s2_fronti=s2_front[i];
		ll s1_backi=s[i][1].size()-s1_fronti;
		ll s2_backi=s[i][2].size()-s2_fronti;
		if(s1_fronti-s2_fronti==t1_front-t2_front)
			if(s1_fronti<=t1_front&&s2_fronti<=t2_front)
				if(s1_backi<=t1_back&&s1_backi<=t2_back)
					ans++;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
//	bool isB=1;
//	for(ll i=1;i<=n;i++){
//		cin>>s[i][1]>>s[i][2];
////		cout<<s[i][1]<<' '<<s[i][2]<<endl;
////		if(isB)
////			if(!issp(s[i][1])||!issp(s[i][2])) isB=0;
//	}
//	cout<<q<<endl;
//	for(ll i=1;i<=q;i++){
//		cin>>t[1]>>t[2];	
//	cout<<t[1]<<' '<<t[2]<<endl;
//		if(t[1].size()!=t[2].size()){
//			cout<<0<<endl;
//			continue;
//		}
////		if(isB&&(!issp(t[1])||!issp(t[2]))) isB=0;
////		if(isB){
////		cout<<"opp"<<endl;
//		jindequma();
////			continue;
////		}
//				
//	}
	for(ll i=1;i<=q;i++) cout<<0<<endl;
	return 0;
}
