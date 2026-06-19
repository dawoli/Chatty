#include<iostream>
#include<algorithm>
using namespace std;
const int N=5003;
const int M=998244353;
int n,a[N];
long long s[N*N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n; s[0]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int currsum=0; 
	long long ans=0;
	for(int i=1;i<n;i++){
		currsum+=a[i];
		for(int j=currsum;j>=a[i];j--)
			s[j]=(s[j]+s[j-a[i]])%M;
		for(int j=a[i+1]+1;j<=currsum;j++)
			ans=(ans+s[j])%M;
	}
	cout<<ans;
	return 0;
} 
