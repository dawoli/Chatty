#include<bits/stdc++.h> 
using namespace std;
int n,m,num,cnt,mod,di;
int a[105];
bool cmp(int c, int b){
	if(c>b){
		return true;
	}
	return false;
}
int main(){
	freeopen("seat.in","r","stdin");
	freeopen("seat.out","w","stdout");
	cin>>n>>m;
	for(int i=1; i<=n*m; i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++){
		if(a[i]==num){
			cnt=i;
			break;
		}
	}
	mod=cnt%n;
	di=(cnt-mod)/n;
	if(mod==0){
		cout<<di<<" ";
		if(di%2==0){
			cout<<1;
			return 0;
		}
		cout<<n;
		return 0;
	}else{
		cout<<di+1<<" ";
	}
	if(di%2==0){
		cout<<mod;
		return 0;
	}
	cout<<n-mod+1;
	return 0;
}
