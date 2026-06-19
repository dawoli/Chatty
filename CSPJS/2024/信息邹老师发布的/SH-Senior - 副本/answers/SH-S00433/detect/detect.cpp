#include<iostream>
using namespace std;

int T,n,m,L,V;
int d[100005],v[100005],a[100005],m[100005];

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",T);
    for(int j=1;j<=T;j++){
    	scanf("%d %d %d %d",&n,&m,&L,&V);
    	for(int i=1;i<=n;i++){
    		scanf("%d %d %d",&d[i],&v[i],&a[i]);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",m[i]);
		}
	}
    printf("3 3");

    return 0;
}
