#include <bits\stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
 
int speA(){
	int x=1;
	for(int i=1;i<=n;i++){
		x=min(x,a[i]); 
	}
	int ans=0;
	if(x){
		cout<<n/2;
	}else{
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
			}
			if(a[i]!=k){
				if(a[i+1]^a[i]==k){
					ans++;
				}
				i++;
			}
		}
		cout<<ans;
	}
}
//int nol(int l){
//	if(l<=n){
//		for(int i=1;i<=n;i++)	
//	}
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int lev=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lev=max(lev,a[i]); 
	} 
	if(lev==1){
		speA();
	}
//	else{
//		cout<<nol(1);
//	}
	return 0;
} 
