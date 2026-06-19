#include <iostream>
using namespace std;


long long n;
long long a[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	long long an=n;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n-1;i++){
		long long A=i;
		for(long long j=i+1;j<n;j++){
			if(a[j]<a[A]){
				A=j;
			}
		}
		long long B=a[i];
		a[i]=a[A];
		a[A]=B;
	}
	long long i=n;
	while(i--){
		long long now=0;
		if(a[n-i]-a[now]>0){
			now++;
			an--;
		}
	}
	cout<<an;
	return 0;
} 
