/*
BFS is an algorithm for traversing or searching tree or graph data structures. 
It starts at the tree root, and explores all of the neighbor nodes at the 
present depth prior to moving on to the nodes at the next depth level. The aim 
of BFS algorithm is to traverse the graph as close as possible to the root node
. Queue is used in the implementation of the breadth first search. 
Steps  : 
Push the root node in the Queue.
Loop until the queue is empty.
Remove the node from the Queue.
If the removed node has unvisited child nodes, mark them as visited and insert 
the unvisited children in the queue.
*/
#include<stdio.h>
int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;
void bfs(int v) {
 for(i = 1; i <= n; i++)
 if(a[v][i] && !visited[i])
 q[++r] = i;
 if(f <= r) {
 visited[q[f]] = 1;
 bfs(q[f++]);
 }
}
void main() {
 int v;
 printf("\n Enter the number of vertices:");
 scanf("%d", &n);
 for(i=1; i <= n; i++) {
 q[i] = 0;
 visited[i] = 0;
 }
 printf("\n Enter graph data in matrix form:\n");
 for(i=1; i<=n; i++) {
 for(j=1;j<=n;j++) {
 scanf("%d", &a[i][j]);
 }
 }
 printf("\n Enter the starting vertex:");
 scanf("%d", &v);
 bfs(v);
 printf("\n The node which are reachable are:\n");
 for(i=1; i <= n; i++) {
 if(visited[i])
 printf("%d\t", i);
 else {
 printf("\n Bfs is not possible. Not all nodes are reachable");
 break;
 }
 }
}
