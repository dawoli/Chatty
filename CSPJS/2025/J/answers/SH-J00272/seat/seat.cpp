#include<iostream>
using namespace std;


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[105];
	int cnt=0;
	cin>>n>>m;
	if(n==1 and m==1){
		cout<<"1 1";
		return 0;
	}
	else{
		for(int i=0;i<n*m;i++){
			cin>>a[i];
		} 
		int R=a[0];
		for(int j=0;j<n*m;j++){
			for(int i=1;i<n*m;i++){
				if(a[i]>a[i-1]){
					swap(a[i],a[i-1]);
				}
				else{
					continue;
				}
			}
		} 
		for(int i=0;i<m*n;i++){
			if(a[i]==R){
				cnt=i+1;
			}
		}
		if(cnt==1) cout<<"1 1";
		else{
			if(cnt%n==0){
				if((cnt/n)%2==0){
					cout<<cnt/n<<" "<<1;
				}
				else{
					cout<<cnt/n<<" "<<n; 
				}
			}
			else{
				if((cnt%n)%2==0){
					cout<<cnt/n+1<<" "<<n-cnt%n;
				}
				else{
					cout<<cnt/n+1<<" "<<cnt%n; 
				}
			}
		}
		return 0;
	}
	
}
