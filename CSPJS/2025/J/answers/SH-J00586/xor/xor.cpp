#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0;
int a[500010];
int c(int a,int b){
	int x=a xor b;
	return x;
}
int main(){
	freopen("xor.in","r","stdin");
	freopen("xor.out","w","stdout");
	//cout << (2 xor 3 xor 3) ;
	cin >> n >> k;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
		if(i>1)a[i]=c(a[i-1],a[i]);
	}
	//for(int i=1;i<=n;i++)cout << a[i] << " ";
	long long las=0;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=i;j++){
			if(las>=j)continue;
			if(i==j){
				if(c(a[i],a[i-1])==k){
					ans++;
					las=i;
					//cout << las << " " << j << " " << i << endl;
					
				}
			}else{
				if(c(a[i],a[j-1])==k){
					ans++;
					las=i;
					//cout << las << " " << j << " " << i << endl;
					
					
				}
			}
		}
	}
	cout << ans << endl;
	//for(int i=1;i<=n;i++)cout << a[i] << " ";
}/*
4 0
2 1 0 3

4 3
2 1 0 3
*/ 
