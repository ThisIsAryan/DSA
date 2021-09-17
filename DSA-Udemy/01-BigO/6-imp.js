//log pairs of elements in the box-
box = [1, 2, 3, 4, 5];
function logAllPairsOfArray(box) {
    for (let i = 0; i < box.length; i++) {
        for (let j = 0; j < box.length; j++) {
            console.log(box[i], box[j])
        }
    }
}
logAllPairsOfArray(box)
//O(n^2)

//print all numbers and then all pair sums
function printAllNumbersAndThenAllPairSums(arr){
    console.log('These are the numbers:')
    arr.forEach(x=>console.log(x))
    console.log('And these are the sum of pairs')

    arr.forEach(function (firstElement){
        (arr.forEach(function (secondElement){
            console.log(firstElement + secondElement)
        })
    )}
)}
printAllNumbersAndThenAllPairSums([1,2,3,4,5])
//O(n + n^2) => O(n^2)
