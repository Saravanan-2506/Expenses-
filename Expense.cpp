#include<iostream>
#include<string>
using namespace std;
class input{
    protected:
    char ch;

    public:
            void getincome(string source[],double inarr[],string idate[]){
                double sum=0;
                int i=0;
                cout<<"Want to enter details (Y/N) :";
                cin>>ch;
                while(ch=='y'||ch=='Y'){              //changes made 
                    cout<<"Enter source of income:";
                    cin>>source[i];
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
                    
                }
            void getexpense(string source[],double inarr[],string idate[]){
                double sum=0;
                int i=0;
                cout<<"Want to enter details (Y/N) :";
                cin>>ch;
                while(ch=='y'||ch == 'Y'){                //changes made 
                    cout<<"Enter source of expense:";
                    cin>>source[i];
                    cout<<"Enter amount spent:";
                    cin>>inarr[i];
                    cout<<"Enter date of expenditure:";
                    cin>>idate[i];
                    sum=sum+inarr[i];
                    i++;
                    cout<<"Final expenditure : "<<sum<<endl;
                    cout<<"Want to enter more details (Y/N) :";
                    cin>>ch;
                    
                }
            }

        };


            



int main(){
    int cho;
    string isource[20];
    double inarr[20];
    string idate[20];
    string esource[20];
    double exarr[20];
    string edate[20];
    input obj;
    cout<<"\n-----EXPENSE TRACKER-----\n"; //changes made
    while(true){
        cout<<"\n---Menu---\n1.Income\n2.Expenditure\n3.View income\n4.View expense\n5.Exit\nEnter the choice:"; //Changes made
        cin>>cho;
        switch(cho){
            case 1:
                obj.getincome(isource,inarr,idate);
                break;
            case 2:
                obj.getexpense(esource,exarr,edate);
                break;
            case 3:

                break;
            case 4:

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
