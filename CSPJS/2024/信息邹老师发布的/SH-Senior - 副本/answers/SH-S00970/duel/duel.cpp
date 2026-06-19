#include <bits/stdc++.h>
using namespace std;

int r[100005];
int s[100005];
int n,kill=0;
int nw, ne;
int amone=0, amtwo=0;
int va[5];
int vain=1;

//bool ok(int a, int b){
//	if (r[a]==-1 or r[b]==)
//}

bool two(){
	for (int i=1; i<=n; i++){
		if (r[i]>2) return false; 
	}
	return true;
}


bool onevalue(){
	int value=r[1];
	for (int i=1; i<=n; i++){
		if (r[i]!=value) return false;
	}
	return true;
}


bool twovalue(){
	for (int i=1; i<=n; i++){
		if (r[i]!=va[1] && r[i]!=va[2]){
			if (vain>2) return false;
			if (vain==1){
				va[vain]=r[i];    // replace 1 with index -> more solutions???
				vain++;
			}
			else if (vain==2){
				va[vain]=r[i];
				vain++;
			}
		}
	}
	if (vain==3) return true;
	else return false;
}




bool repeat(int n){
	for (int i=1; i<n; i++){
		if (r[i]==r[i+1]) return true;
	}
	return false;
}


bool ok(int a, int b){
	// A can be killed by B ?
//  Old SB method
//	if (s[a]==-1 || s[b]==-1 || s[b]==1) return false;
//	return true;
	
	if(s[b]==0 && s[a]!=-1 && r[a]<r[b]) return true;
	return false;
}







int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> r[i];
	
	// test sample 5~10 (25%) 
	if (two()){
		for (int i=1; i<=n; i++){
			if (r[i]==1) amone++;
		}
		amtwo = n - amone;
		cout << n-min(amone,amtwo);
		return 0;
	}
	
	// test if there are only two values, unkown scores (Maybe zero)
	if (onevalue()){
		cout << n;
		return 0;
	}
	
	// test if there are only two values, unkown scores
	if (twovalue()){
		for (int i=1; i<=n; i++){
			if (r[i]==va[1]) amone++;
		}
		amtwo = n - amone;
		cout << n-min(amone,amtwo);
		return 0;
	}
	
	// Strange methods end, true coding started
	// Sort for ease
	sort(r+1,r+n+1);
	
	if (!repeat(n)){
		cout << n-(n/2);
		return 0;
	}
	
	
	// The most most general situations !!!!!
	for (int i=1; i<n; i++){
		// while until ok
		for (int j=i+1; j<=n; j++){
			if (ok(i,j)){
				s[i]=-1;
				s[j]=1;
				kill++;
//				cout << "r[" <<i<< "]="<<r[i]<<"" << " is killed by "<< "r[" <<j<< "]="<<r[j]<<"" << endl;
				break;
			}
			else{
//				cout << "r[" <<i<< "]="<<r[i]<<"" << " is survived by "<< "r[" <<j<< "]="<<r[j]<<"" << endl;
				continue;
			}
		}
	}
	cout << n-kill;
	return 0;
}

