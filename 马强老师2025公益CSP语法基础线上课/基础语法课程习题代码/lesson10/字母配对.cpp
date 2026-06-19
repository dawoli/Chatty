#include<iostream>
using namespace std;
int main(){
	int n;
	char s[30]={};
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	char c;
	cin>>c;
	c=c+32;
	int flag=0;
	for(int i=1;i<=n;i++){
		if(s[i]==c){
			flag=1;
			break;
		}
	}
	if(flag==1) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}
