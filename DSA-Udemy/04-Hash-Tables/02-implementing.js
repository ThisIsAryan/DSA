class HashTable {
    constructor(size) {
        this.data = new Array(size);
    }

    _hash(key) {
        let hash = 0;
        for (let i = 0; i < key.length; i++) {
            hash = (hash + key.charCodeAt(i) * i) % this.data.length
        }
        return hash;
    } //Considered as O(1) coz fast.

    set(key, value) {
        let address = this._hash(key);
        //Now, as the size of our array is small (50), two keys can have the same hash value resulting in hash collisions. 
        //Therefore, we implement separate chaining by creating an array at a specific hash value.
        if (!this.data[address]) {
            this.data[address] = []
        }
        this.data[address].push([key, value]); 
        return this.data; //[ <23 empty items>, [ [ 'grapes', 10000 ] ], <26 empty items> ] - for first insertion (total- 50)
    } //O(1)

    get(key) {
        let address = this._hash(key);
        const currentBucket = this.data[address]
        if (currentBucket) {
            for (let i = 0; i < currentBucket.length; i++) {
                if (currentBucket[i][0] === key) {
                    return console.log(currentBucket[i][1]);
                }
            }
        }
        return console.log(undefined);
    } //Considered O(1), O(n) when hash collision. 
}

const myHashTable = new HashTable(50);
console.log(myHashTable.set('grapes', 10000))
myHashTable.get('grapes')
console.log(myHashTable.set('apples', 13))
myHashTable.get('apples')