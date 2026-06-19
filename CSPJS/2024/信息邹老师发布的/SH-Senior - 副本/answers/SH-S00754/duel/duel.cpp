#include <bits/stdc++.h>
using namespace std;
long long n,a;
int m[500],x[500];
int main(){
//	freopen("duel.in","r",stdin);
//	freopen("duel.out","w",stdout);	
	cin >> n;
	for(int i=0;i<n;i++)cin >> m[i];
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<n-1;j++){
			if(m[j]>m[j+1]){
				a=m[j];
				m[j]=m[j+1];
				m[j+1]=a;
			}
		}
	}
	if(n=1){
		cout << 1;
	}else if(n=2){
		if(m[1]>m[0]){
			cout << 1;
		}
		if(m[1]==m[0]){
			cout << 2;
		}	
	}else{
		for(int j=0;j<n;j++){
			a=m[j];
			for(int i=0;i<n;i++){
				if (a==m[i+1]){
					x[j]+=1;
				}
			}
		}
		cout << x[0]-x[n];
	}
//	for(int i=0;i<n;i++)cout << m[i] <<" ";
	return 0;
} 
