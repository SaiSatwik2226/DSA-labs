/* 1.
a) Consider the following scenario:
Suppose an online video on demand service allows two types of
customers: regular and premium. Both types of customers have the
following attributes common:
• Username
• Phone Number
• Watched shows
Regular customers can only watch upto 32 hrs of content in a single
language: English, while the premium customers can watch unlimited
content in either English or their preferred language (hence an extra
attribute).
Design the classes for the given scenario, with given member
functions:
• watch(Show show): Checks whether the customer can watch the
show. If yes, add it to the watched list and deduct from watched
hours.
• displayCustomer(): Display customer’s details
• displayShowIds(): Display watched shows
b) Assume that the customers can pool in and share an account, i.e., a
single account can have multiple customers, but of same type (all
regular or all premium). Further, an account can be shared by 5
regular customers and 10 premium customers. Create a template
Account, that can hold customers of the required type. Create the
functions to:
• add a customer to the account
• display the customer details
Note: Throw error or print error message wherever necessary. */

#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;

enum Languages{
    ENGLISH, FRENCH, GERMAN
};

struct Show{
    int id, duration, language;
    Show(){}
    Show(int sid, int sduration, int slanguage){
        id=sid;
        duration=sduration;
        language=slanguage;
    }
};

class Customer{
    public:
        string userName, phoneNumber;
        int watchHours;
        Show watchedShows[1000];
        int index;
        Customer(){}
        Customer(string uName, string pNumber){
            userName = uName;
            phoneNumber = pNumber;
            watchHours=32;
            index=0;
        }
    virtual void watch(Show show){
        if(watchHours-show.duration >= 0 && show.language==ENGLISH){
            watchHours = watchHours - show.duration;
            watchedShows[index++] = show;
            cout<<userName<<" watched show id: "<<show.id<<endl;
        }
        else if(show.language!=ENGLISH){
        cout<<userName<<"Only English language is allowed for current subscription\n\n";
        }
        else{
        cout<<userName<<"Exceeds watch limit\n\n";
        }
    }
    virtual void displayCustomer(){
        cout<<"UserName: "<<userName<<"\nPhone: "<<phoneNumber<<endl;
        cout<<"Available Language: English"<<"\n\n";
    }
    void displayWatchedShowIds(){
        for(int i=0;i<index;i++){
            cout<<watchedShows[i].id<<" ";
        }
        cout<<endl;
    }
};

class PremiumCustomer: public Customer{
    public:
        int preferredLanguage;
        PremiumCustomer(): Customer(){}
        PremiumCustomer(string uName, string pName, int language):Customer(uName, pName){
            preferredLanguage= language;
            watchHours = -1;
        }
    void watch(Show show){
    /*update watchedShows and display appropriate messages, consult watch
    function of Customer to get a better idea*/
        watchedShows[index++] = show;
        cout<<userName<<" watched show id: "<<show.id<<endl;
    }
    void displayCustomer(){
        string lang;
        switch(preferredLanguage){
            case FRENCH:
            lang = "French";
            break;
            case GERMAN:
            lang = "German";
            break;
            default:
            lang = "English";
        }
        cout<<"UserName: "<<userName<<"\nPhone: "<<phoneNumber<<endl;
        cout<<"Preferred Language: "<<lang<<"\n\n";
    }
};

template<class T, int max>
class Account{
    public:
        T customers[max];
        int maxCustomers;
        int index;
    Account(){
        maxCustomers=max;
        index=0;
    }
    void addCustomer(T cust){
    /*add the customer to the array customers*/
        index++;
        customers[index] = cust;
    }
    void displayCustomers(){
    /*diplay each customer’s details*/
        for (int i = 1; i <= index ; i++)
        {
            customers[i].displayCustomer();
        }
        
    }
};

int main(){
    Account<Customer, 5> acc1;
    acc1.addCustomer(Customer("User1", "985555"));
    acc1.addCustomer(Customer("User2", "986666"));
    acc1.displayCustomers();

    Account<PremiumCustomer, 10> acc2;
    acc2.addCustomer(PremiumCustomer("PUser1", "987777", GERMAN));
    acc2.addCustomer(PremiumCustomer("PUser2", "988888", FRENCH));
    acc2.displayCustomers();
    
    Show shows[] = {Show(1, 7, ENGLISH), Show(2, 7, FRENCH), Show(3, 10, GERMAN), Show(4, 17, ENGLISH)};
    acc1.customers[0].watch(shows[3]);
    acc1.customers[0].watch(shows[2]);

    for(int i=0; i<3; i++){
        acc2.customers[0].watch(shows[i]);
    }

    cout<<"Watched shows for "<<acc1.customers[0].userName<<":\n";
    acc1.customers[0].displayWatchedShowIds();

    cout<<"Watched shows for "<<acc2.customers[0].userName<<":\n";
    acc2.customers[0].displayWatchedShowIds();
}