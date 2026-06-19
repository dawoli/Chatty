#include<bits/stdc++.h>
using namespace std;
int n;
set<string> a;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		string temp;
		cin>>temp;
		a.insert(temp);
	}
	printf("%d",52-a.size());
	return 0;
}
