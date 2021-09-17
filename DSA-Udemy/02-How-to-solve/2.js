//Check whether there is a pair with sum = given in an array.
// sum = 9
// [1,2,3,4,5] -> true
// [6,7,8,9,10] -> false

//Brute force-
function PairOfSum(arr, sum){
    for(let i = 0; i<arr.length; i++){
        for(let j = i+1; j<arr.length; j++){
            if(arr[i] + arr[j] == sum)
            return true;
        }
    }
    return false;
}
let arr = [1,2,5,7,11] 
let sum = 19
console.log(PairOfSum(arr, sum))
//Time Complexity- O(n^2), Space Complexity- O(1)

//Better approach-
function PairOfSum2(arr, sum){
    let temp = {};
    for(let i = 0; i<arr.length; i++){
    if(temp[arr[i]]){
    return true 
    }   
    else
    {
        let value = sum - arr[i]
        temp[value] = true
    }
}
return false;
}
console.log(PairOfSum2(arr, sum))

//Using set-
function PairOfSum3(array, sum){
    var check = new Set();
    for(let i = 0; i < array.length; i++){
        if(check.has(array[i])){
            return true;
        }
        check.add(sum - array[i])
    }
    return false;
}
console.log(PairOfSum3(arr, sum))
