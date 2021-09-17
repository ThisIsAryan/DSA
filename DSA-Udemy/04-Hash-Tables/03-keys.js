//allowing iteration through all the keys of hash table in the previous code-
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
    }

    set(key, value) {
        let address = this._hash(key);
        if (!this.data[address]) {
            this.data[address] = []
        }
        this.data[address].push([key, value]); 
        return this.data; 
    } 

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
    } 

    keys() {
        if (!this.data.length) {
          return undefined
        }
        let result = []
        // loop through all the elements
        for (let i = 0; i < this.data.length; i++) {
            // if it's not an empty memory cell
            if (this.data[i]) {
              // but also loop through all the potential collisions
              if (this.data[i].length > 1) {
                for (let j = 0; j < this.data[i].length; j++) {
                  result.push(this.data[i][j][0])
                }
              } 
              else {
                result.push(this.data[i][0][0])
              } 
            }
        }
        return result; 
      }
}

const myHashTable = new HashTable(50);
myHashTable.set('grapes', 10000);
myHashTable.get('grapes'); //10000
myHashTable.set('apples', 13);
myHashTable.get('apples'); //13
myHashTable.set('apples', 15); //Not gonna add.
myHashTable.get('apples'); //Still 13.
myHashTable.set('oranges', 2);
myHashTable.get('oranges'); //2
console.log(myHashTable.keys()); //takes a lot of time as we go through all the 50 spaces.