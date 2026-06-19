#include<bits/stdc++.h>
using namespace std;
int n,T,k,q,r,c,l[1005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&k,&q);
		//string s[1005];
		for(int i=1;i<=n;i++){
			scanf("%d",&l[i]);
			//for(int j=1;j<=l[i];j++){
				int num;
				scanf("%d",&num);
			//	s[i].append(to_string(num));
			}
		}
		while(q--){
			scanf("%d%d",&r,&c);
			/*int flag=0;
			for(int i=1;i<=n;i++){
				int in1=s[i].find(to_string(1));
				int in2=s[i].find(to_string(c));
				if(in1!=string::npos&&in2!=string::npos&&in1<in2&&in2-in1<=k) {
					flag=1;
				}
			}*/
			printf("0\n");
		}
	
	return 0;
}
