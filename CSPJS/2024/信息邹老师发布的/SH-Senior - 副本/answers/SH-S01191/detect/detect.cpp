#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;
int n,m,L,V,p[MAXN];

struct node{
	int d,v,a;
}c[MAXN];

void biu(){
	int ans=0;	bool flag=false;
	for(int i=1;i<=n;i++){
		if(c[i].a==0){
			if(c[i].v>V){
				if(c[i].d>p[m])	continue;
				ans++;
				flag=true;
			}
		}
		else{
			if(c[i].v>V){
				if(c[i].d>p[m])	continue;
				ans++;
				flag=true;
			}
			else{
				double x=(V*V-c[i].v*c[i].v)/2/c[i].a;
				if(c[i].d+x<L){
					if(c[i].d+x>=p[m])	continue;
					ans++;
					flag=true;
				}
			}
		}
	}
	if(flag!=false)	cout<<ans<<" "<<m-1<<endl;
	else			cout<<ans<<" "<<m<<endl;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>L>>V;
		for(int j=1;j<=n;j++)	cin>>c[j].d>>c[j].v>>c[j].a;
		for(int j=1;j<=m;j++)	cin>>p[j];
		biu();
	}
}
