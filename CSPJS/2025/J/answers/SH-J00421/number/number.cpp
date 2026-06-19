#include<bits/stdc++.h>
#define ll long long
using namespace std;
char a;
ll nums[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a){
		if('0'<=a&&a<='9'){
			nums[a-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=nums[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
