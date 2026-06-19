#include<bits/stdc++.h>
using namespace std;
int n;
struct monster{
	int no;
	int d;
	bool status;
}a[100005];
int r;
bool cmp(monster o,monster p){
	if(o.d!=p.d){
		return o.d<p.d;
	}
	else{
		return o.no<p.no;
	}
}
int find_start(){
	int beg=a[1].d;
	for(int i=2;i<=n;i++){
		if(a[i].d!=beg){
			return i;
		}
	}
	return n;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r;
		a[i].no=i;
		a[i].d=r;
		a[i].status=true;
	}
	sort(a+1,a+1+n,cmp);
	int dl=1;
	for(int i=find_start();i<=n;i++){
		if(a[dl].d<a[i].d&&a[dl].status==true){
			a[dl].status=false;
			dl++;
		}
		else{
			dl++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i].status==true){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
