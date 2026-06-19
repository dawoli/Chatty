#include<bits/stdc++.h>
using namespace std;
int a[500010];
int n,k,cnt;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s;
	for(int j=1;j<=n-1;j++){
		s=a[j];
		for(int i=2;i<=n;i++){
				if(s==k){
					cnt++;
					s=a[i];
					i++;
				}
				s=s^a[i];
//				cout<<s<<' ';
				if(s==k){
					cnt++;
					s=a[i+1];
					i++;
				}
			}
			cout<<cnt;
			return 0;
		}
	}

