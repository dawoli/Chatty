#include<bits/stdc++.h>
using namespace std;
int n,m,l,v0,t,chao[10005],ji,jii[10005];
int chaod[10005],chaoj[10005];
int p[10005],pp[10005],ans[105];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
    cin >> t;
    for(int q=0;q<t;q++){
    	cin >> n >> m >> l >> v0;
    	for(int i=0;i<n;i++){
    		int d,v,a;
			cin >> d >> v >> a;
			if(v>v0){
				chao[ji++] = i;
				chaod[ji] = d;
			}
		}
		for(int i=0;i<m;i++){
			cin >> p[i];
			for(int j=0;j<ji;j++){
				if(p[i]>chaod[j]){
					if(!chaoj[j])pp[i]++;
				}
			}
		}
		for(int i=0;i<m;i++){
			if(pp[i]!=0){
				ans[q]++;
			}
		}
		jii[q] = ji;
		ans[q] = m - ans[q];
	}
    for(int q=0;q<t;q++){
    	cout << jii[q] << ' ' << ans[q] << endl;
	}
    

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
