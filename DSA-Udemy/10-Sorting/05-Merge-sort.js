const numbers = [99, 44, 6, 2, 1, 5]//, 63, 87, 283, 4, 0];

function mergeSort(array) {
    if (array.length === 1) {
        return array;
    }
    // Split Array in into right and left
    const length = array.length;
    const middle = Math.floor(length / 2)
    const left = array.slice(0, middle)
    const right = array.slice(middle)
    console.log('left:', left);
    console.log('right:', right);


    return merge(
        mergeSort(left),
        mergeSort(right)
    )
}

function merge(left, right) {
    console.log('We Have- ', left, right);
    let result = [];
    let leftIndex = 0;
    let rightIndex = 0;
    while (leftIndex < left.length && rightIndex < right.length) //making sure we have items in the array.
    {
        if (left[leftIndex] < right[rightIndex]) {
            result.push(left[leftIndex]);
            leftIndex++;
        } else {
            result.push(right[rightIndex]);
            rightIndex++
        }
    }
    console.log('result', result);
    result = result.concat(left.slice(leftIndex)).concat(right.slice(rightIndex));
    console.log('We returned- ', result);
    return result;
} 


const answer = mergeSort(numbers);
console.log(answer);

//stable vs unstable- https://stackoverflow.com/questions/1517793/what-is-stability-in-sorting-algorithms-and-why-is-it-important