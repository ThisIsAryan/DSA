let counter = 0;
function inception(){
    console.log(counter)
    if(counter > 3){
        return 'done';
    }
    counter++;
    return inception(); //if return not used, return value will get indefined when the second inception function gets popped from the call stack.
    //in other words, we bubble up the return value to top using return inception()
}

console.log(inception());

//Real World problems- https://stackoverflow.com/questions/105838/real-world-examples-of-recursion