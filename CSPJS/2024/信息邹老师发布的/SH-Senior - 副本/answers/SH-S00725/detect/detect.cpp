#include<bits/stdc++.h>
using namespace std;
struct car{
	double d,v,a;
	int pl=0;
}b[100005];
int T,n,m,l,p[100005];
double vv;
bool h[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		int cnt=0;
		for(int i=0;i<100005;i++) h[i]=false;
		for(int i=0;i<100005;i++) b[i].pl=0;
		for(int i=0;i<100005;i++) p[i]=0;
		cin>>n>>m>>l>>vv;
		for(int i=1;i<=n;i++) cin>>b[i].d>>b[i].v>>b[i].a;
		for(int i=1;i<=m;i++) cin>>p[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(p[j]<b[i].d) continue;
				if(sqrt(pow(b[i].v,2)+2*b[i].a*(p[j]-b[i].d))>vv){
					cnt++;
					b[i].pl=j;
					break;
				}
			}
		}
		cout<<cnt<<' ';
		cnt=0;
		for(int i=1;i<=n;i++) h[b[i].pl]=1;
		for(int i=1;i<=m;i++){
			if(!h[i]) cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
