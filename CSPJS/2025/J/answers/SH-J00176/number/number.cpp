#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[100001]={0};
	int cnt=0;
	cin>>s;
	long long l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i];
			cnt++;
		}  
	}
	char mx=47;
	int c;
	for(int i=0;i<cnt;i++){
		for(int j=0;j<cnt;j++){
			if(a[j]>mx){
				c=j;
				mx=a[j];
			}
		}
		cout<<a[c];
		mx=-1;
		a[c]=-1;
		c=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
