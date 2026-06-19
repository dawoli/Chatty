#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char c[1000005];
	long long cnt=0;
	cin>>s;
	for(long long i=0;i<s.size();i++){
	    if(s[i]<='9'&&s[i]>='0'){
	    	c[cnt]=s[i];
	    	cnt++;
		}	
	}
	sort(c,c+cnt);
	for(long long i=cnt-1;i>=0;i--){
		cout<<c[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
