#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	int parts;
	cin >> parts;
	
	for (int partid = 0; partid < parts; partid++) {
		int width, height, steps, startx, starty, dest;
		cin >> width >> height >> steps >> startx >> starty >> dest;
		
		bool matrix[width][height];
		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {
				char c;
				cin >> c;
				
				matrix[x][y] = (c == 'x');
			}
		}
		
		vector<uint64_t> posits;
		posits.push_back(((uint64_t) startx) << 32 | starty);
		
		for (int currstep = 0; currstep < steps; currstep++) {
			int xb = startx;
			int yb = starty;
			
			if (dest == 0) starty++;
			else if (dest == 1) startx++;
			else if (dest == 2) starty--;
			else if (dest == 3) startx--;
			
			if (startx <= 0 || starty <= 0 || startx > width || starty > height || matrix[startx - 1][starty - 1]) {
				startx = xb;
				starty = yb;
				
				dest = (dest + 1) % 4;
			}
			
			uint64_t packedPos = ((uint64_t) startx) << 32 | starty;
			for (auto posit : posits) {
				if (packedPos == posit) goto je;
			}
			
			posits.push_back(packedPos);
			
			je: 
				continue;
		}
		
		cout << posits.size() << endl;
	}
	
	return 0;
}