#include<bits/stdc++.h>
using namespace std;
int d[100010],v[100010],a[100010],p[100010];
double s[100010];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,m,L,V,f=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]!=0){
				f=1;
			}
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		if(!f){
			int s=0;
			for(int i=1;i<=n;i++){
				if(v[i]>V){
					s++;
				}
			}
			cout<<s<<" "<<n-1<<"\n";
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					s[i]=v[i]*p[j]+0.5*a[i]*p[i];
				}
			}
		}
	}
	return 0;
}
