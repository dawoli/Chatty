#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1],s;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			s=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(s<=i*n){
			cout<<i<<' ';
			if(i%2==0){
				cout<<n-s%n+1;
			}
			else{
				cout<<s-i*n+n;
			}
			return 0;
		}
	}
}
