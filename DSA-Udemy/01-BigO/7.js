//Space Complexity-
function boo(n) {
    for (let i = 0; i < n; i++) {
        console.log('booooo!')
    }
}
boo(5)
//Space complexity is O(1) as no elements added except i. This is irrespective of input.

function arrayOfHiNtimes(n) {
    let HiArr = [];
    for (let i = 0; i < n; i++) { //O(1)
        HiArr[i] ='Hi' //O(n)
    }
    return HiArr;
}
console.log(arrayOfHiNtimes(6))
//Space complexity is O(n) as an array is created with n elements, which takes n spaces.
