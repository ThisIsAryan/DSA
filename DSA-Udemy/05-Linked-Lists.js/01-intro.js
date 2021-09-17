// const backet = ['apples', 'grapes', 'pears'];
// apples
// 8947 --> grapes
//           8742 --> pears
//                     372 --> null

// pointers- A refernce to something else in memory.
let obj1 = { a: true};
let obj2 = obj1; //obj2 points to obj1
obj1.a = 'Not True';
console.log('1', obj1);
console.log('2', obj2); //changes here too.
delete obj1;
console.log('1', obj1);
console.log('2', obj2); //still have obj2 coz our computer are going to delete the memory that is unused. Because obj2 is referencing obj1, it may not get deleted.
//This is called garbage collection. 
