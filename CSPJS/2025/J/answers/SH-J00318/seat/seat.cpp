#include<bits/stdc++.h>
using namespace std;
long long cnt=0;
long long n,m;
long long a1;
long long n1,m1;
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a1;
	for(long long i=0;i<n*m-1;i++){
		long long a;
		cin>>a;
		if(a>a1)cnt++;
	}
	long long se=cnt+1;
	long long se1=se/n;
	long long se2=se%n;
	if(se2==0&&se1%2==0){
		n1=1;
		m1=se1;
		cout<<m1<<" "<<n1<<endl;
		return 0;
	}else if(se2==0&&se1%2==1){
		n1=n;
		m1=se1;
		cout<<m1<<" "<<n1<<endl;
		return 0;
	}
	if((se1+1)%2==0){
		n1=n+1-se2;
		m1=se1+1;
	}else{
		n1=se2;
		m1=se1+1;
	}
	cout<<m1<<" "<<n1;
	return 0;
}
