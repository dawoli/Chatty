#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V;
int ans1,ans2;
int p[100010];


struct n1{
	int l;
	int r;
	bool fg;
}f[100010];

void find(int d,int v,int a,int i){
	if(a==0){
		if(v<=V){
			f[i].fg=0;
			ans1--;
		}else{
			f[i]=(n1){d,L,1};
		}
	}else{
		if(a>0){
			if(v>V){
				f[i].fg=1;
			}else{
				int x=(V*V-v*v)/2/a+1;
				if(x+d>L){
					f[i].fg=0;
					ans1--;
				}else{
					f[i]=(n1){x+d,L,1};
				}
			}
		}else{
			if(v<V){
				f[i].fg=0;
				ans1--;
			}else{
				int x=ceil((V*V-v*v)/2/a)-1;
				f[i]=(n1){d,d+x,1};
			}
		}
	}
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		ans1=ans2=n;
		for(int i=1;i<=n;i++){
			int d,v,a;
			cin>>d>>v>>a;
			find(d,v,a,i);
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		
		for(int i=1;i<=n;i++){
			if(!f[i].fg) continue;
			bool flag=0;
			for(int j=1;j<=m;j++){
				if(p[j]>=f[i].l&&p[j]<=f[i].r){
					flag=1;
					break;
				}
			}
			if(!flag){
				f[i].fg=0;
				ans1--;
			}
		}
		cout<<ans1<<" ";
		for(int i=1;i<=n;i++){
			if(!f[i].fg) continue;
			for(int j=i+1;j<=n;j++){
				if(!f[j].fg) continue;
				if(f[i].l<=f[j].l&&f[i].r>=f[j].r){
					ans2--;
					f[j].fg=0;
				}
			}
		}
		cout<<ans2<<endl;
	}
	
	
	return 0;
} 
