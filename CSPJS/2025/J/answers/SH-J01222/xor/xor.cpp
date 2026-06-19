#include<bits/stdc++.h>
using namespace std;
int a[11451*2],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a1,b;
	cin>>a1>>b;
	for(int i=1;i<=a1;i++){
		cin>>a[i];
	}
	if(b==1){
		for(int i=1;i<=a1;i++){
			if(a[i]==1){
				cnt++;
			}
		}
		cout<<cnt;
	}else{
		for(int i=1;i<=a1;i++){
			if(a[i]==0){
				cnt++;
			}else if(a[i]==a[i-1]){
				cnt++;
				a[i]=-1;
				cout<<2<<endl;
			}
		}
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
