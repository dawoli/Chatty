#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V;
int d[100009],v[100009],a[100009],p[100009];
int from[100009],to[100009];
int wayUp(int vvv,int aaa,int lll){//v,a,limit,v<=limit
	double vv=vvv,aa=aaa,ll=lll;
	double temp=(ll*ll-vv*vv)/(2*aa);
	return int(temp)+1;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int haha=1;haha<=T;haha++){
		n=0;m=0;L=0;V=0;
		cin>>n>>m>>L>>V;
		bool ifa=true,ifb=true,ifc=true;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
//		if(a[i]==0){continue;}
//		if(a[i]>0){
//			if(v[i]>V){
//				from[i]=d[i];to[i]=L;
//			}
//			else{
//				int tim=(V-v[i])/a[i];
//				from[i]=
//			}
//		}
			if(a[i]!=0) ifa=false;
			if(a[i]<0) ifb=false;
			if(a[i]>0) ifc=false;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		if(ifa==true){
			int cnt=0,cut=m-1;
			for(int i=1;i<=n;i++){
				if((d[i]<=p[m])&&(v[i]>V)) cnt++;
			}
			if(cnt==0) cut++;
			cout<<cnt<<" "<<cut<<endl;
			continue;
		}
		if(ifb==true){
			int cnt=0,cut=m-1;
			for(int i=1;i<=n;i++){
				if(d[i]>p[m]) continue;
				if(v[i]>V){cnt++;continue;}
				if(d[i]+wayUp(v[i],a[i],V)<=p[m]){cnt++;}
			}
			
			if(cnt==0) cut++;
			cout<<cnt<<" "<<cut<<endl;
			continue;
		}
		//----baoli----
//		for(int j=1;j<=m;j++){//point -> j
//			for(int i=1;i<=n;i++){//car -> i
//				if
//			}
//		}
	}
	return 0;
}
