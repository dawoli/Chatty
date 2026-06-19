#include<bits/stdc++.h>
using namespace std;
int T, n, m, k1, x1, y1, d1, ans;
bool a[1005][1005], vis[1005][1005],vis2[1005][1005];
char temp;

int dfs(int x, int y, int d, int k){
	if (k == 0)
	   return 0;
	if (d == 0){
	    int t = 0, temp = ans;
	    if (y < m){
	    	for (int i = y + 1; i <= m; i++)
	    	    vis2[x][i] = vis[x][i];
	        for (int i = y + 1; i <= m; i++){
       	        if (a[x][i] == 0)
       	            break;
       	        else{
       	            t++;
				    if (!vis[x][i]){
					    ans++;
					    vis[x][i] = 1;
				    }	
		     	}
	        }
			if (k >= t)
       	        dfs(x, y + t, 1, k - t - 1);
       	    else{
       	        ans = temp;
                for (int i = y + 1; i <= y + k; i++){
       	            if (a[x][i] == 0)
       	                break;
       	            else{
       	                t++;
				        if (!vis2[x][i]){
					        ans++;
					        vis[x][i] = 1;
				       }	
		     	   }
	            }     	        
       	        return 0;
			}   
		}
        else{
        	if (k > 1){
        		dfs(x, y, 1, k - 1);
			}	
		}    
	}
	if (d == 1){
	    int t = 0, temp = ans;
	    if (x < n){
	    	for (int i = x + 1; i <= n; i++)
	    	    vis2[i][y] = vis[i][y];
	        for (int i = x + 1; i <= n; i++){
       	        if (a[i][y] == 0)
       	            break;
       	        else{
       	            t++;
				    if (!vis[i][y]){
					    ans++;
					    vis[i][y] = 1;
				    }	
		     	}
	        }
	        if (k >= t)
       	        dfs(x + t, y, 2, k - t - 1);
       	    else{
      	      	ans = temp;
    	        for (int i = x + 1; i <= x + k; i++){
       	            if (a[i][y] == 0)
       	                break;
       	            else{
       	                t++;
				        if (!vis2[i][y]){
					        ans++;
					        vis[i][y] = 1;
				        }	
		     	    }
	            }
               	return 0;
			}
		}
        else{
        	if (k > 1){
                dfs(x, y, 2, k - 1);     		
			}
		}

	}
	if (d == 2){
	    int t = 0, temp = ans;
	    if (y > 1){
	        for (int i = y - 1; i >= 1; i--)
	    	    vis2[x][i] = vis[x][i];
	        for (int i = y - 1; i >= 1; i--){
       	        if (a[x][i] == 0)
       	            break;
       	        else{
       	            t++;
				    if (!vis[x][i]){
					    ans++;
					    vis[x][i] = 1;
				    }	
		     	}    
	        } 
	        if (k >= t)
       	        dfs(x, y - t, 3, k - t - 1);
       	    else{
       	        ans = temp;
       	        for (int i = y - 1; i >= y - k; i--){
           	        if (a[x][i] == 0)
       	                break;
       	            else{
       	                t++;
				        if (!vis2[x][i]){
					        ans++;
					        vis[x][i] = 1;
				        }	
		     	    }    	        	
				}
       	        return 0;
			}
		}
        else{
        	if (k > 1){
        		dfs(x, y, 3, k - 1); 
		    }	
		}
	}
	if (d == 3){
	    int t = 0, temp = ans;
	    if (x > 1){
	    	for (int i = x - 1; i >= 1; i--)
	    	    vis2[i][y] = vis[i][y];
	        for (int i = x - 1; i >= 1; i--){
       	        if (a[i][y] == 0)
       	            break;
       	        else{
       	            t++;
				    if (!vis[i][y]){
					    ans++;
					    vis[i][y] = 1;
				    }	
		     	}
	        }
			if (k >= t)
       	        dfs(x - t, y, 0, k - t - 1);
       	    else{
       	       	ans = temp;
    	        for (int i = x - 1; i >= x - k; i--){
       	            if (a[i][y] == 0)
       	                break;
       	            else{
       	                t++;
				        if (!vis2[i][y]){
					        ans++;
					        vis[i][y] = 1;
				       }	
		     	   }
	            }   	       	
       	        return 0;
			}	
		}
        else{
            if (k > 1){
                dfs(x, y, 0, k - 1);           	
		   }      	
		}
	}
} 

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n >> m >> k1;
		cin >> x1 >> y1 >> d1;
        for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
                vis[i][j] = 0;
                vis2[i][j] = 0;
                a[i][j] = 0;
			}
		}
		ans = 1;
		vis[x1][y1] = 1;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin >> temp;
				if (temp == '.')  a[i][j] = 1;
				else  a[i][j] = 0;
			}
		}
		dfs(x1, y1, d1, k1);
		cout << ans << endl;
	}
}
