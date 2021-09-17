//Recursive-
function findFactorialRecursive(value){
    if(value===0){
        return 1;
    }
    return value*findFactorialRecursive(--value); //important- not value++ 
}
console.log(findFactorialRecursive(5)); //O(n)

//Iterative-
function findFactorialIterative(value){
    let answer = 1;
    for(let i = value; i != 0; i--){
        answer = answer*i;
    }
    return answer;
}
console.log(findFactorialIterative(5)); //O(n)
