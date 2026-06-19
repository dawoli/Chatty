#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	int n,q;
	scanf("%d %d",&n,&q);
	const int con=n;
	struct s{
		string s1;
		string s2;
	}a[con];
	string t1,t2;
	for (int i=0;i<n;++i){
		cin>>a[i].s1>>a[i].s2;
	}
	for (int i=0;i<q;++i){
		cin>>t1>>t2;
		for(int j=1;j<t1.size();++j){
			for (int k=j;k<t2.size();++k){
				printf("%s",t1[0]);
			}
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
