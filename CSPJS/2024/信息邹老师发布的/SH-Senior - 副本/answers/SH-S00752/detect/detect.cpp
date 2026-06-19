#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1e5+10;

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	int T;
	int n,m,L,V;
	int d[N],v[N],a[N],p[N];
	cin>>T;
	while(T--){
		scanf("%d %d %d %d",&n,&m,&L,&V);
		int v_max = V*V;
		bool bz = true;
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&d[i],&v[i],&a[i]);
			if(a[i]<0)bz=false;
		}
		for(int i=0;i<m;i++){
			scanf("%d",&p[i]);
		}
		if(bz){
			int ans = 0;
			bool flag_s,flag_e;
			for(int i=0;i<n;i++){
				flag_s = false;
				flag_e = false;
				for(int j=0;j<m;j++){
					
					if(p[j] < d[i]){
						continue;
					}
					else{
						if( 2 * (p[j]-d[i]) * a[i] + v[i] * v[i] > v_max)
							ans++;
						break;
					}
				}
			}
			if(ans == 0){
				cout <<  m - 1 << endl;
			}
			else{
				cout << ans <<" " <<  m - 1 << endl;
			}
		}
		else{
			int ans = 0;
			bool flag_s,flag_e;
			vector<pair<int,int> > p_se;
			
			for(int i=0;i<n;i++){
				flag_s = false;
				flag_e = false;
				bool out = false;
				int s=0,e=m-1;
				for(int j=0;j<m;j++){
					if(flag_e) continue;
					int v_now = 2 * (p[j]-d[i]) * a[i] + v[i] * v[i]; 
					if(p[j] < d[i]){
						continue;
					}
					else if( v_now <= v_max && flag_s == true && flag_e == false){
						e = j - 1;
						flag_e = true; 
					}
					else if( v_now > v_max){
						
						if(!flag_s){
							ans++;
							out = true;
							s = j;
						}
						flag_s = true;
					}
				}
				if(out)
					p_se.push_back({s,e});
			}
		
			
			vector<pair<int,int> > ans_ppp;
			for(int j=0;j<p_se.size();j++){
				bool fond = false;
				for(int i=0;i<ans_ppp.size();i++){
					if(p_se[j].second < ans_ppp[i].first || p_se[j].first > ans_ppp[i].second){
						continue;
					}
					if(p_se[j].first > ans_ppp[i].first){
						ans_ppp[i].first =  p_se[j].first;
					}
					if(p_se[j].second < ans_ppp[i].second){
						ans_ppp[i].second =  p_se[j].second;
					} 
					fond = true;
				}
				if(!fond){
					ans_ppp.push_back(p_se[j]);
				}
				
			}
			cout << ans <<" "<< m - ans_ppp.size() << endl;
		}
		
	}
	
	
	return 0;
}

// damn i can't do it .......
