#include<bits/stdc++.h>
using namespace std;
const int N=105;
double sv(int v,int a,int s){
	return sqrt(v*v+2*a*s);
}

int t,n,m,l,vb,d[N],v[N],a[N],p[N],ls[N],chaosu[N],p1[N],c1=0,mxans=0;//vb xiansu  v chesu
int count(int* o1){
	int c=0;
	for(int j=1;j<=n;++j){
		for(int k=1;k<=m;++k){
			if(sv(v[j],a[j],o1[k])>(double)v[j]&&p[k]>d[j]&&o1[k]!=1e9){
				c++;
			}
		}	
	}
	return c;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);

	cin>>t;
	for(int i=1;i<=t;++i){
		cin>>n>>m>>l>>vb;
		for(int j=1;j<=n;++j){
			cin>>d[j]>>v[j]>>a[j];
		}
		for(int k=1;k<=m;++k){
			cin>>p[k];
		}
		cout<<count(p)<<' ';
		for(int k=1;k<=m;++k){
			p1[k]=p[k];
		}
		for(int k=1;k<=m;++k){
			for(int j1=1;j1<=i;++j1){
				p1[j1]=1e9;
			}
			for(int j2=1;j2<=n;++j2){
				p1[j2-1]=p[j2-1];
				p1[j2]=1e9;
				int ans=count(p1);
				if(ans>mxans){
					mxans=ans;
				}
			}
		}
		cout<<mxans;
	}
	fclose(stdin);	fclose(stdout);
	return 0;
} 
