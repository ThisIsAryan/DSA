//10-->5-->16

let myLinkedList = {
    head: {  //head is the very first item of linked list.
        value: 10,   //data value we wanna store.
        next: {
            value: 5,
            next: {
                value: 16,
                next: null
            }
        }   //pointer/refernce to next node.
    } //{ } is a node
} //10 points to 5 points to 16 points to null.

//Using this logic, will create a class-
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

}

const myLinkedList1 = new LinkedList(10);
myLinkedList1.append(5);
myLinkedList1.append(16);
myLinkedList1.prepend(1);
console.log(myLinkedList1);