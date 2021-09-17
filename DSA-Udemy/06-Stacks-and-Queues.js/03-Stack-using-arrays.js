let log = console.log;
class Stack {
    constructor(){
        this.array = [];
    }

    peek(){
        return this.array[this.array.length-1];
    }

    push(value){
        this.array.push(value);
        return this;
    }

    pop(){
        this.array.pop();
        return this;
    }

    isEmpty(){
        if(this.array.length === 0){
            return true;
        }
        else{
            return false;
        }
    }
}

const myStack = new Stack();
myStack.push('Google');
myStack.push('Discord');
myStack.push('Udemy');
log(myStack); 

log(myStack.isEmpty());

log(myStack.peek());

myStack.pop();
myStack.pop();
log(myStack);
myStack.pop();
log(myStack);

log(myStack.peek());