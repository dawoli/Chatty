#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[10000]{};
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		
	}
	int r=a[1];
	int q;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<' ';
		if(a[i]==r){
//			cout<<a[i];
			q=i;
		}
	}
//	cout<<q;
	if(q%n==0){
		cout<<q/n<<' '<<n;
	}else{
		cout<<q/n+1<<' ';
		if((q/n+1)%2==0)cout<<n-(q%n-1);
		if((q/n+1)%2==1)cout<<q%n;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);	
} 
