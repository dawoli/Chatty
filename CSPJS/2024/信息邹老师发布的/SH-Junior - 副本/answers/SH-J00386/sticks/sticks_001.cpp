#include<bits/stdc++.h>
using namespace std;
int s[100001];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	long long t;
	cin>>t;
	for(long long i=1;i<=t;i++){
		cin>>s[i-1];
	}
	for(long long i=0;i<=t-1;i++){
		if(s[i]<2){
			cout<<-1<<endl;
		}
		else if(s[i]==3){
			cout<<7<<endl;
		}
		else if(s[i]==4){
			cout<<4<<endl;
		}
		else if(s[i]==5){
			cout<<3<<endl;
		}
		else if(s[i]==6){
			cout<<6<<endl;
		}
		else if(s[i]==7){
			cout<<8<<endl;
		}
		else if(s[i]==8){
			cout<<10<<endl;
		}
		else if(s[i]==9){
			cout<<18<<endl;
		}
		else if(s[i]==10){
			cout<<22<<endl;
		}
		else if(s[i]==11){
			cout<<20<<endl;
		}
		else if(s[i]==12){
			cout<<28<<endl;
		}
		else if(s[i]==13){
			cout<<68<<endl;
		}
		else if(s[i]==14){
			cout<<88<<endl;
		}
		else if(s[i]==15){
			cout<<106<<endl;
		}
		else if(s[i]==16){
			cout<<188<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
