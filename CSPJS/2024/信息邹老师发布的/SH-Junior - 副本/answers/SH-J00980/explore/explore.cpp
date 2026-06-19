#include<bits/stdc++.h>
using namespace std;
char p[1010][1010];
int n,m,k,s=0,f=1,e=0;
int dg(int a,int b,int d){
	e=0;
	if(d==0&&f<=k){
		if(p[a][b+1]=='.'&&a<=n&&a>=1&&b+1>=1&&b+1<=m){
			f++;
			s++;
			p[a][b+1]='1';
			dg(a,b+1,d);
		}
		else if(p[a][b+1]!='1'){
			d=(d+1)%4;
			f++;
			dg(a,b,d);
		}
	}	
	if(d==1&&f<=k){
		if(p[a+1][b]=='.'&&a+1<=n&&a+1>=1&&b>=1&&b<=m){
			f++;
			s++;
			p[a+1][b]='1';
			dg(a+1,b,d);
		}	
		else if(p[a+1][b]!='1'){
			d=(d+1)%4;
			f++;
			dg(a,b,d);
		}
	}
	if(d==2&&f<=k){
		if(p[a][b-1]=='.'&&a<=n&&a>=1&&b-1<=m&&b-1>=1){
			f++;
			s++;
			p[a][b-1]='1';
			dg(a,b-1,d);
		}
		else	if(p[a][b-1]!='1'){
			d=(d+1)%4;
			f++;
			dg(a,b,d);
		}
	}
	if(d==3&&f<=k){
		if(p[a-1][b]=='.'&&a-1<=n&&a-1>=1&&b>=1&&b<=n){
			f++;
			s++;
			p[a-1][b]='1';
			dg(a-1,b,d);
		}
		else if(p[a-1][b]!='1'){
			d=(d+1)%4;
			f++;
			dg(a,b,d);
		}
	}
	return s;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		s=0;
		f=1;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int j=1;j<=n;j++){
			for(int w=1;w<=m;w++){
				cin>>p[j][w];
			}
		}
		int q=dg(x,y,d);
		cout<<q+1<<"\n";
	}
	return 0;
}
