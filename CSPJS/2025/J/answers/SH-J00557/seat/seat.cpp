#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],s,loc=-1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			loc=i;
			break;
		}
	}	
	if(loc%n==0){
		int c=loc/n;
		cout<<c<<" ";
		if(c%2==0){
			cout<<1<<endl;
		}else{
			cout<<n<<endl;
		}
	}else{
		int c=loc/n+1;
		cout<<c<<" ";
		if(c%2==0){
			int k=loc%n;
			cout<<n-k+1<<endl;;			
		}else{
			int k=loc%n;
			cout<<k<<endl;
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

