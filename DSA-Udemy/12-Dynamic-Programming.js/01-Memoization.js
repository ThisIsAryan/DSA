function addTo80(n) {
    console.log('Long Time');
    return n + 80;
}
console.log(addTo80(5));
console.log(addTo80(5));
console.log(addTo80(5));
//output-
/* 85
   Long Time
   85
   Long Time
   85 */
//Here, long time(consider thia a time taking process) is executed thrice even though it is not required to run every time.

//Therefore- we use caching-> Memoization

let cache = {};
function memoizedAddTo80(n) {
    if (n in cache) {
        return cache[n];
    }
    else {
        console.log('long time');
        cache[n] = n + 80; //cache = {n: n+80}
        return cache[n];
    }
}
console.log(memoizedAddTo80(5));
console.log(memoizedAddTo80(5));
console.log(memoizedAddTo80(5));
//output-
/* long time
   85
   85
   85 */

//Note- Ideally, we don't want to fill cache in global scope (outside our function).
//In JS- we use closure for bringing in the cache to function.
function BettermemoizedAddTo80() {
    let cache = {};
    return function (n) {
        if (n in cache) {
            return cache[n];
        }
        else {
            console.log('long time');
            cache[n] = n + 80; //cache = {n: n+80}
            return cache[n];
        }
    }
}
const memoized = BettermemoizedAddTo80();
console.log('1', memoized(5));
console.log('2', memoized(5));