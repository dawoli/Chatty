#include<bits/stdc++.h>
using namespace std;
const int N=5000;
long long n,k,a[N];
/*void f(long long a,long long b){
	long long c=0,d=0;
	while(a>0){
		c=c*10+a%2;
		a/=2;
	}
	while(b>0){
		d=d*10+b%2;
		b/=2;
	}
	while(c>0){
		a=a*10+c%10;
		c/=10;
	}
	while(d>0){
		b=b*10+d%10;
		d/=10;
	}
}*/
void solve1(){
	long long nk=n/2;
	cout<<nk<<endl;
	return;
}
void solve2(){
	int cnt=0;
	if(k==0){
	    for(int i=1;i<=n;i++){
		    if(a[i]==0) cnt++;
		    else if(a[i]==1&&a[i-1]==1) cnt++;
	    }
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt++;
		}
	}
	cout<<cnt<<endl;
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0) solve1();
	else if(k==1) solve2();
	else solve1();
	return 0;
}
