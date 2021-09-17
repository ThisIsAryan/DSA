#include <iostream>
using namespace std;
class array
{
public:
    int *arr;
    int size = 0;

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int insert(int x){
        arr[size++] = x;
        return arr[size];
    }
    void pop(){
        arr[size--] = 0;
    }
    void pop(int x){ 
        for(int i = 0; i<size;i++){ 
            if(arr[i]==x){
                for(;i<size;i++){
                    arr[i] = arr[i+1];
                }
                size--;
                break;
            }

        }
    }
};
int main()
{
    array a1;
    a1.insert(5);
    a1.insert(10);
    a1.insert(15);
    a1.insert(20);
    a1.insert(25);
    a1.print();
    a1.pop();
    a1.print();
    a1.pop(10);
    a1.print();
    return 0;
}