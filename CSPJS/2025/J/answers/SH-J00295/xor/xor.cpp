#include<bits/stdc++.h>
using namespace std;
int n,k,a[200050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt=0,cnt2=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1)cnt++;
		if(a[i]==0)cnt2++;
	}
	if(n==1){
		if(a[0]=k)cout<<1;
		else cout<<0;
		fclose(stdin);
		fclose(stdout);
		return  0;
	}
	if(k==1)cout<<cnt;
	else if(k==0)cout<<cnt2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
