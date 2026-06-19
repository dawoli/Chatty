#include<bits/stdc++.h>
#define N 100099
using namespace std;
int T;
int n,m,L,V,ans1,ans2;
int pos[N];
int mapp[N];
int vis[N];
struct node{
	int d;
	int a;
	int v;
	int start;
	int endd;
}car[N];



int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
    cin>>T;
    for(int gg=1;gg<=T;gg++){
    	ans1=0,ans2=0;
    	cin>>n>>m>>L>>V;
    	for(int i=1;i<=n;i++){
    		cin>>car[i].d>>car[i].v>>car[i].a;
    		if(car[i].v>V and car[i].a>=0){
    			car[i].start=car[i].d;
    			car[i].endd=L+2;
			}
			else if(car[i].v<=V and car[i].a<=0){
				car[i].start=L+1;
				car[i].endd=L+2; 
			}
			else if(car[i].v<V and car[i].a>0){
				double sss=(V*V-car[i].v*car[i].v)/(2*car[i].a);
				car[i].start=car[i].d+int(sss+0.9999);
				car[i].endd=L+2;
			}
			else if(car[i].v>V and car[i].a<0){
				car[i].start=car[i].d;
				double sss=(V*V-car[i].v*car[i].v)/(2*car[i].a);
				car[i].endd=car[i].start+int(sss+0.9999);
			}
			else{
				car[i].start=car[i].d+1;
				car[i].endd=L+2;
			}
		}
		for(int i=1;i<=m;i++){
			cin>>pos[i];
		}
		sort(pos+1,pos+m+1);
		if(car[1].a>0){
		    int x=pos[m];
			for(int i=1;i<=n;i++){
				if(car[i].start<x or(car[i].v>V and car[i].d<=x)){
					ans1++;
				}
			}
			ans2=m-1;
			if(ans1==0) {ans2=m;
			}
			cout<<ans1<<" "<<ans2<<endl;	
		}
		else if(car[1].a==0){
			for(int i=1;i<=n;i++){
				if(car[i].v>V and car[i].d<=pos[m]){
					ans1++;
				}
			}
			ans2=m-1;
			if(ans1==0) {ans2=m;
			}
			cout<<ans1<<" "<<ans2<<endl;	
		}
	}


	return 0;
}

