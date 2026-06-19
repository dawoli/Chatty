#include<bits/stdc++.h>
using namespace std;
int aa[105],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>aa[i];
	}
	int xx=aa[1];
	int nm=n*m;
	sort(aa,aa+n*m+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(aa[nm]==xx){
				if(i%2==0){
					cout<<i<<" "<<m-j+1;
					return 0;
				}
				if(1%2==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
			nm--;
		}
	}
	return 0;
}
