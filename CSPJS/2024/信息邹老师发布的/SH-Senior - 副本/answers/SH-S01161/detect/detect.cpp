#include<bits/stdc++.h>

using namespace std;

const int maxn=1e5+5;
int t;
int n,m,l,v,p[maxn],cnt=0,jz[maxn];
priority_queue<int> q[maxn];

struct node{
	int v,d,a,max;
	bool flag;
}c[maxn];

int curv(int s,int a,int e,int v){
	return pow(v*v+2*a*(e-v),0.5);
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>l>>v;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
			if(c[i].a>0){
				c[i].max=pow(pow(c[i].v,2)+((c[i].a*(l-c[i].d))<<1),0.5);
				if(c[i].max>v)
					c[i].flag=true;
				else
					c[i].flag=false;
			}
				
			else{
				c[i].max=c[i].v;
				if(c[i].max>v)
					c[i].flag=true;
				else
					c[i].flag=false;
			}
		}
		for(int i=1;i<=m;i++)
			cin>>p[i];
		
		for(int i=1;i<=n;i++){
			if(!c[i].flag) continue;
			for(int j=1;j<=m;j++){
				if(p[j]<c[i].d) continue;//weishanglu
				if(curv(c[i].d,c[i].a,p[j],c[i].v)>v){//chaosu
					cnt++;
					for(int k=1;k<=m;k++)
						q[p[k]].push(i);
					jz[i]=m-j+1;
					break;
				}
			}
		}
		cout<<cnt<<" ";
		for(int i=1;i<=m;i++){
			bool falg=true;
			while(!q[p[i]].empty()){
				int x=q[p[i]].top();
				q[p[i]].pop();
				if(jz[x]==1){
					falg=false;
					break;
				}
				
			}
			if(falg) cnt--;
		}
		cout<<cnt<<endl;
		
		
	}
}
