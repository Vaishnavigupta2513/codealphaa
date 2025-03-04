#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void registerUser(){
string username,password,contact,gender;
cout<<"Enter Username:";
cin>>username;
cout<<"Enter Password:";
cin>>password; 
cout<<"Enter Contact No:";
cin>>contact; 
cout<<"Enter Gender:";
cin>>gender; 
ofstream file(username+".txt");
if(file.is_open()){
    file<<"Username:"<<username<<endl;
    file<<"Password:"<<password<<endl;
    file<<"Contact:"<<contact<<endl;
    file<<"Gender:"<<gender<<endl;
    file.close();
    cout<<"Registration Done"<<endl;

}
else{
    cout<<"Error!File is not opening"<<endl;
}
}
void loginuser(){
    string username,password,fileUsername,filePassword;
    cout<<"Enter Your Username:";
    cin>>username;
    cout<<"Enter Your Password:";
    cin>>password;
    ifstream file(username+".txt");
    if (file.is_open()){
    getline(file,fileUsername);
    getline(file,filePassword);
    file.close();
    if (fileUsername=="Username:"+username && filePassword=="Password:"+password){
        cout<<"Login Done"<<endl;
    }else{
        cout<<"Username or Password is Wrong"<<endl;
    }
    }else{
   cout<<"No user found"<<endl;
    }

}
int main(){
    int choice;
    cout<<"Welcome to Login Registration System.."<<endl;
    cout<<"1.Registration\n2.Login:"<<endl;
    cout<<"Enter Your Choice:";
    cin>>choice;
    if(choice==1){
        registerUser();
    }else if(choice==2){
        loginuser();
    
    }else{
        cout<<"Invalid Choice"<<endl;
    }
    return 0;
}