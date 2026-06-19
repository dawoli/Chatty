#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int student[100];
	int m,n,c,r;
	int swap;
	int cnt=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>student[i];
	}
	int R=student[0];
	for(int i=0;i<n*m;i++){
		for(int j=i+1;j<n*m;j++){
			if(student[i]<=student[j]){
				swap=student[i];
				student[i]=student[j];
				student[j]=swap;
//				cout<<"swap"<<endl;
			}
		}
	}
//	for(int i=0;i<n*m;i++){
//		cout<<student[i]<<" ";
//	}
	for(int i=0;i<n*m;i++){
			if(student[i]!=R){
				cnt++;
//				cout<<cnt<<endl;
			}
			else{
				break;
			}
	}
	if((cnt/n)%2==0){
		c=cnt/n+1;
		r=cnt%n+1;
	}
	else{
		c=cnt/n+1;
		r=n+1-cnt%n;
		if(r>n){
			r=n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
