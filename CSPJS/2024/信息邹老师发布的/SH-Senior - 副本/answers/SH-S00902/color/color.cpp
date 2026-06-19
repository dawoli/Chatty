#include<bits/stdc++.h>

using namespace std;

ifstream fin("color.in");
ofstream fout("color.out");
#define cin fin
#define cout fout

#define int long long
const int N=1e6+9;
const int inf=1e18;

int a[N],b[N],f[N][4],pre[N],buc[N],n;
inline void ChMax(int &x,int y){
	if(y>x) x=y;
}

signed main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1]) b[i]=a[i];
			else b[i]=0;
		}
		for(int i=1;i<=n;i++) b[i]+=b[i-1];
		for(int i=1;i<=n;i++) pre[i]=buc[a[i]],buc[a[i]]=i;
		for(int i=1;i<=n;i++) buc[a[i]]=0;
		
		f[1][0]=f[1][3]=0,f[1][1]=f[1][2]=-inf;
		for(int i=2;i<=n;i++){
			f[i][2]=f[i][0]=max(f[i-1][0],f[i-1][1]);
			f[i][3]=f[i][1]=max(f[i-1][2],f[i-1][3]);
			if(a[i]==a[i-1]){
				f[i][0]+=a[i];
				f[i][3]+=a[i];
			}else if(pre[i]){
				ChMax(f[i][1],f[pre[i]+1][2]+a[i]+b[i-1]-b[pre[i]]);
				ChMax(f[i][2],f[pre[i]+1][1]+a[i]+b[i-1]-b[pre[i]]);
			}
		}
		
		cout<<max(max(f[n][0],f[n][1]),max(f[n][2],f[n][3]))<<endl;
		for(int i=1;i<=n;i++) for(int k:{0,1,2,3}) f[i][k]=0;
	}
	
	return 0;
}
