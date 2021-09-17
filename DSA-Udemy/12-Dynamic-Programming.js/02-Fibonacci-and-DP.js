//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233,....
let calculations = 0;
function fibonacci(n){
    calculations++;
    if(n<2){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

console.log(fibonacci(30), calculations);//832040 2692537
//This is O(2^n) time and O(1) space.


//Now, let's use DP to reduce this to O(n). This is possible as most of our calculations like fib(1), fib(2), etc. are repeated.
calculations = 0;
function fibonacciMaster(){
    let cache = {};
    return function fib(n) {
        calculations++;
        if (n in cache){
            return cache[n];
        }
        else{
            if(n < 2){
                return n;
            }
            else{
                cache[n] = fib(n-1) + fib(n-2);
                return cache[n];
            }
        } 
    }
}

const fasterFib = fibonacciMaster(); //we do this to create the cache variable and use the function returned in next step.
console.log(fasterFib(30), calculations); //832040 59
//This is O(n) time and O(n) space.

// We have 59 calculations using DP and 2692537 calculations using simply recursion.

//Bottom-up approach-

function finbonacciMaster2(n){
    let answer = [0, 1];
    for(let i = 2; i <= n; i++){
        answer.push(answer[i-2] + answer[i-1]);
    }
    return answer.pop();
}

console.log(finbonacciMaster2(30));

