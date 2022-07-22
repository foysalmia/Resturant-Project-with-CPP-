
# Restaurant-Management-System

A Restaurant management simple programme with c++ for practising OOP.



## Inputs

- Input how many foods are available { max = 12}
- Input Every food's data
- Products data => food code,Price,Quantity
- Input table no :
- How many itmes
- Every item's code
- Every item's Quantity



## Screenshots
Input Sample:

![App Screenshot](https://i.ibb.co/Zf15927/input.png)

Menu Print Sample:

![App Screenshot](https://i.ibb.co/1rgZQCZ/dataprint.png)

Take Order Sample:

![App Screenshot](https://i.ibb.co/ft4wLy6/order.png)

Bill Summary Sample :

![App Screenshot](https://i.ibb.co/9v6jp2G/bil.png)
## 🚀 About Me
I'm Foysal who is a curious programmer.
I love to learn new things and beat new challenges.


## Main function code sample

```javascript
#include <iostream>

using namespace std;

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
```


