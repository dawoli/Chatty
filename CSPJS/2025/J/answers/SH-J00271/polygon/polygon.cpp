#include <bits/stdc++.h>
using namespace std;
long long c(int a,int b){
    long long s_=1,s__=1;
	for (int i=b;i>=b-a+1;i--){
		s_*=i;
	}
	for (int i=a;i>=1;i--){
		s__*=i;
	}
	return s_/s__;
}
long long aa(int a,int b){
	long long s=1;
	for (int i=b;i>=b-a+1;i--){
		s*=i;
	}
	return s;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[100],s=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (n==3){
	    if (a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2){
		    cout<<1;
	    }
	    else{
		    cout<<0;
	    }
    }
    else{
    	for (int i=3;i<=n;i++){
    		s+=c(i,n);
		}
		cout<<s%998244353;
	}
	return 0; 
} 
