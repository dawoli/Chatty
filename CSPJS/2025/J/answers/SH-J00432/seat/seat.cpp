#include<bits/stdc++.h>
using namespace std;
int a[110];
int b[20][20];
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int cj;
	cin>>n>>m;
	int ans=0;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	cj=a[1];
	sort(a+1,a+sum+1);
	for(int i=sum;i>=1;i--){
		ans++;
		if(a[i]==cj){
			break;
		} 
	} 	
	if(ans%n!=0){
		int x=ans/n+1;
		int y=ans%n;
			if(ans<=n){
				cout<<"1"<<" "<<ans;
			}
			else{
				if(x%2==0){
					cout<<x<<" "<<n-y+1;
				}
				if(x%2!=0){
					cout<<x<<" "<<y;
				}
			}
		
	}
	else{
		int h=ans/n;
		cout<<h<<" ";
		if(h%2==0){
			cout<<"1";
		}
		else{
			cout<<n;
		}
	}
	return 0;
}
