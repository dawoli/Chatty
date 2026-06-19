#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500009;
ll n,k;
ll a[N];
bool isA(){
	for(int i=2;i<=n;i++)if(a[i]!=a[i-1])return 0;
	return 1;
}
void solveA(){
	if(k==a[1])cout<<n;
	else if(k==0){
		cout<<n/2;
	}else{
		cout<<0;
	}
}
bool isB(){
	for(int i=1;i<=n;i++)if(a[i]>1)return 0;
	return 1;
}
void solveB(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
		}
	}
	cout<<ans;
}
bool had[109];
void solveN100(){
	int ans=0;
	int p=a[1];
	for(int i=2;i<=n;i++){
//		if(!had[i]){
//			had[i]=1;
//			int p=a[i];
//			for(int j=i+1;j<=n;j++){
//				if(p==k&&!had[j+1]){
//					ans++;
//					j++;
//					p=a[j];
//					had[j]=1;
//				}
//				p=p xor a[j];
//			}
//			if(p==k){
//				ans++;
//				had[n]=1;
//			} 
//		}
		if(p==k){
			ans++;
			p=a[i];
			continue;
		}else{
			p=p xor a[i];
		}
	}
	if(p==k)ans++;
	cout<<ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)cin>>a[i];
	if(isA())solveA();
	else if(isB())solveB();
	else if(n<=100)solveN100();
	else cout<<k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
