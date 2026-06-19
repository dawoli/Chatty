#include<bits/stdc++.h>
using namespace std;
int n,m,l,V;
int v[100009],d[100009],a[100009];
int p[100009];
int T,tmp;
void sa(){
	int ans1=0;
	for(int i=1;i<=n;i++) {
		if(v[i]>V and d[i]<=tmp){ans1++;}
	}
	cout<<ans1<<" ";
	if(ans1) cout<<m-1<<endl;
	else cout<<m<<endl;
	return;
}
void solveb(){
	long long ans1=n;
	for(int i=1;i<=n;i++){
		double x=(pow(V,2)-pow(v[i],2))/2/a[i];
		if(x+d[i]>=tmp){ans1--;}
	}
	cout<<ans1<<" ";
	if(ans1) cout<<m-1<<endl;
	else cout<<m<<endl;
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int t=0;t<T;t++) {
		bool sA=1;
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;i++) {
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=n;i++) {
			if(a[i]!=0){
				sA=0;
				break;
			}
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		tmp=p[m];
		if(sA){
			sa();
		} 
		else solveb();
	}
}
