class Node {
    constructor(value){
        this.value = value;
        this.next = null;
    }
}

class Queue {
    constructor(){
        this.first = null;
        this.last = null;
        this.length = 0;
    }
    peek(){
        return this.first;
    }
    enqueue(value){
        const newNode = new Node(value);
        if(this.length===0){
            this.first = newNode;
            this.last = this.first;
        }
        else{
            this.last.next = newNode;
            this.last = newNode;
        }
        this.length++;
        return this;
    }
    dequeue(){
        if(!this.first){
            return null;
        }
        if(this.first === this.last){
            this.last = null;
        }
        this.first = this.first.next;
        this.length--;
        return this;
    }
    isEmpty(){
        if(this.length===0){
            return true;
        }
        else{
            return false;
        }
    }
}

const myQueue = new Queue();
myQueue.enqueue('Aarav');
myQueue.enqueue('Aryan');
myQueue.enqueue('Ayaan');
console.log(myQueue);

console.log(myQueue.peek()); //Node { value: 'Aarav', next: null }

myQueue.dequeue();
myQueue.dequeue();
console.log(myQueue);
myQueue.dequeue();
console.log(myQueue);