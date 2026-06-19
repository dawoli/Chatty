#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int n,m,k;
int a[N];
int a1[N];
int c[N];
int lg[2*N];
int d[25][2*N];
int win[25][2*N];
int x[4];
void init(){
	for(int i=2;i<=n;i++){
		lg[i]=lg[i/2]+1;
	}
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++){
		cin>>a1[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	k=lg[n];
	if((1<<k)!=n)k++;
	for(int r=1;r<=k;r++){
		for(int i=1;i<=1<<(k-r);i++){
			cin>>c[i];
			d[r][i]=c[i]-'0';
		}
	}
	int t;
	cin>>t;
	while(t--){
		long long res=0;
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=n;i++){
			a[i]=a1[i]^x[i%4];
		}
		for(int i=1;i<=1<<k;i++){
			win[0][i]=i;
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=1<<(k-i);j++){
				if(d[i][j]==0){
					if(a[win[i-1][2*j-1]]>=i)win[i][j]=win[i-1][2*j-1];
					else win[i][j]=win[i-1][2*j];
				}
				else{
					if(a[win[i-1][2*j]]>=i)win[i][j]=win[i-1][2*j];
					else win[i][j]=win[i-1][2*j-1];
				}
			}
		}
		for(int i=1;i<=m;i++){
			int Lg=lg[c[i]];
			res=res^win[Lg][1];
		}
		cout<<res<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
