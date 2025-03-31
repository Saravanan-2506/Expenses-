#include<iostream>
#include<string>
using namespace std;
class input{
    protected:
    char ch;
    string isource[30];
    double inarr[30];
    string idate[30];
    string esource[30];
    double exarr[30];
    string edate[30];
    int income=0,expense=0;

    public:
            void getincome(){
                double sum=0;
                int i=0;
                cout<<"Want to enter details (Y/N) :";
                cin>>ch;
                while((ch=='y'||ch=='Y') && i<30){              //changes made 
                    cout<<"Enter source of income:";
                    cin>>isource[i];
                    cout<<"Enter income:";
                    cin>>inarr[i];
                    cout<<"Enter date of income:";
                    cin>>idate[i];
                    sum=sum+inarr[i];
                    i++;
                    cout<<"Final income : "<<sum<<endl;
                    cout<<"Want to enter more details (Y/N) :";
                    cin>>ch;
                }
                income = i; 
                }
            void getexpense(){
                double sum=0;
                int j=0;
                cout<<"Want to enter details (Y/N) :";
                cin>>ch;
                while((ch=='y'||ch == 'Y') && j<30){                //changes made 
                    cout<<"Enter source of expense:";
                    cin>>esource[j];
                    cout<<"Enter amount spent:";
                    cin>>exarr[j];
                    cout<<"Enter date of expenditure:";
                    cin>>edate[j];
                    sum=sum+exarr[j];
                    j++;
                    cout<<"Final expenditure : "<<sum<<endl;
                    cout<<"Want to enter more details (Y/N) :";
                    cin>>ch;
                    
                }
                expense = j;
            }

        };
class view: public input{
    public:
        void viewincome(){
            cout<<"INCOME DETAILS\n";
            cout<<"DATE\tSOURCE\tINCOME"<<endl;
            for(int k=0;k<income;k++)
            {
                cout<<idate[k]<<"\t"<<isource[k]<<"\t"<<inarr[k]<<endl;
            }
        }
        void viewexpense(){
            cout<<"EXPENSE DETAILS\n";
            cout<<"DATE\tEXPENDITURE\tAMOUNT"<<endl;
            for(int k=0;k<expense;k++)
            {
                cout<<edate[k]<<"\t"<<esource[k]<<"\t"<<exarr[k]<<endl;
            }
        }
};

            



int main(){
    int cho;
    view obj1;
    cout<<"\n-----EXPENSE TRACKER-----\n"; //changes made
    while(true){
        cout<<"\n---Menu---\n1.Income\n2.Expenditure\n3.View income\n4.View expense\n5.Exit\nEnter the choice:"; //Changes made
        cin>>cho;
        switch(cho){
            case 1:
                obj1.getincome();
                break;
            case 2:
                obj1.getexpense();
                break;
            case 3:
                obj1.viewincome();
                break;
            case 4:
                obj1.viewexpense();
                break;
            case 5:
                cout<<"Closing the application";
                return 0;
            default:
                cout<<"Invalid Input. Enter choice from the menu";
                break;
         }
    }
    return 0;
}
