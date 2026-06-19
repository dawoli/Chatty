#include<iostream>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%7==0){
			int cnt=n/7;
			for(int i=0;i<cnt;i++)cout<<8;
			cout<<endl;
		}
		else if(n%7==1){
			int cnt=n/7-2;
			cout<<80;
			for(int i=0;i<cnt;i++)cout<<8;
			cout<<endl;	
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
