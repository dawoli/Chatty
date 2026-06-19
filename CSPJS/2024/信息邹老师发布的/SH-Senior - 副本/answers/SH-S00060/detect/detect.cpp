#include<bits/stdc++.h>
using namespace std;
int t;
struct c{
	int s,v,a;
	bool operator<(const c &cc)const{
		return s<cc.s;
	}
}ca[100007];
int dis[100007];
bool f[100007];
bool pd(int x,int te,int l){
	c n=ca[x];
	if(n.a*n.a+2*n.a*te>l*l) return 1;
	return 0;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int ro=1;ro<=t;ro++){
		int n,m,e,li;
		cin>>n>>m>>e>>li;
		int num=0;
		for(int i=1;i<=n;i++){
			f[i]=0;
			cin>>ca[i].s>>ca[i].v>>ca[i].a;
		}
		for(int i=1;i<=m;i++) cin>>dis[i];
		sort(ca+1,ca+n+1);
		for(int i=1;i<=n;i++){
			int l=1;
			for(int j=1;j<=m;j++){
				if(dis[j]<ca[i].s) l++;
				else break;
			}
			for(int j=l;j<=m;j++){
				if(ca[i].v>li){
					num++;
					for(int k=j;k<=m;j++) f[k]=1;
					break;
				}
			}
		}
		cout<<num<<' ';
		num=0;
		for(int i=1;i<=m;i++) if(f[i]) num++;
		cout<<num<<endl;
	}
	return 0;
}
