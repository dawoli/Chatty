#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
int n,m,s[105],a[15][15],k;
bool cmp(int x,int y){
	return x>y;
}
int ansx=0,ansy=0;
signed main(){//seat
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++)s[i]=read();
	k=s[1];
	sort(s+1,s+n*m+1,cmp);
	int now=0;
	for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int i=n;i>=1;i--){
				a[i][j]=s[++now];
				if(a[i][j]==k)ansx=j,ansy=i;
			}
		}
		if(j%2==1){
			for(int i=1;i<=n;i++){
				a[i][j]=s[++now];
				if(a[i][j]==k)ansx=j,ansy=i;
			}
		}
	}
	cout<<ansx<<" "<<ansy;
	return 0;
}

