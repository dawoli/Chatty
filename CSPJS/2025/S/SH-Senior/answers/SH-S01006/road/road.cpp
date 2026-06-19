#include<bits/stdc++.h>
 using namespace std;
 const int N=1e4+5;
 struct E{
 	int u,v;
 	unsigned long long w;
 };
 vector<E> v;
 int n,m,k,fa[N]; 
 unsigned long long ans;
  bool cmp(E x,E y){
 	return x.w<y.w;
 }
 int find(int x){
 	if(fa[x]==x) return x;
 	return fa[x]=find(fa[x]);
 }
 void merge(int x,int y){
 	fa[find(x)]=find(y);
 }
 int main(){//64pts 
 	freopen("road.in","r",stdin);//-----
 	freopen("road.out","w",stdout);
 	cin>>n>>m>>k;
 	for(int i=1;i<=n;i++) fa[i]=i;
 	for(int i=1;i<=m;i++){
 		int x,y;
 		unsigned long long w;
 		cin>>x>>y>>w;
 		if(x>y) swap(x,y); 
 		v.push_back({x,y,w});
	 }
 	for(int i=1;i<=k;i++){
 		unsigned long long c;
		unsigned long long w[10005]={0};
 		cin>>c;
 		for(int j=1;j<=n;j++)
 			cin>>w[j];
 		for(int j=1;j<=n;j++){
 	 		for(int k=j+1;k<=n;k++){
 	 			v.push_back({j,k,c+w[j]+w[k]});//有重边 
		 	}
		 }		
	 }
 	sort(v.begin(),v.end(),cmp);
 	int cnt=0;
 	for(E x:v){
 		int u=x.u,v=x.v;
		unsigned long long w=x.w;
 		if(find(u)!=find(v)){
 			merge(u,v);
 			ans+=w;
 			cnt++;
		 }
		if(cnt>=n-1){
			break;
		}
	 }
	 cout<<ans;
	 return 0;
 }
 
 //最小生成树 
