#include<bits/stdc++.h>
using namespace std;
bool f[55];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	string a;
	for(int i=0;i<n;i++){
		cin>>a;
		int ind=0;
		if(a[0]==67) ind+=13;
		if(a[0]==72) ind+=26;
		if(a[0]==83) ind+=39;
		if(49<=a[1]&&a[1]<=57) ind+=a[1]-49;
		if(a[1]==84) ind+=9;
		if(a[1]==74) ind+=10;
		if(a[1]==81) ind+=11;
		if(a[1]==75) ind+=12;
		f[ind]=true;
	}
	int cnt=52;
	for(int i=0;i<52;i++){
		if(f[i]) cnt--;
	}
	cout<<cnt;
}
