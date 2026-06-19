#include<iostream>
using namespace std;
int n,m,s,ans=0;
int main(){
	cin>>n>>m>>s;
	for(int i=0;i<n*m-1;i++){
		int x;
		cin>>x;
		if(x>s)ans++;
	}
	cout<<ans/n+1<<' '<<(((ans/n)%2)?(n-ans%n):(ans%n+1));
}
