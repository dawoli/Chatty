#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,num1=0,num0=0;
	cin>>n>>k;
	int a[500005];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1){
			num1++;
		}
		else{
			num0++;
		}
	}
	if(k==0)
		cout<<num1/2+num0;
	else{
		cout<<num1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

