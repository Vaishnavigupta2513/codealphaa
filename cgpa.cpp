#include<iostream>
#include<string>
using namespace std;
float calculating_CGPA(int numberCourses){
    float totalCredits=0,totalGradePoints=0;
    string grade;
    int credits;
    for(int i=0;i<numberCourses;i++){
        cout<<"Enter Course Details:"<<i+1<<endl;
        cout<<"Enter Grade{O,A+,A,B,B+,C,P,F}:"<<endl;
        cin>>grade;
        cout<<"Enter The Credit Of Course:"<<endl;
        cin>>credits;
        float gradePoint=0;
       
            if (grade=="O"){
                gradePoint=10;
                cout<< "gradePoint=10"<<endl;
            }
            else if (grade=="A+"){
                gradePoint=9;
                cout<< "gradePoint=9"<<endl;
            }
            else if (grade=="A"){
                gradePoint=8;
                cout<< "gradePoint=8"<<endl;
            }
            else if (grade=="B"){
                gradePoint=7;
                cout<< "gradePoint=7"<<endl;
            }
            else if (grade=="B"){
                gradePoint=6;
                cout<<"gradePoint=6"<<endl;
            }
            else if (grade=="C"){
                gradePoint=5;
                cout<< "gradePoint=5"<<endl;
            }
            else if (grade=="P"){
                gradePoint=4;
                cout<< "gradePoint=4"<<endl;
            }
            else if (grade=="F"){
                gradePoint=2;
                cout<< "gradePoint=2"<<endl;
            }
            else{
                cout<< "invalid Grade";
            }
          


        
        totalGradePoints+=gradePoint * credits;
        totalCredits += credits;

}
return (totalCredits!=0)?(totalGradePoints/totalCredits):0;
}
int main(){
    int numberCourses;
    cout<<"Enter the number of courses:"<<endl;
    cin>>numberCourses;
    float cgpa = calculating_CGPA(numberCourses);
    cout<<"Your CGPA:"<<cgpa<<endl;
    return 0;
}
