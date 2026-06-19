#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;
int S[MAXN][2*MAXN], len[MAXN];
int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	
	int T;
	cin >> T;
	while(T--){
		int n, k, q, l, lm = -1;
	    cin >> n >> k >> q;
	    for(int i=1; i<=n; i++){
		    cin >> l;
		    lm = max(lm, l);
		    for(int j=1; j<=l; j++){
			    cin >> S[i][j];
		    }
		    len[i] = l;
	    }
	    for(int i=1; i<=q; i++){
		    int r, c;
		    cin >> r >> c;
		    if(r == 1){
			    int flag = 0;
			    for(int j=1; j<=n; j++){
			        for(int k=1; k<=lm; k++){
				        if(S[j][k] == c){
					        cout << 1;
					        flag = 1;
					        break;
				        }
			        }
		        }
		        if(!flag){
		    	    cout << 0;
			    }
		    }else if(k == 200000){
		    	int flag = 0;
		    	for(int i=1; i<=n; i++){
		    		if(S[i][len[i]] == c){
		    			cout << 1;
		    			flag = 1;
		    			break;
					}
				}
				if(!flag){
					cout << 0;
				}
			}
		    
	    } 
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
