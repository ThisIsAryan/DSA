//Calculating Big-O=>

function hey(arr){
    console.log(arr[0]) //O(1)
    console.log(arr[1]) //O(1)
}
//Overall - O(2) -> treated as O(1) -> constant time.

function funHallenge(input){
    let a = 10; //O(1)
    a = 50 + 3; //O(1) 
    for(let i = 0; i<input.length; i++){  //O(n)
        anotherfunc() //O(n)
        let stranger = true; //O(n)
        a++; //O(n)
    }
    return a; //O(1)
}
//Total => 1 + 1 + n + n + n + n + 1 => 3 + 4n.
//BigO => O(3+4n) = O(n) -> Linear Time.

function anotherFunChallenge(input) {
    let a = 5; //O(1)
    let b = 10; //O(1)
    let c = 50; //O(1)
    for (let i = 0; i < input; i++) { //O(n)
      let x = i + 1; //O(n)
      let y = i + 2; //O(n)
      let z = i + 3; //O(n)
  
    } 
    for (let j = 0; j < input; j++) { //O(n)
      let p = j * 2; //O(n)
      let q = j * 2; //O(n)
    }
    let whoAmI = "I don't know"; //O(1)
  }
  //Big-O => 4 + 7n => O(n)