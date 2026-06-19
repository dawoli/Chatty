#include<bits/stdc++.h>
using namespace std;

const int maxn=14,maxl=24;
int T,n,k,q,l[maxn],s[maxn][maxl],r,c;
bool visited[maxn][maxl];

void check(){
	queue<pair<int,int>> Q; //{prevpeople,lastnumber}
	Q.push({-1,-1});
	memset(visited,false,sizeof(visited));
	for (int round=0; round<r; round++){
		long long Size=Q.size();
		for (int i=0; i<Size; i++,Q.pop()){
			auto prev=Q.front();
			auto prevpeople=prev.first,lastnumber=prev.second;
			for (int curpeople=0; curpeople<n; curpeople++){
				if (curpeople==prevpeople) continue;
				if (lastnumber==-1){
					for (int length=1; length<min(k,l[curpeople]); length++){
						Q.push({curpeople,s[curpeople][length]});
					}
					continue;
				}
				for (int curnum=0; curnum<l[curpeople]; curnum++){
					if (s[curpeople][curnum]!=lastnumber) continue;
					for (int length=1; length<min(k,l[curpeople]-curnum); length++){
						if (visited[curpeople][curnum+length]) continue;
						Q.push({curpeople,s[curpeople][curnum+length]});
						visited[curpeople][curnum+length]=true;
					}
				}
			}
		}
	}
	while (not Q.empty()){
		auto cur=Q.front();
		auto number=cur.second;
		if (number==c){
			cout<<"1\n";
			return;
		}
		Q.pop();
	}
	cout<<"0\n";
}

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	
	cin>>T;
	for (int i=0; i<T; i++){
		cin>>n>>k>>q;
		for (int j=0; j<n; j++){
			cin>>l[j];
			for (int m=0; m<l[j]; m++){
				cin>>s[j][m];
			}
		}
		for (int j=0; j<q; j++){
			cin>>r>>c;
			check();
		}
	}
	
} 
