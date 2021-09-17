const arr = ['a', 'd', 'f', 'c', 'b'];
const baskets = [1, 23, 21, 3, 44, 22, 54];
console.log(arr.sort());
console.log(baskets.sort());//does not work as in JS, numbers converted to string before sort.

//localeCompare- https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/localeCompare
//Sorting ways- https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/sort

console.log(baskets.sort(function(a,b){
    return a - b;
})); //this will work

//visualize- https://www.toptal.com/developers/sorting-algorithms