#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005],t1,t2;
int n,q,ans = 0,m = 0,sizs[200005],sizt,s1b[200005] = {0},s2b[200005] = {0},t1b,t2b,tchab;
int schab[200005] = {0};
int sqb[200005] = {0},shb[200005] = {0},tqb,thb;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 0;i < n;i++){
		cin >> s1[i] >> s2[i];
		sizs[i] = s1[i].size();
		for(int k = 0;k < sizs[i];k++){
				if(s1[i][k]-'a' != 0){
	    			s1b[i] = k;
		    		break;
		    	}
			}
			for(int k = 0;k < sizs[i];k++){
				if(s2[i][k]-'a' != 0){
	    			s2b[i] = k;
		    		break;
		    	}
			}
			sqb[i] = min(s1b[i],s2b[i]);
			shb[i] = sizs[i]-max(s1b[i],s2b[i]);
			schab[i] = s1b[i]-s2b[i];
			if(i != 0){
				for(int j = 0;j < i;j++){
					if(s1b[i] == s1b[j]&&s2b[i] == s2b[j]&&sizs[i] == sizs[j]){
						schab[i] = -10000000;
						break;
					}
				}
			}
	}
	
	
	
	
	for(int i = 0;i < q;i++){
		ans = 0;
		cin >> t1 >> t2;
		sizt = t1.size();
		for(int k = 0;k < sizt;k++){
			if(t1[k]-'a' != 0){
	   			t1b = k;
	    		break;
	    	}
		}
		for(int k = 0;k < sizt;k++){
			if(t2[k]-'a' != 0){
	   			t2b = k;
	    		break;
	    	}
		}
		tqb = min(t1b,t2b);
		thb = sizt-max(t1b,t2b);
		tchab = t1b-t2b;
			
			
			
			
		if(tchab == 0)ans++;
		for(int j = 0;j < n;j++){
			if((tchab == schab[j])&&tqb >= sqb[j]&&thb >= sqb[j]){
				ans++;
			}
		}
			
		
		cout << ans << "\n";
}
	return 0;
}
