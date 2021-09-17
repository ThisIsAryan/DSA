// DFS is good for shortest path problem. But, here, we do not take into account the 
//weight of path(edge).

//In google map, some road may be faster than the other. DFS will not care.

//Therefore, we use Bellman-Ford or Dijkstra algorithms.

//read- https://medium.com/basecs/finding-the-shortest-path-with-a-little-help-from-dijkstra-613149fbdc8e

//Bellman-Ford can also accomodate negative weights, while Dijkstra's algo.
//Dijkstra's algo runs faster than Bellman-Ford(worst case here is O(n^2));
