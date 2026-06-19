#include<bits/stdc++.h>
using namespace std;
int n,m,t,k,xn,yn,dn;
const int gx[4]={0,1,0,-1};
const int gy[4]={1,0,-1,0};
char c[1002][1002];
bool vst[1002][1002];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>xn>>yn>>dn;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
				vst[i][j]=0;
			}
		}
		int ans=1;
		vst[xn][yn]=1;
		while(k--){
			int xa=xn+gx[dn],ya=yn+gy[dn];
			if(c[xa][ya]=='.'){
				xn=xa;
				yn=ya;
				if(!vst[xn][yn]) ans++;
				vst[xn][yn]=1;
			}
			else dn=(dn+1)%4;
		}
		cout<<ans<<endl;
	}
	return 0;
}
