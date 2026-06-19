#include<bits/stdc++.h>
using namespace std;
int n,F,f[100009],b[100009];
struct Node{
	int x,y,z,c;
}a[100009];
bool cmp(Node a1,Node a2){
	return a1.c==F&&a2.c!=F;
}
void solve(){
	cin>>n;
	int cntx=0,cnty=0,cntz=0;
	long long ans=0;
	for(int i=1;i<=n;i++){
		
		cin>>a[i].x>>a[i].y>>a[i].z;
		
		int k=max({a[i].x,a[i].y,a[i].z});
		if(a[i].x==k){
			a[i].c=1;
			cntx++;
		}
		else if(a[i].y==k){
			a[i].c=2;
			cnty++;
		}
		else{
			a[i].c=3;
			cntz++;
		} 
		ans+=k;
	}
	
	int k=max({cntx,cnty,cntz});
	if(k<=n/2){
		cout<<ans<<endl;
		return;
	}
	if(cntx==k)F=1;
	if(cnty==k)F=2;
	if(cntz==k)F=3;
	sort(a+1,a+n+1,cmp);
	k-=n/2;
	if(F==1){
		for(int i=1;i<=cntx;i++)b[i]=a[i].x-max(a[i].y,a[i].z);
		sort(b+1,b+cntx+1);
		for(int i=1;i<=k;i++)ans-=b[i];
	}
	if(F==2){
		for(int i=1;i<=cnty;i++)b[i]=a[i].y-max(a[i].x,a[i].z);
		sort(b+1,b+cnty+1);
		for(int i=1;i<=k;i++)ans-=b[i];
	}
	if(F==3){
		for(int i=1;i<=cntz;i++)b[i]=a[i].z-max(a[i].x,a[i].y);
		sort(b+1,b+cntz+1);
		for(int i=1;i<=k;i++)ans-=b[i];
	}
	cout<<ans<<endl;
	return;
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
