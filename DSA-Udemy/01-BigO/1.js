//var name = ['aryan', 'rohan', 'raj', 'abhi', 'ram', 'chettri', 'mbappe', 'ronaldo', 'sergio', 'hardy', 'steven']
const large = new Array(100).fill('rohan');
function find(arr){
    let t1 = performance.now(); //check in browser, replit
    for(let i = 0; i < arr.length; i++)
    {
        if(arr[i] == 'rohan')
        {
            console.log('Found Rohan')
        }
    }
    let t2 = performance.now();
    console.log('It took', (t2-t1), 'milliseconds')
}
find(large)

//Time Complexity - O(n)