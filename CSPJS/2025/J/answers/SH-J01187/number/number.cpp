#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int l[10]={};
	for(int i=0;i<int(a.size());i++){
		if(a[i]>='0' && a[i]<='9'){
			l[int(a[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<l[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
