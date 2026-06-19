#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	vector<int> b;
	int c=0;
	for(int i=0;i<a.length();i++){
		if(a[i]>=48&&a[i]<=57){
			b.push_back(a[i]-48);
			c++;
		}
	}
	for(int i=0;i<c;i++){
		for(int j=0;j<c-1;j++){
			if(b[j]<b[j+1]){
				int d=b[j+1];
				b[j+1]=b[j];
				b[j]=d;
			}
		}
	}
	for(int i=0;i<c;i++){
		cout<<b[i];
	}
	return 0;
}
