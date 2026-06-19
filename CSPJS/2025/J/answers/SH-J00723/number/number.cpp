#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000]{};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	
	int j=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='9'){
			a[j]=9;
			j++;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='8'){
			a[j]=8;
			j++;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='7'){
			a[j]=7;
			j++;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='6'){
			a[j]='6';
			j++;
		}
	}for(int i=0;i<s.size();i++){
		if(s[i]=='5'){
			a[j]=5;
			 
			j++;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='4'){
			a[j]=4;
			j++;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='3'){
			a[j]=3;
			j++;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='2'){
			a[j]=2;
			j++;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			a[j]=1;
			j++;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			a[j]=0
			
			
			;
			j++;
		}
	}

	for(int i=1;i<j;i++){
		cout<<a[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
