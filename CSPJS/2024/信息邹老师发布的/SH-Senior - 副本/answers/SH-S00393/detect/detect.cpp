#include<bits/stdc++.h>
using namespace std;
int T,n,m,l,v,d[100010],va[100010],a[100010],p[100010],mx,mn,cw[30],cwk[30];
bool cs(int cx,int mcx,int ac,int v0){
	if(cx>mcx)return 0;
	double sp=sqrt(double(v0)*v0+2.0*ac*(mcx-cx));
	if(sp>v)return 1;
	else return 0;
}

double getpivot(int cx,int ac,int v0){
	return cx+double(v*v*1.0-v0*v0*1.0)/double(2.0*ac);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		memset(cw,0,sizeof(cw));
		memset(cwk,0,sizeof(cwk));
		mx=-1;mn=0x3f3f3f3f;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++)cin>>d[i]>>va[i]>>a[i];
		for(int i=1;i<=m;i++){
			cin>>p[i];mx=max(mx,p[i]);
		}
		if(n<=10&&m<=10){
			for(int j=1;j<=m;j++){
				for(int k=1;k<=n;k++){
					if(cs(d[k],p[j],a[k],va[k])){
						cw[k]=1;
						//cout<<"SPEEDERR!\n";
					}
				}
			}
			int mn=0x3f3f3f3f,cnt=0;
			for(int i=0;i<(1<<m);i++){
				int tmp=i,w=0;
				for(int j=1;j<=m;j++){
					if(tmp&1){
						w++;
						for(int k=1;k<=n;k++){
							if(cs(d[k],p[j],a[k],va[k]))cwk[k]=1;
						}
					}tmp/=2;
				}bool fl=true;
				for(int j=1;j<=n;j++){
					if(cw[j]!=cwk[j]){
						fl=false;
					}cwk[j]=0;
				}if(fl)mn=min(mn,w);
			}
			for(int i=1;i<=n;i++)if(cw[i])cnt++;
			cout<<cnt<<" "<<m-mn<<'\n';
		}else if(a[1]>=0){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(cs(d[i],mx,a[i],va[i]))cnt++;
			}
			if(cnt!=0)cout<<cnt<<" "<<m-1<<'\n';
			else cout<<cnt<<" "<<m<<'\n';
		}else{
			cout<<"114514\n";
		}
	}
	return 0;
}
