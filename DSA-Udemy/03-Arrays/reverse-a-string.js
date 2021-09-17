// In JS, strings are immutable.
function reverse1(str) {
    // check input-
    if(!str || str.length < 1 || typeof(str) !== "string"){ //doesn't necessarily need to be "string", can be anything within " " or ' '
        console.log("Wrong input");
    }
    // pushing items to an array and converting to string.
    const temp = []; var size = str.length;
    for (var i = size; i != 0; i--) { 
        temp.push(str[i - 1]);
    }
    return temp.join(''); //.toString will separate array elements with comma.
}

function reverse2(str){ //spliting to array and joining-
    return str.split('').reverse().join('');
}

const reverse3 = str => [...str].reverse().join(''); //modern JS syntax, [...str] splits the string.

var str = "I am Aryan";
console.log(reverse1(str));
console.log(reverse2(str));
console.log(reverse3(str));
