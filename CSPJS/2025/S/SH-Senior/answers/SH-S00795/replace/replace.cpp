#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,ans;
string cha;
struct rep{
	string ru;
	string rv;
	int length;
}a[N];
string gs(string x,int l,int r){
	string sx;
	sx[0]=x[l];
	for(int i=l+1;i<=r;i++){
		sx+=x[i];
	}
	return sx;
}
struct per{
	string rx;
	string ry;
}b[N];
bool same[N];
bool cmp(rep x,rep y){
	return x.length<y.length;
}
string f(string x,int u,int v,string y){
	string sc;
	for(int i=0;i<u;i++){
		sc+=x[i];
	}
	sc+=y;
	for(int i=v+1;i<x.size();i++){
		sc+=x[i];
	}
	return sc;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].ru>>a[i].rv;
		a[i].length=a[i].ru.size();
	} 
	for(int i=1;i<=q;i++){
		cin>>b[i].rx>>b[i].ry;
	}
	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++){
//		for(auto x:a[i].ru){
//			cout<<x;
//		}
//		cout<<" ";
//		for(auto x:a[i].rv){
//			cout<<x;
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		memset(same,1,sizeof same);
		ans=0;
		if(b[i].rx.size()!=b[i].ry.size()){
			cout<<0<<endl;
			continue;
		}
		else{
			int sxi=b[i].rx.size();
			for(int j=0;j<sxi;j++){
				if(b[i].rx[j]!=b[i].ry[j]) same[j]=0;
			}
			int dx,dy,ds;
			for(int j=0;j<sxi;j++){
				if(same[j]==0){
					dx=j;
					break;
				}
			}
			for(int j=sxi-1;j>=0;j--){
				if(same[j]==0){
					dy=j;
					break;
				}
			}
			ds=dy-dx+1;
			for(int j=1;j<=n;j++){
				if(a[j].length<ds){
					continue;
				}
				else if(a[j].length>b[i].rx.size()){
					continue;
				}
				else if(a[j].length==b[i].rx.size()){
					if(a[j].ru==b[i].rx && a[j].rv==b[i].ry){
						ans++;
					}
				}
				else{
					for(int l=0;l+ds-1<b[i].rx.size();l++){
						if(f(b[i].rx,l,l+ds-1,a[j].rv)==b[i].ry && a[j].ru==gs(b[i].rx,l,l+ds-1)){
							ans++;
						}
					}
				} 
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
