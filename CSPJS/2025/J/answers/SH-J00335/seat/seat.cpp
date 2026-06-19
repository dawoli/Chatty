#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,r_i,t1=0;
	cin >> n >> m;
	int s[n*m];
	int a[m*n];
	for(int i = 0;i<n*m;i++){
		cin >> s[i];
	}
	r=s[0];
	int t;
    for(int i = 1;i<=n*m-1;i++){
    	for(int j = 1;j<=n*m-i;j++){
    	    if(s[j-1]<s[j]){
    	    	t=s[j-1];
    	    	s[j-1]=s[j];
    	    	s[j]=t;
			}
	    }
	}
	for(int i = 0; i<n*m;i++){
		if(s[i]==r){
			r_i=i+1;
		}
	}
	int m1=r_i/n;
	if(r_i%n!=0){
		m1=((r_i-r_i%n)/n)+1;
	}
	int n1=r_i%n;
	if(n1==0){
		n1=n+n1;
		t1 = 1;
	}
	if(m1%2==0){
		n1=n-n1+1;
	    if(t1==1){
	    	n1=1;
		}
	}
	cout << m1 << " "<< n1;
	return 0;
}
