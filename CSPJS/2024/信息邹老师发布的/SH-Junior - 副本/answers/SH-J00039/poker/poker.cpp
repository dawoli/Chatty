#include <bits/stdc++.h>
using namespace std;
    char s[53][2];
    int ans,cnt,n,h[5][14];
    int main(){
	freopen ("poker.in","r",stdin);
	freopen ("poker.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>s[i][0]>>s[i][1];
    	if (s[i][0]=='D'){
    		if (s[i][1]=='A'){
    			if (h[0][1]==0){
    				h[0][1]=1;
    				cnt++;
				}
			}
			else if (s[i][1]=='T'){
				if (h[0][10]==0){
    				h[0][10]=1;
    				cnt++;
				}
			}
			else if (s[i][1]=='J'){
				if (h[0][11]==0){
    				h[0][11]=1;
    				cnt++;
				}
			}
			else if (s[i][1]=='Q'){
				if (h[0][12]==0){
    				h[0][12]=1;
    				cnt++;
				}
			}
			else if (s[i][1]=='K'){
				if (h[0][13]==0){
    				h[0][13]=1;
    				cnt++;
				}
			}
			else{
				if (h[0][(int)s[i][1]]==0){
    				h[0][(int)s[i][1]]=1;
    				cnt++;
				}
			}
		}
		else if (s[i][0]=='C'){
			if (s[i][1]=='A'){
    			if (h[1][1]==0){
    				h[1][1]=1;
    				cnt++;
				}
			}
			else if (s[i][1]=='T'){
				if (h[1][10]==0){
    				h[1][10]=1;
    				cnt++;
				}
			}
			else if (s[i][1]=='J'){
				if (h[1][11]==0){
    				h[1][11]=1;
    				cnt++;
				}
			}
			else if (s[i][1]=='Q'){
				if (h[1][12]==0){
    				h[1][12]=1;
    				cnt++;
				}
			}
			else if (s[i][1]=='K'){
				if (h[1][13]==0){
    				h[1][13]=1;
    				cnt++;
				}
			}
			else{
				if (h[1][(int)s[i][1]]==0){
    				h[1][(int)s[i][1]]=1;
    				cnt++;
				}
			}
		} 
		else if (s[i][0]=='H'){
			if (s[i][1]=='A'){
    			if (h[2][1]==0){
    				h[2][1]=1;
    				cnt++;
				}
			}
			else if (s[i][1]=='T'){
				if (h[2][10]==0){
    				h[2][10]=1;
    				cnt++;
				}
			}
			else if (s[i][1]=='J'){
				if (h[2][11]==0){
    				h[2][11]=1;
    				cnt++;
				}
			}
			else if (s[i][1]=='Q'){
				if (h[2][12]==0){
    				h[2][12]=1;
    				cnt++;
				}
			}
			else if (s[i][1]=='K'){
				if (h[2][13]==0){
    				h[2][13]=1;
    				cnt++;
				}
			}
			else{
				if (h[2][(int)s[i][1]]==0){
    				h[2][(int)s[i][1]]=1;
    				cnt++;
				}
			}
		}
		else{
			if (s[i][1]=='A'){
    			if (h[3][1]==0){
    				h[3][1]=1;
    				cnt++;
				}
			}
			else if (s[i][1]=='T'){
				if (h[3][10]==0){
    				h[3][10]=1;
    				cnt++;
				}
			}
			else if (s[i][1]=='J'){
				if (h[3][11]==0){
    				h[3][11]=1;
    				cnt++;
				}
			}
			else if (s[i][1]=='Q'){
				if (h[3][12]==0){
    				h[3][12]=1;
    				cnt++;
				}
			}
			else if (s[i][1]=='K'){
				if (h[3][13]==0){
    				h[3][13]=1;
    				cnt++;
				}
			}
			else{
				if (h[3][(int)s[i][1]]==0){
    				h[3][(int)s[i][1]]=1;
    				cnt++;
				}
			}
		}
	}
    ans=52-cnt;
    cout<<ans;
    return 0;
	}
