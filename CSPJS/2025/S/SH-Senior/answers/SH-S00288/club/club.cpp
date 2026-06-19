#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m[N][2],a[N][4],p[N],c[4];

bool cmp(int x,int y){
	return a[x][m[x][0]]-a[x][m[x][1]]>a[y][m[y][0]]-a[y][m[y][1]];
}

void init(){
	for(int i=0;i<=n+1;i++){
		m[i][0]=m[i][1]=0;p[i]=0;
		for(int j=0;j<=3;j++)a[i][j]=0;
	}c[0]=c[1]=c[2]=c[3]=0;
}

void solve(){
	init();cin>>n;
	for(int i=1;i<=n;i++){
		m[i][0]=m[i][1]=0;p[i]=i;
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if((!m[i][0])||a[i][m[i][0]]<a[i][j])
				m[i][1]=m[i][0],m[i][0]=j;
			else if((!m[i][1])||a[i][m[i][1]]<a[i][j])m[i][1]=j;
		}
	}sort(p+1,p+n+1,cmp);
	c[1]=c[2]=c[3]=0;int x,ans=0;
	for(int i=1;i<=n;i++){x=p[i];
		if(c[m[x][0]]+1<=n/2){
			c[m[x][0]]++,ans+=a[x][m[x][0]];
		}else{
			c[m[x][1]]++,ans+=a[x][m[x][1]];
		}
	}cout<<ans<<"\n";
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;cin>>T;while(T--)solve();
}