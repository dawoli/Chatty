#include<iostream>
using namespace std;

int ns;
int stick[100005] = {6,2,5,5,4,5,6,3,7,6};

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int i=10;i<=100000;i++){
		int t = i;
		int n[10];
		int len = 0;
		while(t){
			n[++len] = t % 10;
			t /= 10;
		}
		for(int j=len;j>=1;j--){
			stick[i] += stick[n[j]];
		}
	}
	for(int i=1;i<=t;i++){
		cin>>ns;
		bool flag = false;
		for(int j=1;j<=100000;j++){
			if(ns==stick[j]){
				cout<<j<<endl;
				flag = true;
				break;
			}
		}
		if(!flag){
			cout<<-1<<endl;
		}
	}
	return 0;
}




