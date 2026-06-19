#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=1e6+5;
const int MAXK=10;
struct node{
	int u,v,w;
};

struct bin{
	int fa[MAXN+MAXK];
	int mem[MAXN+MAXK];
	bin(){
		for(int i=0;i<MAXN;i++){
			fa[i]=i;
			mem[i]=1;
		}
	};
	int find(int x){
		if(fa[x]==x){
			return x;
		}
		fa[x]=find(fa[x]);
		mem[x]=mem[fa[x]];
		return fa[x];
	}
	bool uni(int x,int y){
		if(find(x)!=find(y)){
			mem[fa[y]]+=mem[fa[x]];
			fa[fa[x]]=y;
			return true;
		}
		if(find(x)==find(y)){
			return false;
		}
		return false;
	}
};
struct cmd{
	bool operator ()(const node &a,const node &b){return a.w>b.w;}
};
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    
    //cout<<"vision:0.2"<<endl;
    int lixian[MAXM][3];
    priority_queue<node,vector<node>,cmd>roads;
    
    int bk[MAXK][MAXN];
    int wk[MAXK];
    
    for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		lixian[i][0]=u;
		lixian[i][1]=v;
		lixian[i][2]=w;
	}
	
	for(int i=0;i<k;i++){
		cin>>wk[i];
		for(int j=1;j<=n;j++){
			cin>>bk[i][j];
		}
	}
	long long true_ans=0x7fffffffffffffff;
	for(int bit=0;bit<(1<<k);bit++){
		
	bin b;
	
	for(int i=0;i<m;i++){
		int uu,vv,ww;
		uu=lixian[i][0]+1;
		vv=lixian[i][1]+1;
		ww=lixian[i][2]+1;
		roads.push({uu-1,vv-1,ww-1});
	}
	long long ans=0;
	for(int i=0;i<k;i++){
		
		if((bit>>i)&1){
			ans+=wk[i];
			for(int j=1;j<=n;j++){
				roads.push({j,i+n+1,bk[i][j]});
			}
		}
	}
	
	
	while(!roads.empty()){
		node r;
		r=roads.top();
		roads.pop();
		//cout<<r.w<<","<<r.u<<" "<<r.v<<"|"<<b.find(r.u)<<" "<<b.find(r.v)<<" =>";
		if(b.uni(r.u,r.v)){
			ans+=r.w;
			if(b.mem[r.v]==n){
				break;
			}
			/*
			cout<<b.find(r.u)<<" "<<b.find(r.v)<<"|";
			for(int i=1;i<=n;i++){
				cout<<b.fa[i]<<" ";
			}
			cout<<"|";
			for(int i=1;i<=n;i++){
				cout<<b.mem[i]<<" ";
			}
			cout<<endl;
			*/
			
		}
		else{
			//cout<<"in the same road system"<<endl;
		}
	}
	true_ans=min(true_ans,ans);
	//cout<<endl<<endl;
	}
	
	cout<<true_ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
