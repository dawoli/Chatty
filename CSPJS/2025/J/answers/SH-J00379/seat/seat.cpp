#include<bits/stdc++.h>
using namespace std;
int main(){
	int m, n;
	cin >> n >> m;
	int a[m*n]; 
	//#Shang4Shan3Ruo6Shui4
	for(int i=0;i<m*n;i++){
		cin >> a[i];
	}
	int r=a[0], k;
	sort(a,a+m*n);
	for(int i=0;i<m*n;i++){
		if(a[i]==r){
			k = n*m-i;
		}
	}
	int s = k % n;
	int q = (k-k%n)/n;
	if(s==0){
		s+=n;
		q-=1;
	}
	if(q%2==0){
		cout << q+1 <<" "<< s;
	}else{
		cout << q+1 <<" "<<n-s+1;
	}
	return 0;
}
