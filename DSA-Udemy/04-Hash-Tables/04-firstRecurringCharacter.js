//Google Question
//Given an array = [2,5,1,2,3,5,1,2,4]:
//It should return 2
//Given an array = [2,1,1,2,3,5,1,2,4]:
//It should return 1
//Given an array = [2,3,4,5]:
//It should return undefined
function firstRecurringCharacter(input) {
    let map = {};
    for (let i = 0; i < input.length; i++) {
        if (map[input[i]] !== undefined) { //don't use if(map[input[i]]) here coz 0 is also false.
            return input[i]
        }
        else
            map[input[i]] = i;
    }
    return undefined;
} //O(n^2)
function firstRecurringCharacter2(input) {
    let map = {};
    for (let i = 0; i < input.length; i++) {
        if (map[input[i]]) { //we can use as instead of i, we are mapping to true
            return input[i]
        }
        else
            map[input[i]] = true;
    }
    return undefined;
} //O(n) and space complexity- O(n)

console.log(firstRecurringCharacter([2, 7, 7, 2, 3, 5, 1, 2, 4])) // 7
console.log(firstRecurringCharacter2([2, 7, 2, 3, 5, 1, 2, 4])) // 2

