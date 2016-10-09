#include <cassert> // assert
#include <vector>
using namespace std;

typedef vector<vector<int>> Grid;
void paintFill(Grid &g,int x,int y,int color,int length,int width) {
	if(x < 0 || x > (width - 1)) return;
	if(y < 0 || y > (length -1)) return;
	if(g[x][y] != color) g[x][y] = color;
	if((x+1) < width && g[x+1][y] != color) 
			paintFill(g,x+1,y,color,length,width);
	if((x-1) > 0 && g[x-1][y] != color) 
			paintFill(g,x-1,y,color,length,width);
	if((y+1) < length && g[x][y+1] != color) 
			paintFill(g,x,y+1,color,length,width);
	if((y-1) > 0 && g[x][y-1] != color) 
			paintFill(g,x,y-1,color,length,width);

}

void paintFill(Grid &g,int x,int y,int color) {
	int length = g.size();
	assert(length > 0);
	int width = g[0].size();
	assert(width > 0);
	paintFill(g,x,y,color,length,width);
}

int main() {
	return 0;
}
