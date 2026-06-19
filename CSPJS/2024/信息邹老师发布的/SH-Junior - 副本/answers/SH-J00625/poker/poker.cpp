#include<bits/stdc++.h>
using namespace std; 
int n,sum=52,k=1;
string a[100];
bool fjudge(string s){
	for(int i=1;i<k;i++){
		if(s==a[i]) return true;
	}
	return false;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string np;
		cin>>np;
		if(!fjudge(np)){
			sum--;
			a[k++]=np;
		}
	}
	cout<<sum;
	return 0;
}
