#include<bits/stdc++.h>
using namespace std;
int k[15];
string a;
bool flag=false;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(k,0,sizeof(k));
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			int j=a[i]-'0';
			k[j]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=k[i];j++){
			cout<<i;
			
		}
	}
	return 0;
} 
