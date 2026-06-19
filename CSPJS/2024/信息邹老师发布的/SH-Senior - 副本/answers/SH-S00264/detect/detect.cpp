#include<bits/stdc++.h>
using namespace std;

struct car{
	int d;
	int v;
	int a;
};

double vm(int v,int a,int s){
	return sqrt(v*v+2*a*s);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	int T;cin>>T;
	while(T!=0){
		int ans=0;
		int n,m,L;
		double V;
		int p[100005];//p[i] the i-th
		int num[100005]={0};//num[i] the i-th
		car c[100005];
	
		cin>>n>>m>>L>>V;
		for(int i=0;i<n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
		}
		for(int i=0;i<m;i++){
			cin>>p[i];
		}
	
		//warning:p can be "0",so remember deal with cars enter while there's no p after
		int vis[1000005];//vis[i] i distance->vis[i]-th p,10^6
		int a=0;
		for(int i=0;i<=p[m-1];i++){
			if(i<=p[a]) vis[i]=a;
			else{
				a++;
				vis[i]=a;
			}
		}
		
		//display
	//	for(int i=0;i<n;i++){
	//		cout<<c[i].d<<" "<<c[i].v<<" "<<c[i].a<<" "<<endl;
	//	}
	//	for(int i=0;i<=p[m-1];i++){
	//		cout<<vis[i]<<" ";
	//	}
		
		for(int i=0;i<n;i++){
			int s=0;
			
			if(c[i].a>=0){
				if(c[i].d<=p[m-1]){//have m after
					s=p[m-1]-c[i].d;
					if(vm(c[i].v,c[i].a,s)>V){//overspeed
						ans++;
						num[m-1]++;
					}
				}
			}
			
			if(c[i].a<0){
				if(c[i].v>V){//have oppotunity overspeed
					if(c[i].d<=p[m-1]){//have m after
						s=p[vis[c[i].d]]-c[i].d;
						if(vm(c[i].v,c[i].a,s)>V){//overspeed
							ans++;
							num[vis[c[i].d]]++;
						}
					}
				}
			}
		}
		int asw=0;
		for(int i=0;i<m;i++){
			if(num[i]==0) asw++;
		}
		cout<<ans<<" "<<asw<<endl;
		T--;
	}
	return 0;
}
