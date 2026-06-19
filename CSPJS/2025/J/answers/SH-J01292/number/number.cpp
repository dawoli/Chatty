#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[100005],k=1,n=0;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='1'){
			a[k]=1;
			k++;
			n++;
		}
		if(s[i]=='2'){
			a[k]=2;
			k++;
			n++;
		}
		if(s[i]=='3'){
			a[k]=3;
			k++;
			n++;
		}
		if(s[i]=='4'){
			a[k]=4;
			k++;
			n++;
		}
		if(s[i]=='5'){
			a[k]=5;
			k++;
			n++;
		}
		if(s[i]=='6'){
			a[k]=6;
			k++;
			n++;
		}
		if(s[i]=='7'){
			a[k]=7;
			k++;
			n++;
		}
		if(s[i]=='8'){
			a[k]=8;
			k++;
			n++;
		}
		if(s[i]=='9'){
			a[k]=9;
			k++;
			n++;
		}
		if(s[i]=='0'){
			a[k]=0;
			k++;
			n++;
		}
	}
	sort(a,a+n+1);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
