#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int sum=52;
    string tmp[n+9];
    for(int i=1;i<=n;i++){
        cin>>tmp[i];
        bool flag=true;
        for(int j=i-1;j>=1;j--){
        	if(tmp[i]==tmp[j]){
        		flag=false;
        		break;
			}
		}
		if(flag) sum--;
	}
	cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

