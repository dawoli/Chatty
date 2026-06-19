#include<bits/stdc++.h>
using namespace std;
int n,m;
char c;
int a[100001];
int num=0;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>0){
			num++;
		}
	}
	if(num<m){
		cout<<0;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			ans*=i;
			ans=ans%998244353;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
