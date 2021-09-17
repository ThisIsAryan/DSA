//Doubly linked list
//1<-->10<-->5<-->99<-->16
class Node{
    constructor(value){
        this.value = value;
        this.next = null;
        this.previous = null;
    }
}
class DoublyLinkedList{
    constructor(value){
        this.head = new Node(value);
        this.tail = this.head; //coz we have only one element
        this.length = 1;
    }

    append(value){
        const newNode = new Node(value);
        newNode.previous = this.tail;
        this.tail.next = newNode;
        this.tail = newNode;
        this.length++;
        return this;
    } //O(1)

    prepend(value){ //1-->10-->5-->16
        const newNode = new Node(value);
        newNode.next = this.head;
        this.head.previous = newNode;
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
            newNode.previous = leaderNode;
            leaderNode.next = newNode;
            followNode.previous = newNode;
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
            followNode.previous = leaderNode;
            this.length--;
        }
        return this;
    } //O(1)
}

const myLinkedList = new DoublyLinkedList(10);
myLinkedList.append(5);
myLinkedList.append(16);
myLinkedList.prepend(1);
console.log(myLinkedList); //1-->10-->5-->16

myLinkedList.insert(10, 99); //(index, value)
myLinkedList.printList(); //[ 1, 10, 5, 16, 99 ]
myLinkedList.insert(2, 45); 
myLinkedList.printList(); //[ 1, 10, 45, 5, 16, 99 ]

myLinkedList.remove(1);
myLinkedList.printList(); //[ 1, 45, 5, 16, 99 ]