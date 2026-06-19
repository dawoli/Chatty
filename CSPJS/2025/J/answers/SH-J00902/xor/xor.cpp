#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a[10005],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) m=a[i];
		if(a[i]==k){
			cnt+=1;
			m=a[i+1];
		}
	}
	for(int i=2;i<=n;i++){
		m=m^a[i];
		if(m==k){
			cnt+=1;
			m=a[i+1];
		}
	}
	cout<<cnt;
	fclose(stdin);fclose(stdout);
	return 0;
}
