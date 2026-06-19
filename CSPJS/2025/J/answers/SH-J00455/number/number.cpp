#include<bits/stdc++.h>
using namespace std;
int f[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string a;
	cin>>a;
	for (int i=0;i<a.size();i++){
		if (a[i]-48<=9){
			f[a[i]-48]++;
		}
	}
	long long cnt=0;
	for (int i=9;i>=0;i--){
		while (true){
			if (f[i]==0) break;
			cnt*=10;
			cnt+=i;
			f[i]--;
		}
	}
	cout<<cnt;
	return 0;
} 
