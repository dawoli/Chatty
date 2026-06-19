#include<iostream>
using namespace std;
int main(){
	int n,flag=1;
	int s[30]={};
	cin>>n;
	cin>>s[0];
	for(int i=1;i<n;i++){
		cin>>s[i];
		if(s[i]-s[i-1]!=1){
			flag=0;
			break;
		}
	}
		
	if(flag==1) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}
