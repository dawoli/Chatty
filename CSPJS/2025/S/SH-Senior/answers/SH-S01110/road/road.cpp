#include<bits/stdc++.h>
using namespace std;

long long res=LONG_LONG_MAX;
int n,m,k,rn=1,t1,t2,t3;
int f[1100];
struct edge{
	int u,v,d;
};

vector<edge> e;
vector<edge> t;
int vi;

inline int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}



inline bool cmp(edge e1,edge e2){
	return e1.d<=e2.d;
}

long long mintree(int nn){
	long long tres=0;int fin=0;
	for(int i=0;i<=nn+10;i++){
		f[i]=i;
	}
	sort(t.begin(),t.end(),cmp);
	
	
	for(auto i:t){
		if(fin==nn-1)   break;
		int tu=find(i.u),tv=find(i.v);
		if(find(tu)!=find(tv)){
			tres+=i.d;
			f[tu]=tv;
			fin++;
		}
	}
	return tres;
}

void equal(){
	t.clear();
	for(auto i:e){
		t.push_back(i);
	}
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		e.push_back({t1,t2,t3});
	}
	
	equal();
	res=mintree(n);
	
	for(int i=1;i<=k;i++){
		scanf("%d",&vi);
		equal();
		for(int j=1;j<=n;j++){
			scanf("%d",&t2);
			t.push_back({j,n+1,t2});
		}
		res=min(res,mintree(n+1)+vi);
	}
	printf("%d",res);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}





