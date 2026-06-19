#include <bits/stdc++.h>
using namespace std;
int t;
int v[100010],a[100010],d[100010],p[100010];
int n,m,l,V;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int w=1;w<=t;++w){
		bool f2=false,f3=false;
		int cnt=0;
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;++i)
			cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;++i)
			cin>>p[i];
		for(int i=1;i<=n;++i){
			if(a[i]==0){
				if(v[i]>V&&d[i]<=p[m]){
					++cnt;
				}
			}else{
				if(a[i]>0){
					double x=(V*V-v[i]*v[i])/2/a[i];
					x+=d[i];
					if(p[m]>x){
						++cnt;
						f2=true;
					}
				}else{
					int x=(V*V-v[i]*v[i])/2/a[i];
					x+=d[i];
					if(p[1]<x&&p[1]>=d[i]){
						++cnt;
						f3=true;
					}
				}
			}
		}
		cout<<cnt<<" ";
		if(f2&&f3)
			cout<<m-2;
		else
			if(f2||f3)
				cout<<m-1;
			else
				if(cnt)
					cout<<m-1;
				else
					cout<<m;
		cout<<endl;
	} 
	return 0;
}
