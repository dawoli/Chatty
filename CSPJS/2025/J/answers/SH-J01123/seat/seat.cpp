#include<bits/stdc++.h>
using namespace std;
int n,m,l;
int a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	l=a[1];
	for(int i=2;i<=n*m-1;i++){
		cin>>a[i];
	}sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==l){
			if((n*m-i+1)%m==0){
				if(((n*m-i+1)/m)%2==0){
					cout<<(n*m-i+1)/m<<" "<<1;
				}else{
					cout<<(n*m-i+1)/m<<" "<<m;
				}
			}if((n*m-i+1)%m!=0){
				if(((n*m-i+1)/m+1)%2==0){
					cout<<(n*m-i+1)/m+1<<" "<<m-(n*m-i+1)%m+1;
				}else{
					cout<<(n*m-i+1)/m+1<<" "<<(n*m-i+1)%m;
				}
			}
		}
	}
	return 0;
	
}
 
