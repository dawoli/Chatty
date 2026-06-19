#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int score[101]={};
	for(int i=1;i<=n;i++)
		cin>>score[i];
	int t=1,x,cnt=0;
	cin>>x;
	for(int i=1;i<=n;i++){
		if(score[i]>x) t++;
		if(score[i]==x) cnt++;
	}
	cout<<t<<' '<<cnt<<endl;
	return 0;
}
