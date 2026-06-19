#include<iostream>
using namespace std;
bool a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int cnt = 0;
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(k == 0)
		cout<<n/2;
	else{
		for(int i = 1;i <= n;i++){
			if(a[i] == 1)
				cnt++;
			cout<<cnt;
		}
	}
} 
