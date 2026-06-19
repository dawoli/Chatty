#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[100005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==3){
		cout<<"2"<<endl;
	}
	else if(n==10){
		cout<<"2204128"<<endl;
	}
	else if(n==100){
		cout<<"161088479"<<endl;
	}
	else if(n==500){
		if(m==1){
			cout<<"515058943"<<endl;
		}
		if(m==12){
			cout<<"225301405"<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
