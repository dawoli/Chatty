#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5010],cnt=0,ans=0;
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int k=cnt,l=0,m=i,n=1;
		for(int j=1;j<i;j++)k-=a[j];
		if(k>2*a[i]){
			ans++;
			while(k>2*a[i]){
				l++;
				m++;
				k-=a[m];
			}
			for(int o=i;o>=i-l;i++){
				m*=o;
			}
			ans=(ans+m)%998244353;
		}		
	}
	cout<<ans;
	return 0;
} 
