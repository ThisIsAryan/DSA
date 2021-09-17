let log = console.log;
class Node {
    constructor(value){
        this.value = value;
        this.next = null;
    }
}

class Stack {
    constructor(){
        this.top = null;
        this.bottom = null;
        this.length = 0;
    }

    peek(){
        return this.top;
    }

    push(value){
        const newNode = new Node(value);
        if(this.length === 0){
            this.top = newNode;
            this.bottom = newNode;
        }
        else{
            const holdingPointer = this.top;
            this.top = newNode;
            this.top.next = holdingPointer;
        }
        this.length++;
        return this;
    }

    pop(){
        if(!this.top){
            return null;
        }
        if(this.top === this.bottom){ //or this.length === 1
            this.bottom = null;
        }
        //const holdingPointer = this.top; //use to store the pop element otherwise it will disappear
        this.top = this.top.next;
        this.length--;
        return this;
    }

    isEmpty(){
        if(this.top === null){
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

log(myStack.isEmpty());

log(myStack.peek());

myStack.pop();
myStack.pop();
log(myStack);
myStack.pop();
log(myStack);

log(myStack.peek());