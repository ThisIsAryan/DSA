//Reverse a linked list - important
//1-->10-->5-->99-->16
class Node{
    constructor(value){
        this.value = value;
        this.next = null;
    }
}
class LinkedList{
    constructor(value){
        this.head = new Node(value);
        this.tail = this.head; //coz we have only one element
        this.length = 1;
    }

    append(value){
        const newNode = new Node(value);    
        this.tail.next = newNode;
        this.tail = newNode;
        this.length++;
        return this;
    } //O(1)

    prepend(value){ //1-->10-->5-->16
        const newNode = new Node(value);
        newNode.next = this.head;
        this.head = newNode;
        this.length++;
        return this;
    } //O(1)

    printList(){
        const array = [];
        let currentNode= this.head;
        while(currentNode !== null){
            array.push(currentNode.value);
            currentNode = currentNode.next;
        }
        return console.log(array);
    }

    traverseToIndex(index){ //lookup
        //check parameters
        let counter = 0;
        let currentNode = this.head;
        while(counter !== index){
            currentNode = currentNode.next;
            counter++;
        }
        return currentNode;
    } //O(1)

    insert(index, value){ 
        if (index === 0) {
            this.prepend(value);
            return this.printList();
        }
        if(index>=this.length){
            return this.append(value);
        }
        else{
            const newNode = new Node(value);
            const leaderNode = this.traverseToIndex(index-1); //leader node is the node we connect the new node to
            const followNode = leaderNode.next //or- this.traverseToIndex(index); //follow node is the node new node will point to.
            newNode.next = followNode;
            leaderNode.next = newNode;
            this.length++;
        }
        return this;
    }

    remove(index){ //delete
        if(index > this.length){
            return undefined;
        }
        else{
            const leaderNode = this.traverseToIndex(index-1);
            const followNode = this.traverseToIndex(index+1);
            leaderNode.next = followNode;
            this.length--;
        }
        return this;
    } //O(1)

    reverse() {
        if (!this.head.next) {
          return this.head;
        }
        let first = this.head;
        let second = first.next;
        //this.tail = this.head;
    
        while(second) {
          const temp = second.next;
          second.next = first;
          first = second;
          second = temp;
        }
    
        this.head.next = null;
        this.tail = this.head;
        this.head = first;
        console.log(this)
        return this;
    }
}

const myLinkedList = new LinkedList(10);
myLinkedList.append(5);
console.log(myLinkedList);
myLinkedList.reverse();