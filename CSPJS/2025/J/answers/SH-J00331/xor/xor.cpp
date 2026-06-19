#include <bits/stdc++.h>
using namespace std;
int n,k,a[500009],ans;
bool A=1,B=1,C=1;
void solve1(){
	if(n%2==0){
		ans=n/2;
	}else{
		ans=(n-1)/2;
	}
}
void solve2(){
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
	}else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans+=cnt/2;
				ans++;
				cnt=0;
			}else{
				cnt++;
			}
		}
		ans+=cnt/2;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)A=0;
		if(a[i]>1)B=0;
		if(a[i]>255)C=0;
	}
	if(A&&k==0){
		solve1();//1,3      *10
	}else if(B&&k<=1){
		solve2();//2,4,5,13 *20 
	}
	cout <<ans<<endl;
	return 0;
} 
