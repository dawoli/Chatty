#include<bits/stdc++.h>
using namespace std;
int n,m,h,l,a[105],r,zw[12][12],cnt=0;
bool flag;
bool cmp(int x,int y){
	if(x<y) return 0;
	return 1;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>r;
    a[0]=r;
    for(int i=1;i<n*m;i++) cin>>a[i];
    sort(a,a+n*m,cmp);
    for(int i=1;i<=n;i++){
    	if(i%2==1){
    		for(int j=1;j<=m;j++){
    			if(a[cnt]==r){
    				cout<<i<<' '<<j;
    				return 0;
				}	
				cnt++;
			}
		}else{
    		for(int j=m;j>=1;j--){
    			if(a[cnt]==r){
    				cout<<i<<' '<<j;
    				return 0;
				}
				cnt++;
			}
		}
	}
	return 0;
}	
