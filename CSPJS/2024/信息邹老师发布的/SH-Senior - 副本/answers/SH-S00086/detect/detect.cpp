#include<bits/stdc++.h>
using namespace std;
struct car{
	int d,v,a;
};
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T,n,m,L,V;
	cin>>T;
	for(int C=1;C<=T;C++){
		cin>>n>>m>>L>>V;
		int p[m+1];
		car c[n+1];
		bool cs[n+1][m+1];
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				cs[i][j]=false;
			}
		}
//		memset(cs,true,sizeof(cs));
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
//			if(c[i].a==0){
//				if(c[i].v<=V){
//					cs[i]=false;
//				}
//			}
		}
		int k=0;
		for(int i=1;i<=m;i++){
			cin>>p[i];
			for(int j=1;j<=n;j++){
				if(c[j].d>p[i]){
					continue;
				}
				if(sqrt(2*c[j].a*(p[i]-c[j].d)+c[j].v*c[j].v)>V){
					cs[j][k]=true;
				}
			}
			k++;
		}
		int count=0;
		for(int i=1;i<=n;i++){
//			bool ccs=false;
			for(int j=0;j<m;j++){
				if(cs[i][j]==true){
					count++;
					break;
				}
			}
		}
		bool xcs[n+1][m+1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(cs[i][j-1]==true){
					xcs[i][j]=false;	
				}
				
			}
		}
		cout<<count<<" ";
		count=0;
		for(int i=0;i<m;i++){
			bool ycs=false;
			for(int j=1;j<=n;j++){
				if(cs[j][i]==true&&xcs[j][i]==true){
					ycs=true;
					break;
				}
			}
			if(!ycs)count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
