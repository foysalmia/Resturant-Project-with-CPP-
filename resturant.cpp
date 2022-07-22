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
    Restaurant(int n,int code[],string name[],int price[])
    {
        this->total_tax = 0;
        for(int i=0; i<n; i++)
        {
            this->food_item_codes[i] = code[i] ;
            this->food_item_names[i] = name[i];
            this->food_item_prices[i] = price[i];
        }
    }

};

class Order
{
public:
    int table_no;
    int items;
    int item_code[12];
    int item_quantity[12];
    int tax;

    Order(int table_no,int items,int item_code[],int item_quantity[])
    {
        this->tax = 0;
        this->table_no = table_no;
        this->items = items;

        for(int i=0; i<items; i++)
        {
            this->item_code[i] = item_code[i];
            this->item_quantity[i] = item_quantity[i];
        }
    }
};

class Summary
{
public:
    int table_no;
    int code[12];
    string name[12];
    int price[12];
    int quantity[12];
    int total_price[12];

    Summary(Order *order,Restaurant *resturant,int item,int n)
    {
        this->table_no = order->table_no;
        for(int i=0; i<item; i++)
        {
            this->code[i] = order->item_code[i];
            this->quantity[i] = order->item_quantity[i];
            for(int j=0; j<n; j++)
            {
                if(order->item_code[i] == resturant->food_item_codes[j])
                {
                    this->name[i] = resturant->food_item_names[j];
                    this->price[i] = resturant->food_item_prices[j];
                }
            }

        }

        for(int i=0;i<item;i++){
            this->total_price[i] = this->price[i] * this->quantity[i];
        }
    }


};

Restaurant *create_resturant(int n)
{
    int food_code[n],food_price[n];
    string food_name[n];

    for(int i=0; i<n; i++)
    {
        cin>>food_code[i];
        cin.ignore();
        getline(cin,food_name[i]);
        cin>>food_price[i];
    };

    Restaurant *myResturant = new Restaurant(n,food_code,food_name,food_price);
    return myResturant;

};



void print_order(Summary *bill,int n)
{

    cout<<"\t\t\t\tBILL SUMMARY"<<endl;
    cout<<"\t\t\t-------------------------"<<endl;
    cout<<"Table No : "<<bill->table_no<<endl;
    cout<<"Item Code\t\tItem Name\t\tItem Price\t\tItem Quantity\t\tTotal Price"<<endl;
    for(int i=0;i<n;i++){
        cout<<bill->code[i]<<"\t\t\t"<<bill->name[i]<<"\t"<<bill->price[i]<<"\t\t\t"<<bill->quantity[i]<<"\t\t\t"<<bill->total_price[i]<<endl;
    }

}

void create_Order(int n,Restaurant *resturant)
{
    int tableNumber,items;
    cout<<"Enter Table No : ";
    cin>>tableNumber;
    cout<<"Enter Number of Items : ";
    cin>>items;
    int item_code[items],quantity[items];

    for(int i=0; i<items; i++)
    {
        cout<<"Enter Item "<<i+1<<" Code : ";
        cin>>item_code[i];
        cout<<"Enter Item "<<i+1<<" Quantity : ";
        cin>>quantity[i];
    }

    Order *newOrder = new Order(tableNumber,items,item_code,quantity);
    Summary *summary = new Summary(newOrder,resturant,items,n);
    print_order(summary,items);


}

void printDetails(int n,Restaurant *resturant)
{
    cout<<"\t\t\t\tMAKE BILL"<<endl;
    cout<<"\t\t\t-------------------------"<<endl;
    cout<<"Item Code\t\tItem Name\t\t\t\tItem Price"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<resturant->food_item_codes[i]<<"\t\t\t"<<resturant->food_item_names[i]<<"\t\t\t"<<resturant->food_item_prices[i]<<endl;
    }
}

int main()
{
    int n;
    cin>>n;

    Restaurant *myResturant = create_resturant(n);
    printDetails(n,myResturant);
    cout<<endl;
    create_Order(n,myResturant);
    return 0;
}
