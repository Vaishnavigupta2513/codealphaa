#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Transaction{
    public:
    string type;
    double amount;
    string timestamp;
    Transaction(string t,double a,string time):type(t),amount(a),timestamp(time){}
};
class customer{
protected:
    int customerID;
    string name,phoneNo,address;
public:
    customer(int id,string n,string phone,string addrs){
    customerID=id;
    name=n;
    phoneNo=phone;
    address=addrs;
}
void viewDetails(){
    cout<<"Customer ID:"<<customerID<<endl;
    cout<<"Name:"<<name<<endl;
    cout<<"Phone No:"<<phoneNo<<endl;
    cout<<"Address:"<<address<<endl;
}

int getCustomerID(){
    return customerID;
}
};
class Account{
private:
int accountNo;
double balance;
vector<Transaction>transactions;
public:
    Account(int accntnumber,double intialDeposit){
        accountNo=accntnumber;
        balance=intialDeposit;
        transactions.push_back(Transaction("Initial Deposit",intialDeposit,"2025-03-01 10:00:00"));
    }

void deposit(double amount){
    if(amount>0){
        balance += amount;
        transactions.push_back(Transaction("Deposit",amount,"2025-03-01 10:30:00"));
        cout<<"Rs."<<amount<<"deposited"<<endl;
    }else{
        cout<<"Invalid Deposit amount"<<endl;
    }
}
void withdraw(double amount){
    if(amount>0 && amount <= balance){
        balance -= amount;
        transactions.push_back(Transaction("Withdraw",amount,"2025-03-01 11:00:00"));
        cout<<"Rs."<<amount<<"with draw"<<endl;
    }else{
        cout<<"Insufficient fund"<<endl;
    }
}
void transfer(Account& toAccount,double amount){
    if(amount>0 && amount <= balance){
        balance -= amount;
        transactions.push_back(Transaction("transfer",amount,"2025-03-01 11:30:00"));
        cout<<"Rs."<<amount<<"with draw"<<endl;
    }else{
        cout<<"Insufficient fund"<<endl;
    }
}

void viewaccntDetails(){
    cout<<"Account Number:"<<accountNo<<endl;
    cout<<"Balance:"<<balance<<endl;
    cout<<"Transaction History:"<<endl;
     for (int i = 0; i < transactions.size(); i++) {
         cout << transactions[i].timestamp << " | " << transactions[i].type << " | Rs. " << transactions[i].amount << endl;
     }
}
int getAccountNo()const{
    return accountNo;
}
double getBalance()const{
    return balance;
}
};

