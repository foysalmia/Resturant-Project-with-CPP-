#include<bits/stdc++.h>

using namespace std;

class Restaurant
{
protected:
    int total_tax;
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    Restaurant(int n,int code[],string name[],int price[]){
        this->total_tax = 0;
        for(int i=0;i<n;i++){
            this->food_item_codes[i] = code[i] ;
            this->food_item_names[i] = name[i];
            this->food_item_prices[i] = price[i];
        }
    }
};

Restaurant *create_resturant(int n){
    int food_code[n],food_price[n];
    string food_name[n];

    for(int i=0;i<n;i++){
        cin>>food_code[i];
        cin.ignore();
        getline(cin,food_name[i]);
        cin>>food_price[i];
    };

    Restaurant *myResturant = new Restaurant(n,food_code,food_name,food_price);
    return myResturant;

};

void printDetails(int n,Restaurant *resturant){
    cout<<"\t\t\t\tMAKE BILL"<<endl;
    cout<<"\t\t\t-------------------------"<<endl;
    cout<<"Item Code\t\tItem Name\t\t\t\tItem Price"<<endl;
    for(int i=0;i<n;i++){
        cout<<resturant->food_item_codes[i]<<"\t\t\t"<<resturant->food_item_names[i]<<"\t\t\t"<<resturant->food_item_prices[i]<<endl;
    }
}

int main()
{
    int n;
    cin>>n;

    Restaurant *myResturant = create_resturant(n);
    printDetails(n,myResturant);
    return 0;
}
