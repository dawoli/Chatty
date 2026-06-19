#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005
int T,n,m,a[N],aa[N],c[N],d[100][N]; 
int pow2(int x){
	int ret=1;
	for(int i=1;i<=x;i++)ret*=2;
	return ret;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf ("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	    scanf ("%d",&aa[i]);
	for(int i=1;i<=m;i++)
	    scanf ("%d",&c[i]);
	if(n<=500){
		int d[10][505]={};
	    int k=0,kk=1;
	    for(k=1;k;k++){
		    kk*=2;
		    if(kk>n)break;
    	}
    	k--;
    	for(int i=k;i>=1;i--)
    	    for(int j=1;j<=pow2(i);j++)
    	        scanf ("%d",&d[i][j]);
    	scanf ("%d",&T);
    	while(T--){
    		int x[4]={};
    		scanf ("%d %d %d %d",&x[0],&x[1],&x[2],&x[3]);
    		for(int i=1;i<=n;i++)
    		    a[i]=aa[i] xor (x[i%4]);
    		
		}
	}
	
	
	return 0;
}
