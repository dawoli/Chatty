#include<bits/stdc++.h>
using namespace std;
string s;
int mat[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    int k=s.size();
    for(int i=0;i<k;i++){
    	if(s[i]>='0' && s[i]<='9'){
    		mat[s[i]-'0']+=1;
		}
	}
	for(int i=9;i>=0;i--)
		for(;mat[i]>0;mat[i]--){
			cout<<i; 
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
