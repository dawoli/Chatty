#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
const int N=1009;
const int S=9;
const int DIV=4;
int a[DIV]={0,1,0,-1};
int b[DIV]={1,0,-1,0};
int x[N],y[N],d[N];
char p[N][N];
int ans[S];
int cnt;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	    ans[i]=1;
	for(int i=1;i<=T;i++){
		cin>>n>>m>>k;
		cin>>x[i]>>y[i]>>d[i];
		for(int j=1;j<=n;j++)
		    for(int l=1;l<=m;l++)
		        cin>>p[j][l];
		while(cnt<k){
		    if(x[i]+a[d[i]]>=1&&x[i]+a[d[i]]<=n&&y[i]+b[d[i]]>=1&&y[i]+b[d[i]]<=m&&p[x[i]+a[d[i]]][y[i]+b[d[i]]]=='.'){
		        ans[i]++;cnt++;
		        x[i]+=a[d[i]];
			    y[i]+=b[d[i]];
		        if(cnt==k) break;
	        }
	        else{
	            d[i]=(d[i]+1)%4;
	            cnt++;
	            if(cnt==k) break;
		    }
	    }	
	}
	for(int i=1;i<=T;i++) cout<<ans[i]<<endl;
	return 0;
}
