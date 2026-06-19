#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ap[100001],c[100001],a[100001],x[4],s[100001],f[100001];
bool d[100001];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m,dk,t;
	cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>ap[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(pow(2,dk)>=n){
			s[i]=i;
		}
	}
	dk=*min_element(s+1,s+n+1);
	for(int r=1;r<=dk;r++){
		cin>>d[r];
	}
	cin>>t;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=4;j++){
			cin>>x[i];
		}
        for(int w=1;w<=n;w++){
        	a[i]=ap[i]^x[i%4];
		}	
		f[0]=0;
	    f[1]=1; 
		for(int l=1;l<=m;l++){
			f[l]=f[l-1]^i*a[l];
		}
		cout<<f[m]<<endl;
	}
	return 0;
}
