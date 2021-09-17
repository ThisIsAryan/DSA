const numbers = [99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0];

function insertionSort(array) {
    const length = array.length;
    for (let i = 0; i < length; i++) {
        if (array[i] < array[0]) {
            //move number to the first position
            array.unshift(array.splice(i, 1)[0]);
        }
        else {
            //only sort the numbers smaller than the numbers to their left. This is what makes insertion sort faster for an almost sorted array.
            if (array[i] < array[i - 1]) {
                //find where the number should go-
                for (let j = 1; j < i; j++) {
                    if (array[i] >= array[j - 1] && array[i] < array[j]) {
                        //move number between j-1 and j. Remember, j starts with 1.
                        array.splice(j, 0, array.splice(i, 1)[0]);
                    }
                }
            }
        }
    }
    return array;
}

console.log(insertionSort(numbers));