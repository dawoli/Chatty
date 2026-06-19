#include <bits/stdc++.h>
using namespace std;
int a;
int b[100000];
int c[15];
int d=0;
int ans[15];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>a;
	for(int i=0;i<=14;i++){
		ans[i]=0;
	}
	for(int i=0;i<a;i++){
		cin>>c[d];
		for(int i=0;i<c[d];i++){
			cin>>b[i];
		}
		for(int i=0;i<c[d];i++){
			for(int k=i+1;k<=c[d]-1;k++){
				if(b[i]==b[k]){
					ans[d]+=b[i];
					break;
				}
			}
		}
		d++;
	}
	for(int i=0;i<a;i++){
		cout<<ans[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
}

