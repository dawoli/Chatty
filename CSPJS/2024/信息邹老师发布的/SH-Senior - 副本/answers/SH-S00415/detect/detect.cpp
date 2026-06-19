#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int a[maxn],d[maxn],v[maxn],p[maxn];
		int n,m,l,V;
		cin>>n>>m>>l>>V;
		for(int i=0;i<n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=0;i<m;i++){
			cin>>p[i];
		}
		if(a[0]==0){
			int s=0;
			for(int i=0;i<n;i++){
				if(v[i]>V && d[i]<=p[m-1]){
					s++;
				}
			}
			if(s==0){
				cout<<0<<' '<<m<<endl;
			}
			else{
				cout<<s<<' '<<m-1<<endl;
			}
		}
		else if(a[0]>0){
			int sum=0;
			for(int i=0;i<n;i++){
				if(d[i]>p[m-1]){
					continue;
				}
				int s=p[m-1]-d[i];
				double v1=sqrt(s*2.0*a[i]*1.0+v[i]*1.0*v[i]*1.0);
				if(v1>V){
					sum++;
				}
			}
			if(sum==0){
				cout<<0<<' '<<m<<endl;
			}
			else{
				cout<<sum<<' '<<m-1<<endl;
			}
		}
	}
} 
