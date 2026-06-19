#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;

int n;
bool flagA=1,flagB=1;

struct node{
	int a,b,c;
	int ab,ac,bc,id;
}t[N];

bool cmpa(node x,node y){
	return x.a>y.a;
}
bool cmpb2(node x,node y){
	return x.ab>y.ab;
}
bool cmp(node x,node y){
	if(x.id==1&&y.id==1)return x.ac<y.ac;
	if(x.id==1&&y.id==2)return x.ac<y.bc;
	if(x.id==2&&y.id==1)return x.bc<y.ac;
	if(x.id==2&&y.id==2)return x.bc<y.bc;
}

void solve(){
	cin>>n;
	ll ans=0;
	flagA=flagB=true;
	for(int i=1;i<=n;i++){
		cin>>t[i].a>>t[i].b>>t[i].c;
		if(t[i].b!=0)flagA=false;
		if(t[i].c!=0)flagA=flagB=false;
		t[i].ab=t[i].a-t[i].b;
		t[i].ac=t[i].a-t[i].c;
		t[i].bc=t[i].b-t[i].c;
		//cout<<t[i].a<<t[i].b<<t[i].c<<endl;
	}
	if(flagA){
		sort(t+1,t+n+1,cmpa);
		for(int i=1;i<=n/2;i++)ans+=t[i].a;
		cout<<ans<<endl;
		return;
	}
	if(flagB){
		int c1=0;
		sort(t+1,t+n+1,cmpb2);
		for(int i=1;i<=n;i++){
			if(c1<n/2){
				c1++;
				ans+=t[i].a;
			}
			else{
				ans+=t[i].b;
			}
		}
		cout<<ans<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		int c1=0,c2=0,c3=0;
		sort(t+1,t+n+1,cmpb2);
		for(int i=1;i<=n;i++){
			if(t[i].ab>0){
				c1++;
				ans+=t[i].a;
				t[i].id=1;
			}
			else{
				c2++;
				ans+=t[i].b;
				t[i].id=2;
			}
		}
		sort(t+1,t+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(t[i].id==1){
				if(c3==n/2)break;
				if(t[i].ac>0&&c1<=n/2)break;
				c3++;
				c1--;
				t[i].id=3;
				ans-=t[i].ac;
			}
			if(t[i].id==2){
				if(c3==n/2)break;
				if(t[i].bc>0&&c2<=n/2)break;
				c3++;
				c2--;
				t[i].id=3;
				ans-=t[i].bc;
			}
		}
		cout<<ans<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<t[i].a<<" "<<t[i].ab<<" "<<t[i].ac<<" "<<t[i].bc<<" "<<t[i].id<<endl;
//		}
		
		
		return;
	}

	
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}
