function printFirstItemThenFirstHalfThenSayHi100Times(items) {
    console.log(items[0]);

    var middleIndex = Math.floor(items.length / 2);
    var index = 0;

    while (index < middleIndex) {
        console.log(items[index]);
        index++;
    }

    for (var i = 0; i < 100; i++) {
        console.log('hi');
    }
}
//O(1 + n/2 + 100) => O(n)

const array1 = ['a', 'b', 'c'];

array1.forEach(element => console.log(element));

boxes = [1,2,3,4,5,6,7,8,9,10];
function compressBoxes(boxes){boxes.forEach(boxes => console.log(boxes))}
//function compressBoxes(boxes){boxes.forEach(function(boxIt){console.log(boxes)}) }
compressBoxes(boxes)