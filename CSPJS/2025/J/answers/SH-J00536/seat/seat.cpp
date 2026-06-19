#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],r=0;
int cols[20][20];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	r = a[0];
	sort(a,a+n*m,cmp);
	int cnt=0;
	for(int j=0;j<m;j++){
		if((j+1)%2==1){
			for(int i=0;i<n;i++){
				if(a[cnt] == r){
					cout<<j+1<<" "<<i+1;
					return 0;
				}
				cols[i][j] = a[cnt];
				cnt++;
			}
		} 
		else{
			for(int i=n-1;i>=0;i--){
				if(a[cnt] == r){
					cout<<j+1<<" "<<i+1;
					return 0;
				}
				cols[i][j] = a[cnt];
				cnt++;
			}
		} 
		
	}
	return 0;
}

