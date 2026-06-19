#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m],l;
	cin>>a[0];
	int b=a[0];
	for(int i=1;i<n*m;i++)cin>>a[i];
	for(int i=0;i<n*m;i++){
		for(int j=i+1;j<n*m;j++)if(a[i]<a[j])swap(a[i],a[j]);
	}
	//for(int i=0;i<n*m;i++)cout<<a[i]<<" ";
	for(int i=1;i<=m;i++){
		if(b>a[n*i]){
			l=i-1;
			break;
		}
	}
	//cout<<endl<<l<<endl;
	//cout<<" "<<n*l<<" "<<n*(l+1)<<endl;
	for(int i=n*l;i<n*(l+1);i++){
		//cout<<a[i]<<"|"<<b<<endl;
		if(b==a[i]){
			if((l+1)%2!=0){
				cout<<l+1<<" ";
				if((i+1)%n!=0)cout<<(i+1)%n<<endl;
				else cout<<n<<endl;
				return 0;
			}
			else{
				cout<<l+1<<" "<<n-i%n<<endl;
				return 0;
			}
		}
	}
}
