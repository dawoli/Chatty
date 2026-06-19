#include<bits/stdc++.h>
using namespace std;
int T;
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		int n,A[100005];
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>A[i];
		cout<<rand()%(*max_element(A+1,A+n+1)*2)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
