#include <bits/stdc++.h>
using namespace std;
int v[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            v[s[i]-48]++;
        }
    }
    for(int i=9;i>=0;i--){
    	if(v[i]!=0){
			for(int j=0;j<v[i];j++){
				printf("%d",i);
			}
		}
    }
    return 0;
}

