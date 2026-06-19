#include <bits/stdc++.h>
using namespace std;
const int N=100009; 
int T,a[N][3];
int main(){
	cin>>T;
	while(T){
		int n,maxn,a1=0,a2=0,sum;
		cin>>n;
		maxn=n/2;
		for(int i=0,j=0;i<n;i++,j+=3){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]==a[i][1]){
				sum+=a[i][0];
				if(a1>a2)a1++;
				else a2++;
				continue;
			}
			if(a[i][0]>a[i][1]&&a1<=maxn){
				sum+=a[i][0];
				a1++;
			}else{
				sum+=a[i][1];
				a2++;
			}if(a[i][0]<a[i][1]&&a2<=maxn){
				sum+=a[i][0];
				a1++;
			}else{
				sum+=a[i][1];
				a2++;
			}
		}
		cout<<sum;
		T--;
	}
	return 0;
}
