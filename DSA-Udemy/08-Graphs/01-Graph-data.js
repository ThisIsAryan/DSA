//Edge list -
const graph = [[0,2], [2,3], [2,1], [1,3]]; //arrays simply state connections.

//Adjacent list -
const graph = [[2], [2,3], [0,1,3], [1,2]]; //index is the node, values are the neighbours.

//Adjacent Matrix -
const graph = {
    0 : [0, 0, 1, 0],
    1 : [0, 0, 1, 1],
    2 : [1, 1, 0, 1],
    3 : [0, 1, 1, 0]
}//Same can be implemented using arrays. 
