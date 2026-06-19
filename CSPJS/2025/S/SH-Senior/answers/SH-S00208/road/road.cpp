#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
long long n,m,k,p,x,pp,s;
long long c[N],f[N];
bool book[N];
struct stu{
	long long u,v,w;
}a[N];
bool cmp(stu x,stu y){
	if(x.w!=y.w) return x.w<y.w;
	return 0;
}
int find(int x){
	if(x!=f[x]) find(f[x]);
	return f[x];
}
void merge(int x,int y){
	long long r1=find(x);
	long long r2=find(y);
	if(r1!=r2) f[r1]=r2;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	pp=p=n;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		p++;
		for(int j=1;j<=n;j++){
			cin>>x;
			m++;
			a[m].u=p;
			a[m].v=j;
			a[m].w=x;
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=p;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		if(find(a[i].u)!=find(a[i].v)){
			merge(a[i].u,a[i].v);
			k++;
			if(a[i].u>n || a[i].v>n){
				if(book[a[i].u-n]==0){
					book[a[i].u-n]=1;
					pp++;
				} 
				if(book[a[i].v-n]==0){
					book[a[i].v-n]=1;
					pp++;
				} 
			}
			s+=a[i].w;
			if(k==pp-1) break;
		}
	}
	cout<<s;
	return 0;
}
