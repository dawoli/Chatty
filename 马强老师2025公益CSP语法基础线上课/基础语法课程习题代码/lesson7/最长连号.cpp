#include<iostream>
using namespace std;
int main(){
	int n,ans=0;
	cin>>n;
	int t,a;
	cin>>t;
	int cnt=1;
	for(int i=2;i<n;i++){
		cin >> a;
		if(a==t+1) cnt++;
		else cnt=1;
		t=a;
		if(cnt>ans)
			ans=cnt;
		
	}
	cout<<ans<<endl;
	return 0;
}
