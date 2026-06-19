#include<bits/stdc++.h>
using namespace std;
int j,c,s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int b[100000];
	string a;
	getline(a);
	for(int i=0;i<a.size();i++)
		if(a[i]<=9){
			b[j]=a[i];
			j++;
		}
	for(int i=0;i<j;i++)
		if(b[i]<b[i+1]){
			c=b[i];
			b[i]=b[i+1];
			b[i+1]=c;
		}
	for(int i=0;i<j;i++){
		s*=10;
		s+=b[i];
	}
	cout<<s;
	return 0;
}
