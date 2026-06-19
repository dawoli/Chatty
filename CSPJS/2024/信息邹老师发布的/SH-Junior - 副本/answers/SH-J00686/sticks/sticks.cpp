#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout); 
	int t;
	cin>>t;
	int cd=0;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		a[8]+=n/7;
		n%=7;
		if(n==6 and a[8]!=0){
			a[0]++;
			n=0;
		}
		else if(n==6){
			a[6]++;
			n=0;
		}
		else if(n==5){
			a[2]++;
		}
		else if(n==4){
			a[4]++;
		}
		else if(n==3)a[7]++;
		else if(n==2)a[1]++;
		else if (n==1){
			a[8]--;
			a[0]++;
			a[1]++;
		}
		if(a[4]and a[8]){
			a[8]--;
			a[4]--;
			a[0]++;
			a[2]++;
		}
		for(int i=1;i<=9;i++){
			if(a[i]){
				cout<<i;
				a[i]--;
				break;
			}
		}
		for(int i=0;i<=9;i++)
			while(a[i]!=0){
				cout<<i;
				a[i]--;
			}
		cout<<endl;
	}
	return 0;
}
