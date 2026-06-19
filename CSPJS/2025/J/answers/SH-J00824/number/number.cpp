#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(char a,char b){
	return a>b;
}
string s;
char a[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i];
			cnt++;
		} 
        
    } 
	sort(a,a+cnt,cmp); 
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}	
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
