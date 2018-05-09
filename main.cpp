#include <iostream>

using namespace std;

static int customerCount = 0;


struct Customer {
    string accountID;
    string name;
    double accountBalance;

};

double validateBalance(double balance){
    while (balance < 0){
        cout << "Enter Valid Balance greater than 0" << endl;
        cin >> balance;
    }
    return balance;
}

bool isValidID(Customer  customerArray[], const string id, int size){

    bool found = false;
    for (int i = 0; i < size ; ++i) {
        if(customerArray[i].accountID.compare(id) ==0){
            found = true;
            break;
        }
    }
    return found;
}


void displayCustomer(Customer customerArray[]){
    cout<< "Enter Customer Number"<<endl;
    int num;
    cin >> num;
    cout<< customerArray[num].accountID<< " " <<customerArray[num].name<< " " << customerArray[num].accountBalance << endl;
}

Customer createCustomer(){
    string acc;
    string name;
    double balance;
    cout<< "Enter account ID" << endl;
    cin>> acc;
    cout << "Enter name" << endl;
    cin >> name;
    cout << "Enter Balance" << endl;
    cin >> balance;
    balance = validateBalance(balance);
    Customer c = {acc, name, balance};

    return c;
}



void modifyCustomer(Customer customerArray[], string id, int size){
    for (int i = 0; i < size ; ++i) {
        if(customerArray[i].accountID == id){

            cout << "Enter a new name"<< endl;
            string name;
            cin >> name;
            customerArray[i].name = name;
            cout << "Enter a new balance"<< endl;
            double balance;
            cin >> balance;
            balance = validateBalance(balance);
            customerArray[i].accountBalance = balance;
        }
    }
}



void displayAllCustomers(Customer customerArray[], int size){
    for (int i = 0; i < size ; ++i) {
        cout<< "Customer Number " << i<< endl;
        cout<< customerArray[i].accountID<< endl;
        cout<< customerArray[i].name<< endl;
        cout<< customerArray[i].accountBalance<< endl;
        cout<< endl;
    }
}


int main() {
    Customer customerArray [20];

    char input = 'n';

    while (input != '0'){
        cout<< "Press 0 to exit"<< endl;
        cout << "1: Display data for customer number" << endl;
        cout << "2: Create new customer" << endl;
        cout << "3: Modify customer (enter customer number)" << endl;
        cout << "4: Display all customers" << endl;
        cin>> input;

        switch (input){
            case '1' :
                displayCustomer(customerArray);
                break;
            case '2':{
                customerArray[customerCount] = createCustomer();
                customerCount++;
                break;
            }
            case '3': {
                cout << "Enter account ID of customer to modify" << endl;
                string id;
                cin >> id;
                if (isValidID(customerArray, id, customerCount)) {
                    modifyCustomer(customerArray, id, customerCount);
                }
                else
                    cout << "Not a valid id" << endl;
                break;
            }
            case '4':
                displayAllCustomers(customerArray, customerCount);
                break;

        }
    }
    return 0;
}
