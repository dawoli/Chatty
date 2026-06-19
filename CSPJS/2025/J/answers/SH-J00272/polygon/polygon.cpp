#include<iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long a[5005];
	cin>>n;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<n;j++){
		for(int k=1;k<n;k++){
			for(int m=2;m<n;m++){
				if((a[k]+a[j]+a[m])>(2*max(a[j],a[k],a[m]))){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
