#include<iostream>
#include<bitset>
#include<cstdio>
using namespace std;
const int P=998244353;
int a[30],n;
bitset<20> b;
void cal1(){
	for(int i=0;i<n;i++) cin>>a[i];
	int ans=0;
	for(int i=1;i<(1<<n);i++){
		b=i;
		int sum=0,maxn=-1;
		for(int j=0;j<n;j++){
			if(b[j]==1){
				sum+=a[j];
				maxn=max(maxn,a[j]);
			}
		}
		if(sum>2*maxn) ans++;
	}
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=20) cal1();
}
