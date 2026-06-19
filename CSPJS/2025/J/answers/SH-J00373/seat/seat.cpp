#include<bits/stdc++.h>
using namespace std;
int a,b,A[1050],c;
int compare(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a*b;i++){
		cin>>A[i];
		c=A[1];
	}
	sort(A+1,A+a*b+1,compare);
	for(int i=1;i<=a*b;i++){
		if(A[i]==c){
			cout<<(i-1)/a+1<<' ';
			if(((i-1)/a+1)%2==1){
				if(i%a>0){
					cout<<i%a;
				}
				else{
					cout<<a;
				}
			}
			else{
				if(i%a!=0){
					cout<<a-i%a+1;
				}
				else{
					cout<<1;	
				}
			}
			return 0;
		}
	}
	return 0;
}
