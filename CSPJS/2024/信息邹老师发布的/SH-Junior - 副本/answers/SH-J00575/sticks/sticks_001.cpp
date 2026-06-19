#include<bits/stdc++.h>
using namespace std;
void put(int sum){
	int a[6]={0,1,2,6,8},b[6]={6,2,5,6,7},c[10]={};
	int weishu;
	if(sum%7==0){
		weishu=sum/7;
		for(int i=0;i<weishu;i++){
			cout<<8;
		}
		cout<<endl;
	}else if(sum==1){
		cout<<-1<<endl;
	}else if(sum==6){
		cout<<6<<endl;
	}else if(sum%7==1){
		weishu=sum/7+1;
		cout<<10;
		for(int i=0;i<weishu-2;i++){
			cout<<8;
		}
		cout<<endl;
	}else if(sum%7==6){
		weishu=sum/7+1;
		cout<<80;
		for(int i=0;i<weishu-2;i++){
			cout<<8;
		}
		cout<<endl;
	}else{
		weishu=sum/7+1;
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int shuju[51]={},T;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>shuju[i];
	}
	for(int i=0;i<T;i++){
		put(shuju[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

