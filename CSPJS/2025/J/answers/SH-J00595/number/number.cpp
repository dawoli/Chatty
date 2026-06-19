#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num[12]={};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(auto c:s){
    	if('0'<=c&&c<='9'){
    		int n=c-48;
    		num[n]++;
		}
	}
	for(int i=9;i>=0;i--)
		for(num[i];num[i]>0;num[i]--){
			cout<<i;
		}
    fclose(stdin);
    fclose(stdout);
	return 0;
}

