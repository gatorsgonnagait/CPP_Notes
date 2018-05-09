#include <iostream>
using namespace std;

class NumericArray{

    private:
        int size;
        double * array;

    public:

        explicit NumericArray(int size){
            this->size = size;
            array = new double[size]{};// initializes all values to zero

        }
        ~NumericArray(){ // destructor, used to get rid of dynamically allocated memory
            delete [] array;
        }

        void setValue(int index, double value){
            if (index < size && index >= 0)
                array[index] = value;
            else
                throw out_of_range ("ArrayIndexOutOfBoundsException:   An attempt was made to access an element using an invalid subscript.");
        }

        double getValue(int index){
            if (index < size && index >= 0)
                return array[index];
            else
                throw out_of_range ("ArrayIndexOutOfBoundsException:   An attempt was made to access an element using an invalid subscript.");
        }

        double getMax(){
            double max = array[0];
            for (int i = 1; i < size; ++i) {
                if(array[i]>max){
                    max = array[i];
                }
            }
            return max;
        }

        double getMin(){
            double min = array[0];
            for (int i = 1; i < size; ++i) {
                if(array[i]<min){
                    min = array[i];
                }
            }
            return min;
        }

        double getAverage(){
            double sum = 0;
            for (int i = 1; i < size; ++i) {
                sum += array[i];
            }
            return sum/size;
        }

        int getSize(){
            return size;
        }

        void display(){
            for (int i = 0; i < size; ++i) {
                cout << array[i] << " ";
            }
            cout<<endl;
        }

};

int main() {
    NumericArray n1 = NumericArray(7);

    cout<< n1.getSize()<<endl;
    n1.setValue(0, 19);
    n1.setValue(1, 4);
    n1.setValue(2, 5);
    n1.setValue(3, 11);
    n1.setValue(4, 3);
    n1.setValue(5, 2);
    n1.setValue(6, 16);
    cout<< n1.getValue(4)<<endl;
    cout<< n1.getMax()<< endl;
    cout<< n1.getMin()<< endl;
    cout<< n1.getAverage()<<endl;
    n1.display();
    return 0;
}