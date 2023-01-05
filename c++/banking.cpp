#include <iostream>
#include <fstream>

using namespace std;



class bank_account{
    
    char name[80];
    int acc_num;
    long long int deposit;
    char acc_type;
    char info;
    int del;
    int acc_num1;
    long long int transfer;
    long int acc_pin;
    char type[50];
    
public:
    
    
    
void create(){
    cout<<"Enter account number:";
    cin>>acc_num;
    cout<<"Enter acoount holder's name: ";
    cin>>name;
    cout<<"Enter your pin:";
    cin>>acc_pin;
    cout<<"Enter type of account(savings,salary,fix deposit..etc): ";
    cin>>type;
    cout<<"Enter the amount to be deposited: ";
    cin>>deposit;
    cout<<"\nCongratulations!! Your account has been created..";
}

void display_acc(){
    cout<<"\nAccount number: "<<acc_num<<endl;
    cout<<"\nAcount holder's name: "<<name<<endl;
    cout<<"\nAccount type: "<<type<<endl;
    cout<<"\nBalance: "<<deposit<<endl;
}
void query(){
    cout<<"\nEnter your query regarding any field: ";
    cin>>info;
}

void acc_modify(){
    cout<<"Name to modify: ";
    cin.ignore();
    cin>>name;
    cout<<"\nEnter account type to be modified to: ";
    cin>>type;
}

void acc_delete(){
    cout<<"\nPress 1 if you are sure to close your account: ";
    cin>>del;
    
    if(del==1){
        cout<<"\nAccounted closed!";
    }
    else{
        cout<<"\nAccounted not closed!";
    }
}

void money_deposit(){
    cout<<"\nEnter amount to be deposited(>1000): "<<endl;
    cin>>deposit;
    if(deposit<1000){
        cout<<"\nPlease enter amount > Rs.1000";
    }
    else{
        cout<<"\nRs. "<<deposit<<"deposited in your account.";
    }
}

int balance_enquiry(){
    cout<<"\nBalance detail: ";
    return deposit;
}

void display_all(){
    
    cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"====================================================\n";
}

void net_bank(){
    cout<<"\nEnter account number where the money is to be transferred: "<<endl;
    cin>>acc_num1;
    cout<<"\nEnter amount to be transferred:Rs.  ";
    cin>>transfer;
    if(transfer>1000){
        cout<<"Rs. "<<transfer<<"credited to account no. "<<acc_num1<<endl;
    }
    else{
        cout<<"\nEnter an amount greater than Rs.1000."<<endl;
    }
    


};



int main()
{
    int ch;
	int num;
	long int pin;
	

	
	    cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t1. CREATE NEW ACCOUNT";
		cout<<"\n\n\t2. DEPOSIT AMOUNT";
		cout<<"\n\n\t3. NET BANKING";
		cout<<"\n\n\t4. BALANCE ENQUIRY";
		cout<<"\n\n\t5. MODIFY AN ACCOUNT";
		cout<<"\n\n\t6. CLOSE AN ACCOUNT";
		cout<<"\n\n\t7. FOR QUERY(HELPDESK)";
		cout<<"\n\n\t8. EXIT";
		cout<<"\n\n\tChoose your option: ";
		cin>>ch;
		
		switch (ch){
		    case'1':
		        create();
		        break;
		        
		    case '2':
		         cout<<"\nEnter your account number: ";
		         cin>>num;
		         cout<<"\nEnter your pin: ";cin>>pin;
		         void money_deposit();
		         break;
		         
		    case '3':
		            cout<<"\nEnter your account number: ";
		            cin>>num;
		            cout<<"\nEnter your pin: ";cin>>pin;
		            void net_bank();
		            break;
		      
		    case '4':
		            cout<<"\nEnter your account number: ";
		            cin>>num;
		            cout<<"\nEnter your pin: ";cin>>pin;
		            void balance_enquiry();
		            break;
		            
		            
		       case '5':
		            cout<<"\nEnter your account number: ";
		            cin>>num;
		            cout<<"\nEnter your pin: ";cin>>pin;
		            acc_modify();
		            break;
		      
		      case '6':
		            cout<<"\nEnter your account number: ";
		            cin>>num;
		            cout<<"\nEnter your pin: ";cin>>pin;
		            acc_delete();
		            break;
		            
		      case '7':
		            cout<<"\nEnter your account number: ";
		            cin>>num;
		            cout<<"\nEnter your pin: ";cin>>pin;
		            query();
		            break;
		      
		      case '8':
		            cout<<"\nThankyou for using our online banking system!!"<<endl;
		            break;
		      
		      default: cout<<"\a";
		      
		}
		
		cout<<"\n";
	    
	    return 0;

    }
};