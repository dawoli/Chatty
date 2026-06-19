#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,k;
int a[100009];
bool ap=1,bp=1;
int get(int q,int w){
	int ans=a[q];
	for(int i=q+1;i<=w;i++){
		ans^=a[i];
	}
	return ans;
}
void input(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)ap=0;
		if(a[i]!=1&&a[i]!=0)bp=0;
	}
}
void solveA0(){
	cout<<n/2;
	return;
}
void solveB0(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0)cnt++;
		if(a[i]==1&&a[i+1]==1&&i<n){
			i++;
			cnt++;
		}
	}
	cout<<cnt;
}
void solveB1(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1)cnt++;
	}
	cout<<cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	input();
	if(ap&&k==0){
		solveA0();
		return 0;
	}else if(k==0&&bp){
		solveB0();
		return 0;
	}else if(k==1&&bp){
		solveB1();
		return 0;
	}
	return 0;
}


