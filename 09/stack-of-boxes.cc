#include <algorithm>
#include <set>
using namespace std;

struct Box {
	int height;
	int width;
	int depth;
};

int cmpBoxes(Box &b1, Box &b2) {
	int b1_dim = b1.height + b1.width + b1.depth;
	int b2_dim = b2.height + b2.width + b2.depth;
	return b1_dim > b2_dim;
}

set<Box> tallestStack(set<Box> boxes) {
	sort(boxes.begin(),boxes.end(),cmpBoxes);
	set<Box>::iterator i;
	for(i = boxes.begin(); i != prev(boxes.end()); i++) {
		Box b1 = *i;
		Box b2 = *(++i);
		i--;
		int b1_dim = b1.height + b1.width + b1.depth;
		int b2_dim = b2.height + b2.width + b2.depth;
		if(b1_dim - b2_dim < 3)
			boxes.erase(++i);
			i--;
	}
	return boxes;
}

int main() {
	return 0;
}
