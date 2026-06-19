#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<ll,ll>
const ll N=1e5+5;
struct node{ll a,b,c;}s[N],str[N];
ll n;
vector<PII>ss;
bool cmp(PII u,PII v){
	return min(u.first,u.second)<min(v.first,v.second);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	ll t;cin>>t;
	while(t--){
		cin>>n;
		memset(s,0,sizeof s);
		memset(str,0,sizeof str);
		ss.clear();
		ll cnta=0,cntb=0,cntc=0;
		ll cntab=0,cntbc=0,cntac=0;
		for(ll i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			ll maxx=max(s[i].a,max(s[i].b,s[i].c));
			if(s[i].a>s[i].b&&s[i].a>s[i].c)cnta++;
			else if(s[i].b>s[i].a&&s[i].b>s[i].c)cntb++;
			else if(s[i].c>s[i].b&&s[i].c>s[i].a)cntc++;
			else if(s[i].b==s[i].a&&s[i].b>s[i].c)cntb++,cnta++,cntab++;
			else if(s[i].c==s[i].b&&s[i].c>s[i].a)cntc++,cntb++,cntbc++;
			else if(s[i].c==s[i].a&&s[i].c>s[i].b)cnta++,cntc++,cntac++;
			str[i].a=s[i].a-maxx,str[i].b=s[i].b-maxx,str[i].c=s[i].c-maxx;
		}
		ll ans=0;
		if(cnta<=n/2&&cntb<=n/2&&cntc<=n/2){
			for(ll i=1;i<=n;i++)ans+=max(s[i].a,max(s[i].b,s[i].c));
			cout<<ans<<endl;
			continue;
		}
		else if(cntb<=n/2&&(((cnta-cntac)<=n/2)&&((cntc-cntac)<=n/2)&&(n/2-cnta+cntac)+(n/2-cntc+cntac)>=cntac)){
			for(ll i=1;i<=n;i++)ans+=max(s[i].a,max(s[i].b,s[i].c));
			cout<<ans<<endl;
			continue;
		}
		else if(cnta<=n/2&&(((cntb-cntbc)<=n/2)&&((cntc-cntbc)<=n/2)&&(n/2-cntb+cntbc)+(n/2-cntc+cntbc)>=cntbc)){
			for(ll i=1;i<=n;i++)ans+=max(s[i].a,max(s[i].b,s[i].c));
			cout<<ans<<endl;
			continue;
		}
		else if(cntc<=n/2&&(((cnta-cntab)<=n/2)&&((cntb-cntab)<=n/2)&&(n/2-cnta+cntab)+(n/2-cntb+cntab)>=cntab)){
			for(ll i=1;i<=n;i++)ans+=max(s[i].a,max(s[i].b,s[i].c));
			cout<<ans<<endl;
			continue;
		}
		else{
			ll ccnta=0,ccntb=0,ccntc=0;
			if(cnta>n/2){
				ccnta=cnta;
				ccntb=cntb-cntab,ccntc=cntc-cntac;
				for(ll i=1;i<=n;i++){
					if(str[i].a==0){
						PII x;x.first=abs(str[i].b);x.second=abs(str[i].c);
						ss.push_back(x);
					}
				}
				sort(ss.begin(),ss.end(),cmp);
				for(ll i=0;i<cnta;i++){
					if(ss[i].first<ss[i].second)ccntb++,ans-=ss[i].first;
					else ccntc++,ans-=ss[i].second;
					ccnta--;
					if(ccnta<=n/2)break;
				}
				for(ll i=1;i<=n;i++)ans+=max(s[i].a,max(s[i].b,s[i].c));
				cout<<ans<<endl;
				continue;
			}
			if(cntb>n/2){
				ccntb=cntb;
				ccnta=cnta-cntab,ccntc=cntc-cntbc;
				for(ll i=1;i<=n;i++){
					if(str[i].b==0){
						PII x;x.first=abs(str[i].a);x.second=abs(str[i].c);
						ss.push_back(x);
					}
				}
				sort(ss.begin(),ss.end(),cmp);
				for(ll i=0;i<cntb;i++){
					if(ss[i].first<ss[i].second)ccnta++,ans-=ss[i].first;
					else ccntc++,ans-=ss[i].second;
					ccntb--;
					if(ccntb<=n/2)break;
				}
				for(ll i=1;i<=n;i++)ans+=max(s[i].b,max(s[i].a,s[i].c));
				cout<<ans<<endl;
				continue;
			} 
			if(cntc>n/2){
				ccntc=cntc;
				ccntb=cntb-cntbc,ccnta=cnta-cntac;
				for(ll i=1;i<=n;i++){
					if(str[i].c==0){
						PII x;x.first=abs(str[i].b);x.second=abs(str[i].a);
						ss.push_back(x);
					}
				}
				sort(ss.begin(),ss.end(),cmp);
				for(ll i=0;i<cntc;i++){
					if(ss[i].first<ss[i].second)ccntb++,ans-=ss[i].first;
					else ccnta++,ans-=ss[i].second;
					ccntc--;
					if(ccntc<=n/2)break;
				}
				for(ll i=1;i<=n;i++)ans+=max(s[i].a,max(s[i].b,s[i].c));
				cout<<ans<<endl;
				continue;
			}
		}
	}
	return 0;
}
