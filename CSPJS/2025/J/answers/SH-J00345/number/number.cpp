#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string a;
int s=1;
long long b[100000005]={};

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,a);
	for(int i=0;i<=a.length();i++){
		if(a[i]=='0'){
			b[s]=0;
			s++;
		}
		if(a[i]=='1'){
			b[s]=1;
			s++;
		}
		if(a[i]=='2'){
			b[s]=2;
			s++;
		}
		if(a[i]=='3'){
			b[s]=3;
			s++;
		}
		if(a[i]=='4'){
			b[s]=4;
			s++;
		}
		if(a[i]=='5'){
			b[s]=5;
			s++;
		}
		if(a[i]=='6'){
			b[s]=6;
			s++;
		}
		if(a[i]=='7'){
			b[s]=7;
			s++;
		}
		if(a[i]=='8'){
			b[s]=8;
			s++;
		}
		if(a[i]=='9'){
			b[s]=9;
			s++;
		}
	}
	sort(b,b+s+1);
	if(a.length()==1){
		cout<<a[0]-48<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=s-1;i++){
		cout<<b[s+1-i];
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
