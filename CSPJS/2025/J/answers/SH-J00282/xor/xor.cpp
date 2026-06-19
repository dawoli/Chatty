#include<bits/stdc++.h>
using namespace std;
int a[500005];
int xxor(int x, int y){
	int ans=a[x];
	for(int i = x+1; i <= y; i++){
		ans^=a[i];
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0,x=0;
	cin>>n>>k;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for(int i = 0; i < n; i++){
		if(xxor(x,i)==k){
			cnt++;
			x=i+1;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
