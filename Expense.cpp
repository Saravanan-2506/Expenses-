#inlcude<iostream>
#include<string>
using namespace std;
class expense{

    protected:
            double income;
            double expense;
            string i_date ,e_date;
            string isource , esource;
    public:
            void getincome(){
                cout<<"Enter source of income:";
                cin>>isource;
                cout<<"Enter income:";
                cin>>income;
                cout<<"Enter date of income:";
                cin>>i_date;
            }

            void getexpense(){
                cout<<"Enter source of expense:";
                cin>>esource;
                cout<<"Enter expense amount:";
                cin>>expense;
                cout<<"Enter date of expense:";
                cin>>e_date;
            }

            

}

int main(){

}
