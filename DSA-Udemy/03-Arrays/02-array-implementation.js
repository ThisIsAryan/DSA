class MyArray {
    constructor() {
        this.length = 0;
        this.data = {};
    }

    get(index) {
        return this.data[index]
    }

    push(item) {
        this.data[this.length] = item; //to add item at last index
        this.length++; //to increase length
        return this.length; //typically such functions return the length.
    }

    pop() {
        const lastItem = this.data[this.length - 1]; //not this.length--
        delete this.data[this.length - 1]; //not this.length--
        this.length--;
        return lastItem; //undefined
    }

    delete(index) {  //O(n)
        const item = this.data[index];
        delete this.data[index];
        //Now, we have to shift index of all following elements by 1.
        this.shiftItems(index); //O(n)
        return item;
    }

    shiftItems(index) {
        for (let i = index; i < this.length - 1; i++) {
            this.data[i] = this.data[i + 1];
        }
        delete this.data[this.length - 1];
        this.length--;
    }

}

const newArray = new MyArray();
console.log(newArray); //MyArray { length: 0, data: {} }
console.log(newArray.get(0)); //undefined

newArray.push('Hi');
newArray.push('You');
newArray.push('!');
console.log(newArray); //MyArray { length: 3, data: { '0': 'Hi', '1': 'You', '2': '!' } }

newArray.pop();
console.log(newArray); //MyArray { length: 2, data: { '0': 'Hi', '1': 'You' } }

newArray.delete(1); //'You' (index of 1)
console.log(newArray);


