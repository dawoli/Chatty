#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500005],maxn=1;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(k=0){
		for(int i=0;i<n;i++){
			if(a[i]==0) maxn++;
		}
		maxn--;
	}
	else if(k=1){
		for(int i=0;i<n;i++){
			if(a[i]==1) maxn++;
		}
		maxn--;
	}
	cout << maxn;
	return 0;
} 
