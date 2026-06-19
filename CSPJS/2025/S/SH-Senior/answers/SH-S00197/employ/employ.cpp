#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		char x;
		cin>>x;
	}
	int p=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x==0){
			n--;
		}
	}
	int o=n;
	cout<<n;
	long long num=1;
	for(int i=0;i<min(o,m);i++){
		num*=n;
		n--;
		num%=998244353;
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

