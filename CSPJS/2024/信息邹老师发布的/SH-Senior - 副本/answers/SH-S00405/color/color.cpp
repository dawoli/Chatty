#include <iostream>
using namespace std;

int red, blue;
bool redused, blueused;
int n, score;
int a[1000010];
int T;

int solve(int i, int score){
	if(i>n)return score;
	int t = a[i];
	if(redused == true && t == red){
                score += red;
                redused = false;
                red = 0;
                return solve(i+1, score);
            }else if(blueused==true && t == blue){
                score += blue;
                blueused = false;
                blue = 0;
                return solve(i+1, score);
            }else if(redused == false){
                red = t;
                redused = true;
                return solve(i+1, score);
            }
            else if(redused == true && blueused == false){
            	int rr = red;
            	red = t;
            	int a = solve(i+1, score);
            	red = rr;
                blue = t;
                blueused = true;
                int b = solve(i+1, score);
                return max(a, b);
            }else if(blueused == true){
            	int bb = blue;
            	int rr = red;
                blue = t;
                int a = solve(i+1, score);
                blue = bb;
                red = t;
				int b = solve(i+1, score);
				red = rr;
				return max(a ,b);     
		}

}

int main() {
	
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            int t; cin >> t;
			a[i]=t;
        }

        cout << solve(1, 0) << endl;
    }
    return 0;
}
