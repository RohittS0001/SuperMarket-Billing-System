#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;
class bill{
    private:
    string item;
    int rate, quantity;
    public:
    bill():item(""),rate(0),quantity(0){

    }
    void setItem(string Item){
        item=Item;
    }
     void setRate(int Rate){
        rate=Rate;
    }
    void setQuantity(int Quantity){
        quantity=Quantity;
    }

    string getItem(){
        return item;
    }
    int getRate(){
        return rate;
    }
    int getQuantity(){
        return quantity;
    }
void addItem(){
    bool close=false;
    while(!close){
        int choice;
        cout<<"\t\t 1. ADD."<<endl;
        cout<<"\t\t 2. CLOSE. "<<endl;
        cout<<"\t\t ENTER THE CHOICE : ";
        cin>>choice;
        if(choice==1){
            system("cls");
            string item;
            int rate,quant;
            cout<<"\t\t ENTER ITEM NAME        : ";
            cin>>item;
            setItem(item);

            cout<<"\t\t ENTER THE RATE 0F ITEM : ";
            cin>>rate;
            setRate(rate);

            cout<<"\t\t ENTER THE QUANTITY     : ";
            cin>>quant;
            setQuantity(quant);

            ofstream out("C:\\Users\\Rohit\\OneDrive\\Desktop\\billing system\\billing_system1.txt", ios::app);

            if (!out) {
                cout << "\t\t ERROR: FILE CAN'T OPEN!!" << endl;
            } else {
                out << getItem() << " : " << getRate() << " : " << getQuantity() << endl;
                out.close();
                cout << endl << "\t\t" << getItem() << " : Rate-" << getRate() << " : Quantity-" << getQuantity() << endl << endl;
                cout << "\t\t ITEMS ADDED SUCCESSFULLY" << endl << endl;
                Sleep(6000);
            }
        }

        else if (choice == 2) {
            system("cls");
            close = true;
            cout << "\t\t BACK TO MAIN MENU" << endl;
            Sleep(1000);
        }
    }
}
void printbill(){
    system("cls");
    int count=0;
    bool close=false;
    while(!close){
        system("cls");
        int choice;
        cout<<"\t\t 1. ADD ITEM TO THE BILL."<<endl;
        cout<<"\t\t 2. PRINT BILL."<<endl;
        cout<<"\t\t ENTER THE CHOICE : ";
        cin>>choice;
        if(choice==1){
            string item;
            int quant;
            cout<<"\t\t ENTER THE ITEM:";
            cin>>item;
            cout<<"\t\t ENTER QUANTITY:";
            cin>>quant;

            ifstream in("C:\\Users\\Rohit\\OneDrive\\Desktop\\billing system\\billing_system1.txt");
            ofstream out("C:\\Users\\Rohit\\OneDrive\\Desktop\\billing system\\bill_temp.txt");

            string line;
            bool found=false;
            while(getline(in, line)){
                stringstream ss(line);
                string itemname;
                int itemrate;
                int itemquant;
                char delimiter;
                ss>>itemname>>delimiter>>itemrate>>delimiter>>itemquant;
                if (item==itemname){
                    found =true;
                    if(quant<=itemquant){
                        int amount = itemrate*quant;
                        cout<<"\t\t ITEM | RATE | QUANTITY | AMOUNT "<<endl;
                        cout<<"\t\t"<<itemname<<"\t"<<itemrate<<"\t"<<quant<<"\t"<<amount<<endl;
                        int newQuant=itemquant-quant;
                        itemquant = newQuant;
                        count += amount;
                        if (newQuant > 0) {
                            out << itemname << " : " << itemrate << " : " << newQuant << endl;
                        }
                    }else {
                        cout << "\t SORRY, NOT ENOUGH STOCK FOR " << item << "!" << endl;
                        out << line << endl;
                        }
                }else{
                    out<<line<<endl;
                }
            }
            if(!found){
                cout<<"\t ITEM NOT AVAILABLE"<<endl;
            }
            out.close();
            in.close();
            remove("C:\\Users\\Rohit\\OneDrive\\Desktop\\billing system\\billing_system1.txt");
            rename("C:\\Users\\Rohit\\OneDrive\\Desktop\\billing system\\bill_temp.txt","C:\\Users\\Rohit\\OneDrive\\Desktop\\billing system\\billing_system1.txt");
            
        }
        else if(choice==2){
            close=true;
            cout<<"\t\t COUNTING TOTAL BILL"<<endl;

        }
        Sleep(1000);
    }
    system("cls");
    cout<<endl<<endl<<endl;
    cout<<"\t\t TOTAL BILL------------------------------:"<<count<<endl<<endl;
    cout<<"\t\t THANKS FOR SHOPPING!"<<endl;
    Sleep(10000);

}
void displayItems() {
    system("cls");
    ifstream in("C:\\Users\\Rohit\\OneDrive\\Desktop\\billing system\\billing_system1.txt");
    string line;
    cout << "\t\t REMAINING ITEMS" << endl;
    cout << "\t\t ITEM | RATE | QUANTITY" << endl;
    while (getline(in, line)) {
        stringstream ss(line);
        string itemname;
        int itemrate, itemquant;
        char delimiter;
        ss >> itemname >> delimiter >> itemrate >> delimiter >> itemquant;
        cout << "\t\t" << itemname << "\t" << itemrate << "\t" << itemquant << endl;
    }
    in.close();
    Sleep(5000);
}
void clearData() {
    ofstream out("C:\\Users\\Rohit\\OneDrive\\Desktop\\billing system\\billing_system1.txt", ios::trunc);
    out.close();
    cout << "\t\t ALL DATA CLEARED SUCCESSFULLY!" << endl;
    Sleep(2000);
}

};
int main(){
    bill b;
    bool exit=false;
    while(!exit){
        system("cls");
        int val;
        cout<<"\t Welcome To Super Market Billing System"<<endl;
        cout<<"\t --------------------------------------"<<endl;
        cout<<"\t "<<endl;
        cout<<"\t\t 1. ADD ITEM."<<endl;
        cout<<"\t\t 2. NEW BILL. "<<endl;
        cout<<"\t\t 3. DISPLAY REMAINING ITEMS. "<<endl;
        cout<<"\t\t 4. CLEAR DATA. "<<endl;
        cout<<"\t\t 5. EXIT."<<endl;
        cout<<"\t\t ENTER THE CHOICE : ";
        cin>>val;
        if(val==1){
            system("cls");
            b.addItem();
            Sleep(2000);
        }
        else if(val==2){
            b.printbill();
        }
        else if(val==3){
            b.displayItems();
         }else if(val==4){
            b.clearData();
        }
        else if(val==5){
            system("cls");

            exit=true;
            cout<<"\t\t -------GOOD LUCK!-------"<<endl;
            Sleep(2000);
        }
    }
}