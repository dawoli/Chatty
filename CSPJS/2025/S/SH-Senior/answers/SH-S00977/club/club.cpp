#include<bits/stdc++.h>
using namespace std;
struct student{
	long long a,b,c;
}s[100005],a[100005],b[100005],c[100005];
long long t,n,cnta,cntb,cntc,cnt,ans,cut[100005];
bool cmpa(student a,student b){
	return a.a>b.a;
}
bool cmpb(student a,student b){
	return a.b>b.b;
}
bool cmpc(student a,student b){
	return a.c>b.c;
}
bool cmp(long long a,long long b){
	return a>b;
}
void solve(){
	ans=0,cnta=0,cntb=0,cntc=0,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b>>s[i].c;
	}
	for(int i=1;i<=n;i++){
		long long m=max(s[i].a,max(s[i].b,s[i].c));
		if(m==s[i].a){
			a[++cnta]=s[i];
		}else if(m==s[i].b){
			b[++cntb]=s[i];
		}else{
			c[++cntc]=s[i];
		}
	}
	for(int i=1;i<=cnta;i++){
		ans+=a[i].a;
	}
	for(int i=1;i<=cntb;i++){
		ans+=b[i].b;
	}
	for(int i=1;i<=cntc;i++){
		ans+=c[i].c;
	}
	if(cnta>n/2){
		cnt=cnta;
		for(int i=1;i<=cnt;i++){
			cut[i]=a[i].a-max(a[i].b,a[i].c);
		}
	}
	if(cntb>n/2){
		cnt=cntb;
		for(int i=1;i<=cnt;i++){
			cut[i]=b[i].b-max(b[i].a,b[i].c);
		}
	}
	if(cntc>n/2){
		cnt=cntc;
		for(int i=1;i<=cnt;i++){
			cut[i]=c[i].c-max(c[i].a,c[i].b);
		}
	}
	if(cnt){
		sort(cut+1,cut+cnt+1,cmp);
		for(int i=n/2+1;i<=cnt;i++){
			ans-=cut[i];
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
