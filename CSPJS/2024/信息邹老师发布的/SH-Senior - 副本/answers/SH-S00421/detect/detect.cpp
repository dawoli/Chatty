#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T>0)
	{
		int n,m,L,V;
		int d[100000],v[100000],a,c[100000];
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a;
		for(int i=1;i<=m;i++) cin>>c[i];
		int js=0;
		bool b=false;
		for(int k=1;k<=n;k++){
			if(v[k]>V){
				b=true;
				js++;
				if(c[m]<d[k]){
					js--;
				}
			}
		}
		if(!b) cout<<"0 "<<m<<"\n";
		else cout<<js<<" "<<m-1<<" \n";
		T--;
	}
}
