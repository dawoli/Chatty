#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=1000005;
//struct node{int ndst,nded;};
int nddt[M],det[M],T;
void solve(){
	int n,m,L,V,sumde[N]={0},sumcs,dd[N]={0},vv[N]={0},aa[N]={0};
//	for(int i=0;i<M;i++)nddt[i]=0,det[i]=0;
	cin>>n>>m>>L>>V;
	sumcs=n;
	for(int i=1;i<=n;i++)cin>>dd[i]>>vv[i]>>aa[i];
	for(int i=1;i<=m;i++){
//		int xxx;
		cin>>det[i];
//		det[xxx]=i;
	}
//		if(nddt[det[i]])sum--;
	for(int i=1;i<=n;i++){
		int d=dd[i],v=vv[i],a=aa[i],ndst,nded;
		if(a==0){
			if(v>V)
				ndst=d,nded=L;
			else
				ndst=-1,nded=-1;
		}
		else if(a<0){
			if(v<=V) 
				ndst=-1,nded=-1;
			else if(int(floor(d+(V*V-v*v)/(2.0*a)))==d+(V*V-v*v)/(2.0*a))
				nded=min(L,int(floor(d+(V*V-v*v)/(2.0*a)))-1),ndst=d;
			else
				nded=min(L,int(floor(d+(V*V-v*v)/(2.0*a)))),ndst=d;
		}
		else{
			if(v>=V)
				ndst=d,nded=L;
			else if(ceil(d+(V*V-v*v)/(2.0*a))+1<=L &&
					int(floor(d+(V*V-v*v)/(2.0*a)))==d+(V*V-v*v)/(2.0*a))
				ndst=ceil(d+(V*V-v*v)/(2.0*a))+1,nded=L;
			else if(ceil(d+(V*V-v*v)/(2.0*a))+1<=L && int(floor(d+(V*V-v*v)/(2.0*a)))!=d+(V*V-v*v)/(2.0*a))
				ndst=ceil(d+(V*V-v*v)/(2.0*a)),nded=L;
			else
				ndst=-1,nded=-1;
		}
		bool flag=true;
		for(int j=1;j<=m;j++){
			if(det[j]>=ndst&&det[j]<=nded)flag=false,sumde[i]++;
		}
		if(flag)sumcs--;
//		cout<<endl<<i<<":"<<ndst<<" "<<nded<<endl<<endl;
	}
//	for(int i=1;i<=L;i++){
//		if(det[i]&&nddt[i])
//	}
	sort(sumde+1,sumde+1+n);
	
	cout<<sumcs<<" "<<sumde[1]+sumde[2]+sumde[3]<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
		solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
