#include<bits/stdc++.h> 
using namespace std;
string s;
int a[1000005];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			n++;
			a[n]=1;
		}
		else if(s[i]=='2'){
			n++;
			a[n]=2;
		}
		else if(s[i]=='3'){
			n++;
			a[n]=3;
		}
		else if(s[i]=='4'){
			n++;
			a[n]=4;
		}
		else if(s[i]=='5'){
			n++;
			a[n]=5;
		}
		else if(s[i]=='6'){
			n++;
			a[n]=6;
		}
		else if(s[i]=='7'){
			n++;
			a[n]=7;
		}
		else if(s[i]=='8'){
			n++;
			a[n]=8;
		}
		else if(s[i]=='9'){
			n++;
			a[n]=9;
		}
		else if(s[i]=='0'){
			n++;
			a[n]=0;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)cout<<a[i];
}
