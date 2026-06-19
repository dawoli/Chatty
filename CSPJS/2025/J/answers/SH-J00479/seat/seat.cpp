#include<bits/stdc++.h>
using namespace std;
ifstream fin("seat.in");
ofstream fout("seat.out");
int n,m,r;
int a[105];
int main(){
	int n,m;
	fin>>n>>m;
	fin>>a[1];
	r=a[1];
	for(int i=2;i<=n*m;++i){
		fin>>a[i];
	}
	sort(a+1,a+n*m+1);
	int lower=1,upper=n*m;
	while(lower<upper){
		int mid=(lower+upper)/2;
		if(r>a[mid]){
			lower=mid+1;
		}
		else{
			upper=mid;
		}
	}
	upper=n*m-upper+1;
	fout<<upper/n+upper%n<<" "<<(((upper/n+upper%n)%2!=0)?((upper%n==0)?n:(upper%n)):((upper%n==0)?1:(n-upper%n+1)));
}

