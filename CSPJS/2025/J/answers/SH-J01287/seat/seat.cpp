#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}	
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			if(i%n==0){
				if(i/n%2==1) cout<<n<<' '<<i/n;
				else cout<<i/n<<' '<<1;
			}
			else{
				int l=i/n+1;
				if(l%2==0){
					int c=n+1-(i-(l-1)*n);
					cout<<l<<' '<<c;
				}
				else{
					int c=i-(l-1)*n;
					cout<<l<<' '<<c;
				}
			}
			break;
		}
	}
	return 0;
}
