#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<n;j++){
			if(a[j]>a[j+1]){
			swap(a[j],a[j+1]); 
		}
		}
	}
	//for(int j=1;j<=n;j++){
		//cout<<a[j]<<" ";
	//}
	int cnt=n;
	for(long long i=1;i<=n;i++){
		for(long long j=i-1;j>=1;j--){
			if(a[j]<a[i]&&a[j]!=-1){
				a[j]=-1;
				cnt--;
				break;
			}
		}
		//for(int j=1;j<=n;j++){
			//cout<<a[j]<<" ";
		//}
		//cout<<endl;
	}
	cout<<cnt;
	return 0;
}
