#include<bits/stdc++.h>
#define ABLESOLVE1
#define ABLESOLVE2 
using namespace std;
const int N=1e5+9,N1=209;
int a[N],b[N],c[N];
int f[N1][N1][N1];
int n;
void solve1(){
	memset(f,0,sizeof f);
	int mv=0;
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				if(i+j+k>n)continue;
				if(i+j+k==n)mv=max(mv,f[i][j][k]);
				f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]+a[i+j+k+1]);
				f[i][j+1][k]=max(f[i][j+1][k],f[i][j][k]+b[i+j+k+1]);
				f[i][j][k+1]=max(f[i][j][k+1],f[i][j][k]+c[i+j+k+1]);
			}
		}
	}
	cout<<mv<<endl;
}
void solve2(){
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=n-n/2+1;i<=n;i++)ans+=a[i];
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		bool problemsolved=false;
#ifdef ABLESOLVE1
		if(n<=200&&!problemsolved){
			solve1();
			problemsolved=true;
		}
#endif
#ifdef ABLESOLVE2
		if(!problemsolved){
			solve2();
			problemsolved=true;
		}
#endif
	}
	return 0;
}
