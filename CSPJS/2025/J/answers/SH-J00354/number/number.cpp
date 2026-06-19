#include<bits/stdc++.h>
using namespace std;
string a;
int n;
int i;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("/d",&a);
	int n=a.size();
	if(n==0){
		cout<<5<<endl;
		return 0;
	}
	else{
		for(int i=0;i<=9;i++){
			if(n[i]>=0&&n[i]<=9){
			cout<<n[i]<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
