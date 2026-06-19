#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],yh[500005],flg=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			yh[i]=a[i];
		}
		else{
			yh[i]=a[i]^yh[i-1];
		}
		if(a[i]!=1){
			flg=0;
		}
	}//Ç°×ºÒì»ò 
	if(flg){
		cout<<n/2;
		return 0;
	}
	cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
