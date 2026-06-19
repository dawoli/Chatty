#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000010];
bool cmp(const int x,const int y){
	return x>y;
}
int main(){
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	
	
	cin >> s;
	int sz=s.size(),j=0;
	for(int i=0;i<sz;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[j]=(s[i]-'0');
			j++;
		}
	} 
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++){
		if(i==0&&a[i]==0){
			cout << 0;
			return 0;
		}
		cout << a[i];
	}
	
}
