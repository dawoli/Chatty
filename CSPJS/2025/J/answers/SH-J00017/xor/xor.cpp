#include<bits/stdc++.h>
using namespace std;
int a[500010];
bool book[500010];
int qz(int s,int e){
	int res=0;
	for(int i=s;i<=e;i++){
		if(book[i]){
			return -1;
		}
		res=(res^a[i]);
	}
	return res;
}
void bj(int s,int e){
	for(int i=s;i<=e;i++){
		book[i]=true;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int cnt=0;
	//O(n)
	for(int i=1;i<=n;i++){
		for(int j=1;j+i-1<=n;j++){
			if(qz(j,j+i-1)==k){
				cnt++;
				bj(j,j+i-1);
			} 
		}
	}
	
	cout<<cnt;
	return 0;
}

