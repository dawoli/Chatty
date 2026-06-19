#include<bits/stdc++.h>
using namespace std;
int n,r[100005],front,iff,o1,o2;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
    cin >> n ;
    for(int i=0;i<n;i++){
    	cin >> r[i];
    	if(r[i]!=1&&r[i]!=2){
    		iff=1;
		}else if(r[i]==1)o1++;
		else if(r[i]==2)o2++;
	}
    if(!iff){
    	if(o1>o2)cout << n-o2;
		else cout << n-o1;
	}else{
		sort(r,r+n);
        int k=1;
        while(k<=n){
        	if(r[k]>r[front])front++;
        	k++;
    	}
        cout << n-front;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
