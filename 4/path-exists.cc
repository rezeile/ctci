#include <vector>
#include <cstdio>
using namespace std;

/*struct GraphNode {
	int value;
	bool visited;
	int weight;
	vector<GraphNode> adjacent;
};

bool findViaDFS(GraphNode source,GraphNode target) {
	source.visited = true;
	if(source == target) return true;
	for(int i = 0; i < source.adjacent.size(); i++) {
		GraphNode a = source.adjacent[i];
		if(!a.visited) {
			return findViaDFS(a,target);
		}
	}
	return false;
}

bool pathExists(GraphNode n1,GraphNode n2) {
	return findViaDFS(n1,n2) || findViaDFS(n2,n1);
}*/

int main() {
	freopen("path.txt","r",stdin);
	int V;
	scanf("%d",&V);
	for(int i = 0; i < V; i++) {
		
	}
	return 0;
}
