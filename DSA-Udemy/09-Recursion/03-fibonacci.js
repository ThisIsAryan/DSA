// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34,.....

function fibonacciIterative(n){ //O(n)
    let arr = [0,1];
    for(let i = 2; i < n + 1; i++){
        arr.push(arr[i-2]+arr[i-1]);
    }
    return arr[n];
}
console.log(fibonacciIterative(8));


function fibonacciRecursive(n){ //O(2^n) //Exponential time complexity.
    if(n < 2){
        return n;
    }
    else{
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }
}
console.log(fibonacciRecursive(8));

//Tail call optimization - https://2ality.com/2015/06/tail-call-optimization.html