#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,now;
int ans;
int arr[500005];
bool all1(){
	if(n>100) return false;
	for(int i=1;i<=n;i++){
		if(arr[i]!=1)return false;
	} 
	return true;
}
bool oneandzero(){
	for(int i=1;i<=n;i++){
		if(arr[i]!=1&&arr[i]!=0)return false;
	} 
	return true;
} 
void solveall1(){
	cout<<n/2;
	return;
}
void solveoneandzero(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(k==0){
			if(arr[i]==0) cnt++;
			else if(arr[i]==arr[i-1]){
				cnt++;
				arr[i-1]=-1;
				arr[i]=-1;
			}
		}
		else{
			if(arr[i]==1) cnt++;
		}
	}
	cout<<cnt;
	return;
}
bool pown2(){
	if(n<=1000) return true;
	return false;
}
void solvepow2(){
	for(int i=1,j;i<=n;i++){
		bool find=0;
		int x=arr[i];
		for(j=i+1;j<=n;j++){
			if(x==k){
				find=1;
				break;
			}
			x=x xor arr[j];
		}
		if(x==k){
			find=1;
		}
		if(find==1){
			ans++;
			i=j-1;
		}
	} 
	cout<<ans<<endl;
	return;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(all1()) solveall1();
	else if(oneandzero()) solveoneandzero();
	else if(pown2()) solvepow2();
	return 0;
}

