#include<iostream>
using namespace std;
const int N=1e6+9;
int T;
int n,m,l,v;
int d[N],u[N],a[N],p[N];
bool f=1;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		int cs=0;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>u[i]>>a[i];
			if(a[i]!=0) f=0; 
		} 
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		if(f==1){
			for(int i=1;i<=n;i++){
				if(u[i]>v) cs++;
			}
			
			
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=m;j++){
//					if(d[i]>p[j]) {
//						if(u[i]>v) {
//							for(int k=j+1;k<=m;k++) jc[k]=true;
//						}
//						break;
//					}
//				}
//			}
//			
			
			cout<<cs<<' '<<m-1<<'\n';
			
		}
		
	}
	return 0;
}
