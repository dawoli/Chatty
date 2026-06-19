/*
  
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	char a,s[1000]={};
	cin>>a>>s;
	int cnt=0;
	double d;
	for(int i=0;i<strlen(s);i++)
		if(s[i]==a) cnt++;
	d=1.0*cnt/strlen(s);//0.1234==12.34 %
	d=d*100;
	printf("%.2lf",d);
	cout<<"%";
	return 0;
}
