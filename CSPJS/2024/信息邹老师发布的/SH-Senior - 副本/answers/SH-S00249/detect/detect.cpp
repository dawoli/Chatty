#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+5;
long long n,m,l,v,pos=1,cnt,t,yq[N],flag[N];
struct CHEZI{
	long long d,v,a;
}c[N];
bool cmp(CHEZI p,CHEZI q){
	return p.d<q.d;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>l>>v;
		for(int j=1;j<=n;j++){
			cin>>c[j].d>>c[j].v>>c[j].a;
		}
	}
	for(int i=1;i<=m;i++) cin>>yq[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(yq[j]<c[j].d) continue;
			else{
				if(sqrt(c[i].v*c[i].v+2*c[i].a*(yq[j]-c[i].d))>v){
					cnt++;
					flag[yq[j]]=1;
					break;
				}
			}
		}
	}
	cout<<cnt-1<<" ";
	cnt=0;
	for(int i=1;i<=m;i++){
		if(flag[yq[i]]==0) cnt++;
	}
	cout<<cnt<<" ";
	return 0;
}
