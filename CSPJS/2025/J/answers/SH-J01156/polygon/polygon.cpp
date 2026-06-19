#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,a[6000];
long long b[6000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int f;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=5009;j++){
			b[max(0,j-a[i])]+=b[j];
			b[max(0,j-a[i])]%=998244353;
		}
		for(int j=1;j<=i-1;j++){
			f=a[j]+1-a[i];
			b[f]++;
			b[f]%=998244353;
		}
		
	}
	
	cout<<b[0];
	return 0;
}
