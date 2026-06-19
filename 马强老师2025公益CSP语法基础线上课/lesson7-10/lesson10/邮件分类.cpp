#include<iostream>
using namespace std;
int main(){
	//输入
	const int N=10001;
	int a[N]={},b[N]={},c[N]={};//a--10 b--20 c--30
	int n,x,acnt=0,bcnt=0,ccnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		switch(x/10000){
		case 10:a[acnt]=x;acnt++;break;
		case 20:b[bcnt]=x;bcnt++;break;
		case 30:c[ccnt]=x;ccnt++;break;
		}
	}
	cout<<"Beijing"<<endl;
	for(int i=0;i<acnt;i++)
		cout<<a[i]<<" ";
	cout<<endl<<"Shanghai"<<endl;
	for(int i=0;i<bcnt;i++)
		cout<<b[i]<<' ';
	cout<<endl<<"Tianjin"<<endl;
	for(int i=0;i<ccnt;i++)
		cout<<c[i]<<' ';
	return 0;
}
