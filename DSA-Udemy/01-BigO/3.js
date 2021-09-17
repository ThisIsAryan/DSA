//making code 1.js more efficient using break-
const name = ['momo', 'nemo', 'moto', 'doco', 'roco'];
function findingNemo(arr) {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] == 'nemo') {
            console.log('Found nemo')
            break; //reduces the number of iterations.
        }
    }
}
findingNemo(name)

//But, in Big-O, we look at the worst case.

let fruits = ['Apple', 'Banana']
fruits.forEach(function (item, index) {
    console.log(item, index)
})

//Ways of creating loops-
const fishes = ['momo', 'nemo', 'moto', 'doco', 'roco'];

function findingNemo1(arr) {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] == 'nemo') {
            console.log('Found nemo')
            break; //reduces the number of iterations.
        }
    }
}

function findingNemo2(arr) {
    arr.forEach(fish => {
        if (fish == 'nemo'){
        console.log('Found nemo')}
    })
}

function findingNemo3(arr) {
    for(let fish of arr){
        if(fish === 'nemo'){
            console.log('Found nemo');
        }
    }
}

findingNemo1(fishes)
findingNemo2(fishes)
findingNemo3(fishes)
