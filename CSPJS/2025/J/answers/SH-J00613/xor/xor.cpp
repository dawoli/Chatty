#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5e5+10;
int n,k;
int a[N];
int b[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	cout<<b[k]<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

