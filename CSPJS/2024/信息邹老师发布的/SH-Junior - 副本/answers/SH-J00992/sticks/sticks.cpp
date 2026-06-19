#include<bits/stdc++.h>
using namespace std;
string ans[100005]={"-1","-1","1","7","4","2","6","8","10","18","22","20","28","68","88","108","188","200","208","288","688","888"};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
    	int n;
    	cin>>n;
    	if(n<=21){
    		cout<<ans[n]<<endl;
    		continue;
		}
		int pd=n%7;
		if(pd==1){
			cout<<108;
		}else if(pd==2){
			cout<<188;
		}else if(pd==3){
			cout<<200;
		}else if(pd==4){
			cout<<208;
		}else if(pd==5){
			cout<<288;
		}else if(pd==6){
			cout<<688;
		}else if(pd==0){
			cout<<888;
			pd+=7;
		}
		int num=(n-pd)/7-2;
		for(int i=1;i<=num;i++){
			cout<<8;
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

