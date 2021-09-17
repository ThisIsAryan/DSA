//Comparing arrays

const arr1 = ['s', 'r', 't', 'y']
const arr2 = ['w', 'l', 'r', 'o']

//=============================================================================================================
//Brute force approach-
function CompareArrays(arr1, arr2) {
    let i = arr1.length;
    let j = arr2.length;
    for (k = 0; k < i; k++) {
        for (l = 0; l < j; l++) {
            if (arr1[k] == arr2[l])
                return true
        }
    }
    return false
}
console.log(CompareArrays(arr1, arr2)) //Time Complexity- O(a*b) //Space Complexity- O(1)

//==============================================================================================================
//More efficient approach-
//array1 ==> obj {
//a: true;
//b: true;
//c: true;
//x: true;
//}
//array1 is converted to an object. 

//array2[index] == obj.properties

function CompareArrays2(arr1, arr2) {
    //loop through first array and create object where properties === items in the array
    //loop through second array and check if item in second array exists in created object.
    let map = {}; //object
    //Mapping array to object - 
    for (let i = 0; i < arr1.length; i++) { 
        if (!map[arr1[i]]) {
            const item = arr1[i];
            map[item] = true; //object with property a: true,.....
        }
    }
    console.log(map[arr1[1]])
    console.log(map)
    for (let j = 0; j < arr2.length; j++){
        if(map[arr2[j]]){  //dekh, agar arr2[j] ka koi element hoga arr1 k map m, to map[arr2[j]] uski key return krega jo true h. if k andr true aaya, condition execute huyi, true return hua.
            return true;
        }
    }
    return false;
}
console.log(CompareArrays2(arr1, arr2)) //Time Complexity O(a+b) //Space Complexity O(a)
//we are assuming 2 parameters. Eg. CompareArrays2(arr1, null) -> ERROR!!

//===============================================================================================================
//Language specific method to make code more readable and consize-

function CompareArrays3(arr1, arr2){
    return arr1.some(item => arr2.includes(item))
}
console.log(CompareArrays3(arr1, arr2))