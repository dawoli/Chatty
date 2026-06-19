#include<iostream>
using namespace std;
string a;
int num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=a.size();
	a=" "+a;
	for(int i=1;i<=n;i++){
		//cout<<a[i];
		if(a[i]>='0'&&a[i]<='9'){
			int b=int(a[i]);
			num[b-48]++;
		}
	}for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++){
			cout<<i;
		}
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
