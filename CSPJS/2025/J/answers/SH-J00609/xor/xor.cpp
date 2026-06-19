#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in ","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	long long a[n+10];
	long long cnt;
	long long A=0,B=0,A1=0;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt++;
			a[i]=-1;
		}
		if(a[i]<=1)B++;
		if(a[i]==1)A1++;
		if(a[i]==1&&a[i-1]==1&&(num==0||num==i)){
			A++;
			num=i+2;
		}
		if(num==i)num=0;
	}
	if(B==n&&k==1)cout<<cnt;
	if(B==n&&k==0)cout<<cnt+A;
	if(A1==n&&k==0)cout<<A;
	return 0;
}
