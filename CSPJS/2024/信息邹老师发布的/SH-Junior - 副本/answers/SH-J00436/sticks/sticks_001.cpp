#include<iostream>
#include<queue>
#include<string>
#define ll long long
using namespace std;
ll sticks[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ll t,n;
	cin>>t;
	queue<string>ans;
	while(t--){
		cin>>n;
		if(n<=1){ans.push("-1"); continue;}
		if(n%7==0){
			string tmpans="8";
			for(ll i=1; i<n/7; i++){
				tmpans+="8";
			}
			ans.push(tmpans);
			continue;
		}
		if(n%7==1){
			string tmpans="10";
			ll tmpp=(n-1)/7; tmpp--;
			for(ll i=0; i<tmpp; i++){tmpans+="8";}
			ans.push(tmpans);
			continue;
		}
		ll tmp=n%7;
		string tmpans;
		ll tmpp;
		if(tmp==2)tmpans="1";
		else if(tmp==3)tmpans="7";
		else if(tmp==4){
			tmpans="20";
			tmpp=(n-tmp)/7; tmpp;
			for(ll i=1; i<tmpp; i++){tmpans+="8";}
			ans.push(tmpans);	
			continue;	
		}
		else if(tmp==5)tmpans="5";
		else if(tmp==6)tmpans="6";
		tmpp=(n-tmp)/7; tmpp;
		for(ll i=0; i<tmpp; i++){tmpans+="8";}
		ans.push(tmpans);		
	}
	
	while(ans.size()){
		cout<<ans.front()<<endl;
		ans.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
