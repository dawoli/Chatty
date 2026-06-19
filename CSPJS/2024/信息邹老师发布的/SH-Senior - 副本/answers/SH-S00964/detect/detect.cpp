#include <bits/stdc++.h> 
using namespace std;
#define maxn 1000010
struct node{
	int d,v,a;
}b[maxn];
int l[maxn],c[maxn];
int T,n,m,L,V;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
	long long cnt=0;
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++){
		cin>>b[i].d>>b[i].v>>b[i].a;
	}
	for(int i=1;i<=m;i++){
		int j;
		cin>>j;
		l[j]=1;
	}
	for(int i=L;i>=1;i--){
		c[i]=c[i+1]+l[i];
	}
	for(int i=1;i<=n;i++){
		int a=b[i].a;
		int d=b[i].d;
		int v=b[i].v;
		if(v>V){
			cnt++;
			continue;
		}
		if(!a){
			if(v>V)cnt++;
			continue;
		}
		double bei=(V*V-v*v);
		double chu=2*a;
		double dis1=bei/chu;
		int dis=dis1;
		if((dis1>(double)dis)){
			dis++;
		}
		if(c[dis]){
			cnt++;
		}
	}
	cout<<cnt<<" "<<m-1<<endl;
	}
	return 0;
}


