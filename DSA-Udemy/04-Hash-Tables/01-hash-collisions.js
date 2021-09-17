// In JS- hashing done using objects-
let log = console.log;
let user = {
    age : 52,
    name : 'Kylie',
    mahic : true,
    scream : function(){
        console.log('ahhhhhh!');
    } 
}

log(user.age); //O(1)
//adding a new propery- 
user.spell = 'abra kadabra'; //O(1)
log(user.spell);
user.scream(); //O(1) 

//Hash collisions ki theory in copy.