class banksystem{
private:
    vector<customer>customers;
    vector<Account>accounts;
public:
void createCustomer(){
int id;
string name, phoneNo, address;
cout<<"Enter Customer ID:";
cin>>id;
cin.ignore();
for(int i=0;i<customers.size();i++){
    if(customers[i].getCustomerID()==id){
        cout<<"Customer ID already exist."<<endl;
        return;
    }
    }

cout<<"Enter Customer Name:";
getline(cin,name);
cout<<"Enter Customer Phone Number:";
getline(cin,phoneNo);
cout<<"Enter Customer Address:";
getline(cin,address);
    customers.push_back(customer(id,name,phoneNo,address));
    cout<<"Customer Created!"<<endl;
}

void createAccount(){
int customerID,accountNo;
double initialDeposit;
cout<<"Enter customer Id:";
cin>>customerID;
bool customerFound=false;
    for(int i=0;i<customers.size();i++){
        if(customers[i].getCustomerID()==customerID){
            customerFound=true;
            break;
        }
    }
    if(!customerFound){
            cout<<"customer not found"<<endl;
            return;
}
cout<<"Enter Account Number";
cin>>accountNo;
for(int i=0;i<accounts.size();i++){
        if(accounts[i].getAccountNo()==accountNo){
            cout<<"Account No Already exist"<<endl;
            return;
        }
}
cout<<"Enter intial Deposit Amount:";
cin>>initialDeposit;
if(initialDeposit<=0){
    cout<<"Intial deposit must be greater than 0 "<<endl;
    return;
}
accounts.push_back(Account(accountNo,initialDeposit));
cout<<"Account created For customer ID:"<<customerID<<endl;
}
void depositMoney(){
int accountNo;
double amount;
cout<<"Enter Account No to deposit Money:";
cin>>accountNo;
cout<<"Enter Amount to Deposit:";
cin>>amount;
bool accountFound=false;
    for(int i=0;i<accounts.size();i++){
        if(accounts[i].getAccountNo()==accountNo){
            accounts[i].deposit(amount);
            accountFound=true;
            break;

        }
    }
    if(!accountFound){
    cout<<"Account Not found"<<endl;
    }
}
void withdrawMoney(){
int accountNo;
double amount;
cout<<"Enter Account No to Withdraw Money:";
cin>>accountNo;
cout<<"Enter Amount to Withdraw:";
cin>>amount;
bool accountFound=false;
    for(int i=0;i<accounts.size();i++){
        if(accounts[i].getAccountNo()==accountNo){
            accounts[i].withdraw(amount);
            accountFound=true;
            break;

        }
    }
    if(!accountFound){
    cout<<"Account Not found"<<endl;
    }
}

void transferMoney(){
int fromaccountNo;
int toaccountNo;
double amount;
cout<<"Enter Sender Account No:";
cin>>fromaccountNo;
cout<<"Enter Receiver Account No:";
cin>>toaccountNo;
cout<<"Enter Amount to Transfer:";
cin>>amount;
    Account* fromaccount = nullptr;
    Account* toaccount = nullptr;
    for(int i=0;i<accounts.size();i++){
        if(accounts[i].getAccountNo()== fromaccountNo){
            fromaccount = &accounts[i];
    }
    if(accounts[i].getAccountNo()== toaccountNo){
            toaccount = &accounts[i];

}
}
if(fromaccount && toaccount){
   
        fromaccount->transfer(*toaccount,amount);
    }else{
        cout<<"Sender and Receiver Account not found."<<endl;
    }
}

void viewcustomerDetails(){
    int customerID;
    cout<<"Enter Customer ID to view Details:";
    cin>>customerID;
    bool customerFound = false;
    for(int i=0;i<customers.size();i++){
        if(customers[i].getCustomerID()==customerID){
            customers[i].viewDetails();
            customerFound = true;
            break;

        }
    }
    if(!customerFound){
        cout<<"Customer Not Found"<<endl;
    }

}
void viewaccntDetails(){
    int accountNo;
    cout<<"Enter Account No to view Details:";
    cin>>accountNo;
    bool accountFound = false;
    for(int i=0;i<accounts.size();i++){
        if(accounts[i].getAccountNo()==accountNo){
            accounts[i].viewaccntDetails();
            accountFound = true;
            break;
        }
    }
     if(!accountFound){
        cout<<"Account Not Found"<<endl;
    }
}
};
int main(){
    banksystem bank;
    int choice;
    do{
        cout<<"Banking System\n";
        cout<<"1.Create Customer\n";
        cout<<"2.Create Account\n";
        cout<<"3.Deposit Money\n";
        cout<<"4.With Draw Money\n";
        cout<<"5.Transfer Money\n";
        cout<<"6.View Customer Details\n";
        cout<<"7.View Account Details\n";
        cout<<"8.Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
    switch(choice){
        case 1:
        bank.createCustomer();
        break;
        case 2:
        bank.createAccount();
        break;
        case 3:
        bank.depositMoney();
        break;
        case 4:
        bank.withdrawMoney();
        break;
        case 5:
        bank.transferMoney();
        break;
        case 6:
        bank.viewcustomerDetails();
        break;
        case 7:
        bank.viewaccntDetails();
        break;
        case 8:
        cout<<"Exit.\n";
        break;
        default:
        cout<<"Invalid Choice.\n";
        break;
    }


    }while(choice!=8);

    return 0;
}

