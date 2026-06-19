#include <iostream>
using namespace std;

int n,k,q;
int r,c;
int S[200005]={1},l[100005];
int fin;
bool ans;

int find(int x,int gl){
	for(int i=l[gl-1]+1;i<=l[gl];i++){
		if(S[i]==x) return i;
	}
	return 0;
}
string route;
void dfs(int rou,int len,int pos,int wer){
	if(ans) return;
	if(len<=0) return;
	if(rou==0&&S[pos]==c&&len<k){
		/*
		cout << "-----------" << endl;
		cout << r << ' ' << c << endl;
		cout << route << endl;
		cout << pos << ' ' << S[pos] << endl;
		for(int i=1;i<=l[n];i++) cout << S[i] << ' ';
		cout << endl;
		cout << "-----------" << endl;
		*/
		ans=1;
		return;
	}
	if(rou<0) return;
	if(!pos){
		for(int i=1;i<=n;i++){
			int get=find(1,i);
			if(get){
				string ort=route;
				route+=char(get+'0');
				dfs(rou-1,k,get,i);
				route = ort;
			}
		}
		return;
	}
	if(pos+1<=l[wer]){
		string ort=route;
		route+=char(pos+1+'0');
		dfs(rou,len-1,pos+1,wer);
		route=ort;
	}
	if(len<k){
		for(int i=1;i<=n;i++){
			if(i==wer) continue;
			int get=find(S[pos],i);
			if(get){
				string ort=route;
				route+=char(get+'0');
				dfs(rou-1,k,get,i);
				route=ort;
			}
		}
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	
	int T;
	cin >> T;
	while(T--){
		cin >> n >> k >> q;
		for(int i=1;i<=n;i++){
			int t;
			cin >> t;
			l[i]=l[i-1]+t;
			for(int j=l[i-1]+1;j<=l[i];j++){
				cin >> S[j];
			}
		}
		for(int i=1;i<=q;i++){
			ans=0;
			cin >> r >> c;
			dfs(r,k-1,0,0);
//			cout << 0 << endl;
			cout << ans << endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

