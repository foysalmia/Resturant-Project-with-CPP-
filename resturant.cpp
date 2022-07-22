#include<bits/stdc++.h>

using namespace std;

class Restaurant
{
protected:
    float total_tax;
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    int get_tax(){
        return total_tax;
    }
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

    friend class Summary;

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
    float order_tax;
    int order_sum;
    float total_charge;
    int code[12];
    string name[12];
    int price[12];
    int quantity[12];
    int total_price[12];

    Summary(Order *order,Restaurant *resturant,int item,int n)
    {
        this->table_no = order->table_no;
        this->order_sum = 0;
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

        for(int i=0; i<item; i++)
        {
            this->total_price[i] = this->price[i] * this->quantity[i];
            this->order_sum += total_price[i];
        }

        this->order_tax = (float)this->order_sum * 0.05;
        this->total_charge = (float)this->order_sum + this->order_tax;
        resturant->total_tax += this->order_tax;
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
    for(int i=0; i<n; i++)
    {
        cout<<bill->code[i]<<"\t\t\t"<<bill->name[i]<<"\t"<<bill->price[i]<<"\t\t\t"<<bill->quantity[i]<<"\t\t\t"<<bill->total_price[i]<<endl;
    }
    cout<<"TAX\t\t\t\t\t\t\t\t\t\t\t\t"<<bill->order_tax<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"NET TOTAL\t\t\t\t\t\t\t\t\t\t\t"<<bill->total_charge<<" Taka"<<endl;

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
        int code;
        bool isAvailable = false;
Flag:
        cout<<"Enter Item "<<i+1<<" Code : ";
        cin>>code;
        for(int j=0; j<n; j++)
        {
            if(code == resturant->food_item_codes[j])
            {
                isAvailable = true;
                break;
            }
        }
        if(isAvailable)
        {
            item_code[i] = code;
        }
        else
        {
            cout<<"Sorry,This food is not available right now..."<<endl;
            goto Flag;
        }

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
    while(true)
    {
        printDetails(n,myResturant);
        cout<<endl;
        create_Order(n,myResturant);
        cout<<"Sub Total tax : "<<myResturant->get_tax()<<endl;
    }
    return 0;
}
