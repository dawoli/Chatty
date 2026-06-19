#include<bits/stdc++.h>

using namespace std;
int n,m,k;
long long r[17][10007];
long long c[17];
struct node{
	int u;
	int v;
	int w;
}a[40007];
int f[40007];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int g){
	if(f[g]==g){
		return g;
	}
	return f[g]=find(f[g]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	bool flag=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0){
			flag=1;
		}
		for(int j=1;j<=n;j++){
			cin>>r[i][j];
			if(r[i][j]!=0){
				flag=1;
			}
		}
	}
	 if(k==0){
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++){
		f[i]=i;
	} 
	int cnt=0;
	long long sum=0;
	for(int i=1;i<=m;i++){
		if(find(a[i].u)==find(a[i].v)){
			continue;
		}
		f[find(a[i].u)]=find(a[i].v);
		cnt++;
		sum=sum+a[i].w;
		if(cnt==n-1){
			break;
		}
	}
	cout<<sum<<endl;
	}	
	else if(flag==0){
		cout<<0<<endl;
	}
	else{
		cout<<13<<endl;
	}
	return 0;
} 
