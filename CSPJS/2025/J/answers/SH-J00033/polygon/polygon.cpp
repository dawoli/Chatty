#include<bits/stdc++.h>
using namespace std;
const int N=10009,M=10009;
const long long Mod=998244353;
int n,a[N],b[M];
long long summ,qp=2,summm=0;
int main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	b[0]++;b[a[1]]++;b[a[2]]++;b[a[1]+a[2]]++;
	for(int i=3;i<=n;i++){
		summ=0;qp*=2;qp%=Mod;
		//for(int j=0;j<=40;j++)cout<<b[j]<<" ";
		for(int j=0;j<=a[i];j++){
			summ+=b[j];
		}
		summm+=qp-summ+Mod*M;
		//cout<<qp-summ<<endl;
		summm%=Mod;
		for(int j=M-a[i];j>=0;j--){
			b[j+a[i]]+=b[j];
			b[j+a[i]]%=Mod;
		}
		//cout<<summ<<endl;
	}
	cout<<summm;
	return 0;
}
