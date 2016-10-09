/* 
 * Solution for problem 4.2 of Cracking the Coding Interview. The 
 * reader is encouraged to purchase the 5th edition of the textbook
 * to view the problem statement. 
 *
 * Author: Eliezer Abate
 * Last Updated: September 26, 2016
 */

#include <vector>  // std::vector
#include <utility> // std::pair
#include <cstdlib> // std::exit
#include <cstdio>  // std::scanf, std::printf, std::freopen
using namespace std;

/*===============================================================
  					      SOLUTION 
 ===============================================================*/

/* 
 * We will choose to represent the input graph using an adjacency 
 * list. For the following graph: 
 *
 *                    [0]
 *                   /   \
 * 				    /     \
 *				   v       v
 *				  [1] <----[2]
 *				           /
 *						  /
 *					   	 v
 *					    [3]
 *	
 *
 * We would have the follwing input information:
 * 
 *   4
 *   2 1 2
 *   0
 *   2 1 3
 *   0
 *
 *
 * The first line will contain a single number V (in this case 4) representing the 
 * number of vertices in the graph. It will be followed by V lines containing the
 * one or more numbers. The first number indicated how many neighbors the ith vertex 
 * has. For example the 2nd vertex has two neighbors (1 and 3, respectively). Thus
 * the entry on the 2nd line (using 0-indexed numbering) is 2 1 3.
 */

typedef vector<vector<pair<int,int>>> AdjList;

/* function: findViaDFS(int s,int t, AdjList &graph, vector<bool> &visitedNodes);
 * --------------------------------------------------------------------------------
 * Given the index of a source vertex and a target
 * vertex this function returns true if a path 
 * exists between the source and the target. Otherwise
 * it returns false.
 */
bool findViaDFS(int source,int target,AdjList &graph, vector<bool> &visitedNodes) {
	visitedNodes[source] = true;
	if(source == target) return true;
	for(int i = 0; i < graph[source].size(); i++) {
		pair<int,int> node = graph[source][i];
		if(!visitedNodes[node.first]) {
			return findViaDFS(node.first,target,graph,visitedNodes);
		}
	}
	return false;
}

/* function: pathExists
 * -------------------------------------------------
 * This self explanatory function is a wrapper over
 * the findViaDFS function. Since the graph is 
 * directed it may be the case that a path from 
 * n1 to n2 may exist but not otherwise, or vice 
 * versa. Thus both checks are necessary.
 */
bool pathExists(int n1, int n2, AdjList &graph) {
	vector<bool> nodes1(graph.size());; // 1 if visited, 0 otherwise
	vector<bool> nodes2(graph.size());; // 1 if visited, 0 otherwise
	return findViaDFS(n1,n2,graph,nodes1) || findViaDFS(n2,n1,graph,nodes2);
}

/* 
 * function: populateGraph
 * ---------------------------------------------
 * Simple utitlity function that populates a graph
 * given a properly formatted input text
 */
void populateGraph(AdjList &graph,char *file) {
	freopen(file,"r",stdin);
	int V, total_neighbors, index, weight;
	scanf("%d",&V);
	for(int i = 0; i < V; i++) {
		vector<pair<int,int>> neighbors;
		scanf("%d ",&total_neighbors);
		for(int j = 0; j < total_neighbors; j++) {
			scanf("%d %d",&index,&weight);
			neighbors[j] = make_pair(index,weight);
		}
		graph[i] = neighbors;
	}
}

int main(int argc, char *argv[]) {
	if(argc <= 1) {
		printf("please pass a graph input file");
		exit(0);
	}
	AdjList graph;
	populateGraph(graph,argv[1]);
	return 0;
}
