#include<bits/stdc++.h>
using namespace std;
string pk[55];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	int x=n;
	for(int i=1;i<=n;i++)
    cin>>pk[i];
	for(int i=1;i<=n;i++){
		int sum=1;
		for(int j=i+1;j<=n;j++){
			if(pk[i]==pk[j])
			{
				sum++;
				if(sum<=2)
				x--;
			}
		}
	}
	cout<<52-x<<endl;
	return 0;
} 
