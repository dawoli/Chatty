#include<bits/stdc++.h>
using namespace std;
int f[10002]={0};
struct edge{
	int fr;
	int to;
	int v;
};
bool compare(edge a,edge b){
	if(a.v >b.v )return a.v <b.v ;
}
int find (int x){
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	vector<edge> e;
	for(int i=1;i<=m;i++){
		edge temp;
		cin>>temp.fr >>temp.to >>temp.v ;
		e.push_back(temp); 
	} 
	for(int i=0;i<k;i++){
		int va,a[10002];
		cin>>va;
		for(int j=0;j<n;j++)cin>>a[j];
		for(int q=1;q<n;q++){
			for(int p=q+1;p<=n;p++){
				edge temp;
				temp.fr =q;
				temp.to =p;
				temp.v =a[q-1]+a[p-1]+va;
				e.push_back(temp);
			}
		}
	}
	int ans=0;
	sort(e.begin(),e.end(),compare);
	int cnt=0;
	for(int i=0;i<e.size();i++){
		if(cnt==n-1)break;
		int a=e[i].fr,b=e[i].to;
		if(find(a)!=find(b)){
			f[a]=b;
			ans+=e[i].v;
			cnt++;
		}
	}
	cout<<ans;
	return 0;
}
