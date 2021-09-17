const strings = ['a', 'b', 'c', 'd']
//for 32 bit - this strings takes 4 shelfs of storage = 32 bytes (8 bits * 4(one for each element))

//Push- 
strings.push('e') //O(1)
console.log(strings)

//Pop-
strings.pop() //O(1)
console.log(strings)

//Unshift-
strings.unshift('0') //O(n)
console.log(strings)

//splice-
console.log(strings.splice(2, 0, 'add'))
console.log(strings)