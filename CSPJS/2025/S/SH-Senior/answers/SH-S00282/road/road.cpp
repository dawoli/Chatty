#include<bits/stdc++.h>
using namespace std;
struct xian{
	int a;
	int b;
	int w;
	bool sf;
};
xian x[10001];
int pt[1001][1001]={0};
int np[1001]={0};
int vis[1001]={0};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	int ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int p=0,q=0,w=0;
		cin>>p>>q>>w;
		pt[p][np[p]]=q;
		np[p]++;
		pt[q][np[q]]=p;
		np[q]++;
		x[i].a=min(p,q);
		x[i].b=max(p,q);
		x[i].w=w;
		x[i].sf=false;
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		int s;
		cin>>s;
	}
	int num=n;
	//circle
	while(num!=0){
		int di=1;
		while(di!=0){
			di=0;
			for(int i=1;i<=n;i++){
				if(np[i]==1&&vis[i]==0){
					for(int j=1;j<=m;j++){
						if((x[j].a==i||x[j].b==i)&&x[j].sf==false){
							x[j].sf=true;
							if(x[j].a==i) np[x[j].b]--;
							else np[x[j].a]--;
						}
					}
					vis[i]=1;num--;di++;
				}
			}
		}
		//cout<<"nm"<<num<<endl;
		if(num==0) break;
		
		int mxl=0,mxlw=0;
		for(int i=1;i<=m;i++){
			if(x[i].sf==false&&mxlw<x[i].w){
				mxl=i;mxlw=x[i].w;
			}
		}
		np[x[mxl].a]--;np[x[mxl].b]--;
		x[mxl].sf=true;
		num--;
		ans-=mxlw;
	//\	cout<<"nm"<<num<<"as"<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
