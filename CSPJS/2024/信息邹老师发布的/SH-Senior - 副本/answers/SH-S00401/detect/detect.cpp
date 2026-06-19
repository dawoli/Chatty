#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,L;
double V;
int d[100005],v[100005],a[100005],res1,res2;
int p[100005];
int u[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int q=0;q<T;q++){
		res1=0,res2=0; 
		cin>>n>>m>>L>>V;
		for(int i=0;i<n;i++){
			cin>>d[i]>>v[i]>>a[i];}
		for(int i=0;i<m;i++){
			cin>>p[i];u[i]=0;}
		for(int i=0;i<n;i++){
			int st=-1,ed=m-1;
			if(a[i]<0){
				for(int j=0;j<m;j++){
					if(p[j]<d[i]){continue;}
					double TV=sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]));
					if(TV>V&&st==-1){st=j;res1++;continue;}
					if(TV<=V&&ed==m-1){ed=j;break;}}}
			if(a[i]>=0){
				for(int j=0;j<m;j++){
					if(p[j]<d[i]){continue;}
					double TV=sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]));
					if(TV>V&&st==-1){st=j;res1++;break;}}}
			for(int j=st;j<=ed;j++){
					if(u[j]==1){break;}
					if(j==ed){
						if(a[i]<0){u[st]=1;}
						if(a[i]>=0){u[ed]=1;}}}}
		for(int i=0;i<m;i++){
			res2+=u[i];}
		cout<<res1<<' '<<m-res2<<endl;}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
