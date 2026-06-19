//CCFÌ«ÉÆÁ¼ÁË 
#include <bits/stdc++.h>
using namespace std;
int a[5005],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int l=1;l<=n;l++){
		for(int r=1;r<=n;r++){
			if(r-l>=3){
				int sum;
				for(int i=l;i<=r;i++){
					sum+=a[i];
				}
				if(sum>=2*a[r]){
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
} 
