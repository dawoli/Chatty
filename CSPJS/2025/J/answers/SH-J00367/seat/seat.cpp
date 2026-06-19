#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[11][11];
	int b[100],abc=0;
	for(int i=0;i<m*n;i++){
		cin>>b[i];
	}
	abc=b[0];
	sort(b,b+n*m);
	int n1=1,m1=1;
	bool flag=true;
	for(int i=n*m-1;i>=0;i--){
		a[m1][n1]=b[i];
		if(a[m1][n1]==abc){
			cout<<m1<<" "<<n1;
			break;
		}
		if(m1%2==1&&n1==m){
			m1++;
			flag=false;
			continue;
		}else if(m1%2==0&&n1==1){
			m1++;
			flag=true;
			continue;
		}
		if(flag){
			n1++;
		}else{
			n1--;
		}
	}
	return 0; 
} 
