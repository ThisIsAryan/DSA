// Simply merge-
function merge(array1, array2) {
    const mergeArray = [];
    var i = 0, j = 0;
    var array1Item = array1[0]; var array2Item = array2[0];
    while (array1Item) {
        mergeArray.push(array1[i]);
        i++;
        array1Item = array1[i]
    }
    while (array2Item) {
        mergeArray.push(array2[j]);
        j++;
        array2Item = array2[j]
    }
    return mergeArray;
}

//Merge sorted-
function mergeSorted(array1, array2) {
    const mergeArray = [];
    var i = 0, j = 0;
    var array1Item = array1[0]; var array2Item = array2[0];
    while (array1Item || array2Item) 
    {
    if(!array2Item || array1Item<array2Item) 
    {
        mergeArray.push(array1[i]);
        i++;
        array1Item = array1[i]
    }
    else
    {
        mergeArray.push(array2[j]);
        j++;
        array2Item = array2[j]
    }
    }
    return mergeArray;
}
const array1 = [1, 7, 9, 11];
const array2 = [5, 8, 10, 12, 15, 15, 18];
console.log(merge(array1, array2)); //1,  7,  9, 11,  5, 8, 10, 12, 15, 15, 18
console.log(mergeSorted(array1, array2)); //1,  5,  7,  8,  9, 10, 11, 12, 15, 15, 18