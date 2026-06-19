#include<iostream>
#include<cstring>
using namespace std;
const int N=1e6+10;
int t,n,a[N];
int main(){
	cin>>t;
	while(t--){
		memset(a,0,N);
		int sum=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				if(a[i]==a[j]){
					sum=sum+a[i];
					break;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
