#include<bits/stdc++.h>
using namespace std;
int n,m,q[101],a[101];
int main(){
	freo("seat.in","r",stdiu);
	freo("seat.out","w",stdouts);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>q[i];
		a[i]=q[i];
		while(q[i-1]>=q[i]&&i>=2){
			int r=q[i-1];
			q[i-1]=q[i]; 
			q[i]=r;
		}
	}
	for(int i=1;i<=n*m;i++){
		cout<<q[i]<<" ";
	} 
	return 0;
}

