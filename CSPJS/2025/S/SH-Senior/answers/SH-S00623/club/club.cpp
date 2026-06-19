#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+7;
long long T;
struct struc{
	long long a,b,c,w;
} s[N];
long long a[N],b[N],c[N],cnta,cntb,cntc;
bool cmp(long long x,long long y){
	return s[x].w<s[y].w;
}
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cnta=0,cntb=0,cntc=0;
		long long n,ans=0;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			long long temp=max({s[i].a,s[i].b,s[i].c});
			ans+=temp;
			if(temp==s[i].a){
				a[++cnta]=i;
				if(s[i].b>=s[i].c) s[i].w=s[i].a-s[i].b;
				else s[i].w=s[i].a-s[i].c;
			}
			else if(temp==s[i].b){
				b[++cntb]=i;
				if(s[i].a>=s[i].c) s[i].w=s[i].b-s[i].a;
				else s[i].w=s[i].b-s[i].c;
			}
			else{
				c[++cntc]=i;
				if(s[i].a>=s[i].b) s[i].w=s[i].c-s[i].a;
				else s[i].w=s[i].c-s[i].b;
			}
		}
		sort(a+1,a+1+cnta,cmp);
		sort(b+1,b+1+cntb,cmp);
		sort(c+1,c+1+cntc,cmp);
		if(cnta>n/2){
			for(long long i=1;i<=cnta-n/2;i++){
				ans-=s[a[i]].w;
			}
		}
		else if(cntb>n/2){
			for(long long i=1;i<=cntb-n/2;i++){
				ans-=s[b[i]].w;
			}
		}
		else if(cntc>n/2){
			for(long long i=1;i<=cntc-n/2;i++){
				ans-=s[c[i]].w;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
