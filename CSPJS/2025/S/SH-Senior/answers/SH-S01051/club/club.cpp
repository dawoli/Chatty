#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int a[N],b[N],c[N],ans[N],t,n,anu,bnu,cnu,p;
int count(int d,int e,int a1,int b1,int c1){
	if(d==1&&e<n){
		return max(max(a[e]+count(1,e+1,a1+1,b1,c1),a[e]+count(2,e+1,a1,b1+1,c1)),a[e]+count(3,e+1,a1,b1,c1+1));
	}
	if(d==2&&e<n){
		return max(max(b[e]+count(1,e+1,a1+1,b1,c1),b[e]+count(2,e+1,a1,b1+1,c1)),b[e]+count(3,e+1,a1,b1,c1+1));
	}
	if(d==3&&e<n){
		return max(max(c[e]+count(1,e+1,a1+1,b1,c1),c[e]+count(2,e+1,a1,b1+1,c1)),c[e]+count(3,e+1,a1,b1,c1+1));
	}
	if(d==1&&e==n) return a[e];
	if(d==2&&e==n) return b[e];
	if(d==3&&e==n) return c[e];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		ans[i]=max(max(count(1,1,1,0,0),count(2,1,0,1,0)),count(3,1,0,0,1));
	}
	for(int i=1;i<=t;i++) cout<<ans[i]<<endl;
	return 0;
}
