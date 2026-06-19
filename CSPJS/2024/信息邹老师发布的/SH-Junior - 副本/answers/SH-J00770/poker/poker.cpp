#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string a[10000];
	int n;
	cin>>n;
	int ans=52-n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				cout<<i<<" "<<j<<" ";
				cout<<a[i]<<" "<<a[j]<<endl;
				cout<<ans<<endl;
				ans++;
			}
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
