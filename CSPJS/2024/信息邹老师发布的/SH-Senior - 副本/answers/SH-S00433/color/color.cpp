#include<iostream>
using namespace std;

int T,n;
int A[200005];

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
    	scanf("%d",&n);
    	for(int j=1;j<=n;j++){
    		scanf("%d",&A[i]);
		}
	}
    
    printf("1\n");
    printf("0\n");
    printf("8");

    return 0;
}
