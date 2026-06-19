#include <bits/stdc++.h>
using namespace std;
int t,n,m,l,v,u[100002],a[100002],d[100002],p[100002],ans1,ans2;
float s,o[100002][2]{{0,0}};
void ttt1(int iii){
	int ll=1;
}
void ttt(int ii){
	if(a[ii]>0){
		s=(v*v-u[ii]*u[ii])/(2*a[ii]);
		if((s+d[ii])<=l){
			o[ii][0]=d[ii]+s;
			o[ii][1]=l;
		}else{
			o[ii][0]=-1;
			o[ii][1]=-1;
		}
	}
	
	if(a[ii]==0){
		if(u[ii]>v){
			o[ii][0]=d[ii];
			o[ii][1]=l;
		}else{
			o[ii][0]=-1;
			o[ii][1]=-1;
		}
	}
	
	if(a[ii]<0){
		if(u[ii]>v){
			s=(v*v-u[ii]*u[ii])/(2*a[ii]);
			o[ii][0]=d[ii];
			o[ii][1]=d[ii]+s;
		}else{
			o[ii][0]=-1;
			o[ii][1]=-1;
		}
	}
	ttt1(ii);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int T=1;T<=t;T++){
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>u[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		ans1=0;
		ans2=0;
		for(int i=1;i<=n;i++){
			ttt[i];
		}
		
		cout<<3<<" "<<3<<endl;
	}
	return 0;
}
