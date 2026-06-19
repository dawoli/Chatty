#include<bits/stdc++.h>
using namespace std;
const int N=1000009;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=0;
	for(int i=0;i<s.size()+1;i++){
		if(s[i]=='1'){
			a[j]=1;
			j++;
		}
		if(s[i]=='2'){
			a[j]=2;
			j++;
		}
		if(s[i]=='3'){
			a[j]=3;
			j++;
		}
		if(s[i]=='4'){
			a[j]=4;
			j++;
		}
		if(s[i]=='5'){
			a[j]=5;
			j++;
		}
		if(s[i]=='6'){
			a[j]=6;
			j++;
		}
		if(s[i]=='7'){
			a[j]=7;
			j++;
		}
		if(s[i]=='8'){
			a[j]=8;
			j++;
		}
		if(s[i]=='9'){
			a[j]=9;
			j++;
		}
		if(s[i]=='0'){
			a[j]=0;
			j++;
		}
	}
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
}
