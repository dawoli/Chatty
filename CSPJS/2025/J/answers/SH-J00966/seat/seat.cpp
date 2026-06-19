#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,b[101],jie=1;
	cin>>n>>m;
	cin>>a;
	for(int i=0;i<n*m-1;i++){
		cin>>b[i]; 
	}
	sort(b,b+n*m-1);
	for(int i=n*m-2;b[i]>a;i--){
		jie++;
	}
	if(((jie-1)/n)%2==1){
		cout<<jie/n+1<<" "<<n+1-(jie-(jie/n)*n);
	}
	if(((jie-1)/n)%2==0){
		cout<<(jie-1)/n+1<<" "<<jie-((jie-1)/n)*n;
	}
	return 0;
}
