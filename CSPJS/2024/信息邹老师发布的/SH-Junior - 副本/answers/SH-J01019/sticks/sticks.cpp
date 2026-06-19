#include<iostream>
#include<cstdio>
using namespace std;

int a[10]={6,2,5,5,4,5,6,3,7,6};

int sti(int n){
	int sum=0;
	int t=n;
	while(t>0){
		sum+=a[t%10];
		t/=10;
	}
	return sum;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		int cnt=1;
		cin>>n;
		if(n<2) cout<<"-1"<<endl;
		else{
			while(true){
				if(sti(cnt)==n){
					cout<<cnt<<endl;
					break;
				}	
				cnt++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
