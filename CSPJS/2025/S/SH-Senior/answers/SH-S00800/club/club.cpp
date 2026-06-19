#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct aij{
	ll a,b,c;
};
ll t,n,ans,A[200009],B[200009],C[200009];
aij x[200009];

bool cmp1(const aij&a,const aij&b){
	if(a.a>b.a) return 1;
	if(a.a<b.a) return 0;
	if(a.b>b.b) return 1;
	if(a.b<b.b) return 0;
	return a.c>b.c;

}
bool cmp2(ll a,ll b){
	return x[a].a-x[a].b<x[b].a-x[b].b;
}
bool cmp3(ll a,ll b){
	return x[a].b-x[a].a<x[b].b-x[b].a;
}
bool cmpa(ll a,ll b){
	return x[a].a-max(x[a].b,x[a].c)<x[b].a-max(x[b].b,x[b].c);
}
bool cmpb(ll a,ll b){
	return x[a].b-max(x[a].a,x[a].c)<x[b].b-max(x[b].a,x[b].c);
}
bool cmpc(ll a,ll b){
	return x[a].c-max(x[a].a,x[a].b)<x[b].c-max(x[b].a,x[b].b);
}


bool solve(ll n){
	bool ok1=1,ok2=1;
	ans=0;
	for(ll i=1;i<=n;i++){
		cin>>x[i].a>>x[i].b>>x[i].c;
		if(x[i].b||x[i].c)ok1=0;
		if(x[i].c)ok2=0;
	}
	if(ok1){	
	sort(x+1,x+1+n,cmp1);
	for(int i=1;i<=n/2;i++)
		ans+=x[i].a;
		cout<<ans<<endl;
		return 0;
	}
	if(ok2){
		ll ai=0,bi=0,ci=0;
		ll cnta=0,cntb=0;
		for(ll i=1;i<=n;i++){
			if(x[i].a>x[i].b){
				ai++;
				A[ai]=i;
				cnta+=x[i].a;
			}
			else{
				bi++;
				B[bi]=i;
				cntb+=x[i].b;
			}
		}
		if(ai==bi){
			cout<<cnta+cntb<<endl;
			return 0;
		}
		if(ai>bi){
			sort(A+1,A+1+ai,cmp2);
			ll minus=ai-(n/2);
			for(ll i=1;i<=minus;i++){
				cnta-=x[A[i]].a;
				cntb+=x[A[i]].b;
			}
			cout<<cnta+cntb<<endl;
			return 0;
		}
		if(ai<bi){
			sort(B+1,B+1+bi,cmp3);
			ll minus=bi-(n/2);
			for(ll i=1;i<=minus;i++){
				cnta-=x[B[i]].b;
				cntb+=x[B[i]].a;
			}
			cout<<cnta+cntb<<endl;
			return 0;
		}
	}
	ll ai=0,bi=0,ci=0;
	ll cnta=0,cntb=0,cntc=0;
	for(ll i=1;i<=n;i++){
		if(x[i].a>x[i].b&&x[i].a>x[i].c){
			ai++;
			A[ai]=i;
			cnta+=x[i].a;
		}
		else if(x[i].b>x[i].a&&x[i].b>x[i].c){
			bi++;
			B[bi]=i;
			cntb+=x[i].b;
		}
		else {
			ci++;
			C[ci]=i;
			cntc+=x[i].c;
		}
	}
	if(ai<=n/2&&bi<=n/2&&ci<=n/2){
		cout<<cnta+cntb+cntc<<endl;
		return 0;
	}
	if(ai>n/2){
		sort(A+1,A+1+ai,cmpa);
		ll minus=ai-(n/2);
		for(ll i=1;i<=minus;i++){
			cnta-=x[A[i]].a;
			cntb+=max(x[A[i]].b,x[A[i]].c);
		}
		cout<<cnta+cntb+cntc<<endl;
		return 0;
	}
	if(bi>n/2){
		sort(B+1,B+1+bi,cmpb);
		ll minus=bi-(n/2);
		for(ll i=1;i<=minus;i++){
			cnta-=x[B[i]].b;
			cntb+=max(x[B[i]].a,x[B[i]].c);
		}
		cout<<cnta+cntb+cntc<<endl;
		return 0;
	}
	if(ci>n/2){
		sort(C+1,C+1+ci,cmpc);
		ll minus=ci-(n/2);
		for(ll i=1;i<=minus;i++){
			cnta-=x[C[i]].c;
			cntb+=max(x[C[i]].a,x[C[i]].b);
		}
		cout<<cnta+cntb+cntc<<endl;
		return 0;
}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(ll p=1;p<=t;p++){
		cin>>n;
		bool adsfadf=solve(n);
	}
	return 0;
} 
