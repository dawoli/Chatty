#include<bits/stdc++.h>
using namespace std;
string a[100000];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int sum=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[j]==a[i]){
				sum+=1;
				a[j]='0'; 
			}
		}
	}
	cout<<(52-n+sum)<<endl;
	return 0;
}
