#include<iostream>
using namespace std;
int n,T;
int mp[22]={0,0,1,7,4,2,6,8,10,18,22,20,28,80,88,108,188,200,208,288,808,888};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n<=21){
			cout<<mp[n]<<endl;
			continue;
		}
		cout<<mp[n%7+14];
		string p="";
		for(int i=3;i*7<=n;i++)p+='8';
		cout<<p<<endl;
	}
	return 0;
} 
