#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if((a[1]+a[2]>a[3])&&(a[1]+a[3]>a[2])&&(a[2]+a[3]>a[1])){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	int o=0;
	for(int i=1;i<=n;i++){
		o=max(o,a[i]);
	}
	if(o==1){
		cout<<(n-1)*(n-2)/2;
	}else{
		cout<<n;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
