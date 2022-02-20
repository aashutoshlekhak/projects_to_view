#include<iostream>
#include<string.h>
#include<fstream>
#include<windows.h>
#include<conio.h>
using namespace std;
fstream file;
class bus{
char busno[5],price[5],arrival[5],departure[5],start[10],destination[10],seat[8][4][10];
public:
       void registration();
       void show_bus();
       void show_bus2();
       void reserve();
};
void bus::registration()
{
  cout<<"Enter Bus Number: "<<endl;
  cin>>busno;
  cout<<"Enter Price: "<<endl;
  cin>>price;
  cout<<"Enter Starting Place: "<<endl;
  cin>>start;
  cout<<"Enter Destination: "<<endl;;
  cin>>destination;
  cout<<"Enter Departure Time from "<<start<<endl;
  cin>>departure;
  cout<<"Enter Arrival Time to "<<destination<<endl;
  cin>>arrival;
  for(int i=0; i<8; i++)
        {
            for(int j=0; j<4; j++)
            {
                strcpy(seat[i][j],"Empty");
            }
        }
}
void bus::show_bus()
{
    cout<<endl<<"____________________________________________________________________________"<<endl<<endl;
    cout<<"Bus Number : "<<busno<<endl;
    cout<<"Price : Rs"<<price<<endl;;
    cout<<"Starting from : "<<start<<endl;
    cout<<"Destination : "<<destination<<endl;
    cout<<"Departure Time from "<<start<<" : "<<departure<<endl;
    cout<<"Arrival Time to "<<destination<<" : "<<arrival<<endl;
    cout<<"\t\t\t   Seat Arrangement"<<endl;
    int k=0;
    for(int i=0; i<8; i++)
        {
            for(int j=0; j<4; j++)
            {
                k++;
                cout<<"\t"<<k<<seat[i][j]<<"\t";
            }
            cout<<endl;
        }
    cout<<"____________________________________________________________________________"<<endl;
}
void bus::show_bus2()
{
    cout<<endl<<"____________________________________________________________________________"<<endl<<endl;
    cout<<"Bus Number : "<<busno<<endl;
    cout<<"Price : Rs"<<price<<endl;;
    cout<<"Starting from : "<<start<<endl;
    cout<<"Destination : "<<destination<<endl;
    cout<<"Departure Time from "<<start<<" : "<<departure<<endl;
    cout<<"Arrival Time to "<<destination<<" : "<<arrival<<endl;
    cout<<"\t\t\t   Seat Arrangement"<<endl;
    int k=0;
    for(int i=0; i<8; i++)
        {
            for(int j=0; j<4; j++)
            {
                k++;
                if(strcmp(seat[i][j],"Empty")==0)
                {
                cout<<"\t"<<k<<seat[i][j]<<"\t";
                }
                else {cout<<"\t"<<k<<"*****"<<"\t";}
            }
            cout<<endl;
        }
    cout<<"____________________________________________________________________________"<<endl;
}
void bus::reserve(){
                char num[5];
                bus b2;
                int seatn,y=1;
                cout<<"Enter Bus Number"<<endl;
                while (y=1){
                        cin>>num;
                file.open("bus.txt", ios::in|ios::out);
                file.seekg(0,ios::end);
                int p1 = file.tellg()/sizeof(b2);
                file.seekg(0,ios::beg);
                for (int i=0; i<p1; i++)
                {
                  file.read((char*)&b2, sizeof(b2));
                 if(strcmp(b2.busno, num)==0)
                    {
                        y++;
                        goto B;
                  }
                }
                    cout<<"Enter Valid Bus Number"<<endl;
                    file.close();
                 }
                B:
                cout<<"Enter Seat Number :"<<endl;
                cin>>seatn;
                if(seatn>32||seatn<1){cout<<"Invalid Seat Number"<<endl;
                goto B;}
                if (strcmp(b2.seat[seatn/4][(seatn%4)-1], "Empty")==0)
                {
                    cout<<"Enter Passenger's name : ";
                    cin>>b2.seat[seatn/4][(seatn%4)-1];
                    file.seekp((file.tellp()-sizeof(b2)),ios::beg);
                    file.write((char *)&b2, sizeof(b2));
                    file.close();
                    cout<<"Check bill from the file bill.txt"<<endl;
                    file.open("bill.txt",ios::out);
                        file<<"_____________________________________"<<endl<<endl;
                        file<<"Passenger's Name : "<<b2.seat[seatn/4][(seatn%4)-1]<<endl;
                        file<<"Seat Number : "<<seatn<<endl;
                        file<<"Bus Number : "<<b2.busno<<endl;
                        file<<"Price : Rs "<<b2.price<<endl;;
                        file<<"From "<<b2.start;
                        file<<" To "<<b2.destination<<endl;
                        file<<"Departure Time from "<<b2.start<<" : "<<b2.departure<<endl;
                        file<<"Arrival Time to "<<b2.destination<<" : "<<b2.arrival<<endl;
                        file<<"_____________________________________"<<endl;
                    file.close();
                }
                else
                {
                    cout<<"The Seat Number is Reserved.Choose Another Seat.\n";
                    goto B;
                   }
                    }
int main() {

int a,b,c,o=0;
bus b1;
A:
  cout<<"\n\t\t\tBUS RESERVATION SYSTEM\n\t\t\t1.Register a Bus\n\t\t\t"
  <<"2.Reserve a Bus\n\t\t\t"
  <<"3.Exit\n\t\t\tEnter your choice: ";
  cin>>a;
  switch(a)
  {
    case 1:
{    p:
    system("cls");
    if(o==0)
    {
string username,password;
    char ch;
    cout<<"\t\t\t****Security Login****";
    cout<<"\n\t\t\tEnter Username : ";
    cin>>username;
    cout<<"\n\t\t\tEnter Password : ";
    for(int i=1;i<=5;i++)
    {
        ch=getch();
        password+=ch;
        cout<<"*";
    }
    if((username=="Aashutosh"||username=="Abinash"||username=="Avinash"||username=="Mecon") && password=="12345" )
    {
        cout<<"\n\t\t\tLoading";
        for(int i=1;i<=5;i++)
        {
            Sleep(400);
            cout<<".";
        }
        cout<<"\n\t\t\tLogin Successful";
        o++;
        }
        else
        {cout<<"\n\t\t\tYour Username or Password is incorrect. Try Again"<<endl;
        goto p;}
        system("cls");
    }

        cout<<"\n\t\t\tBUS REGISTRATION\n\t\t\t1.Add New Bus\n\t\t\t"
        <<"2.Update Existing Bus\n\t\t\t3.Delete Existing Bus\n\t\t\t"
        <<"4.Show Current Reservations\n\t\t\t5.Return to Previous Menu"
        <<"\n\t\t\tEnter your choice: ";
        cin>>b;
        switch(b)
        {
        case 1:
            {
                file.open("bus.txt", ios::app  );
                b1.registration();
                file.write((char *)&b1, sizeof(b1));
                file.close();
                cout<<"New Bus Registered";
                goto A;
            }
        case 2:
            {
            int k,location;
            file.open("bus.txt", ios :: out|ios::in );
            cout<<"Enter Record Number of the Bus to be Updated"<<endl;
            cin>>k;
            cout<<"Enter New Details : "<<endl;
            location = (k-1)*sizeof(b1);
            file.seekg(location,ios::beg);
            b1.registration();
            file.write((char*)&b1,sizeof(b1));
            cout<<"\nRecord Number "<<k<< " updated";
            file.close();
            goto A;
            }
        case 3:
            {
            int n;
            fstream temp;
            cout<<"Enter Record Number of the Bus to be Deleted"<<endl;
            cin>>n;
            file.open("bus.txt", ios::in);
            file.seekg(0,ios::end);
            int e = file.tellg()/sizeof(b1) ;

            temp.open("temp.txt", ios::out);
            file.seekg(0);
            file.seekg(0,ios::beg);
            for (int i=0; i<e ; i++)
            {
                file.read((char*)&b1,sizeof(b1));
                if (i!=(n-1))
                {
                temp.write((char*)&b1,sizeof(b1));
                }
            }
            file.close();
            file.open("bus.txt",ios::out);
            temp.close();
            temp.open("temp.txt",ios::in);

            for (int i=0; i<e-1; i++)
            {
                temp.read((char*)&b1,sizeof(b1));
                file.write((char*)&b1,sizeof(b1));
            }
            temp.close();
            file.close();
            remove("temp.txt");
            cout<<"Bus deleted";
             goto A;
            }
        case 4:
            {
            file.open("bus.txt", ios :: in);
            file.seekg(0,ios::end);
            int l1 = file.tellg()/sizeof(b1);
            if(l1==0){cout<<"\t\t\tNo Buses Available";}
            file.seekg(0,ios::beg);
            for (int i=0; i<l1; i++)
               {
                  file.read((char*)&b1, sizeof(b1));
                  cout<<"Record Number : "<<i+1;
                  b1.show_bus();
                }
               file.close();
               goto A;
            }
        case 5:
            {
               goto A;
            }
        }
        }
    case 2:
       {
        cout<<"\n\t\t\tBUS RESERVATION\n\t\t\t1.Show Available Buses and Seats\n\t\t\t"
        <<"2.Reserve a Seat\n\t\t\t3.Return to Previous Menu\n\t\t\t"
        <<"Enter your choice: ";
        cin>>b;
        switch(b)
        {
        case 1:
            {
            file.open("bus.txt", ios :: in);
            file.seekg(0,ios::end);
            int l1 = file.tellg()/sizeof(b1);
            if(l1==0){cout<<"\t\t\tNo Buses Available";}
            file.seekg(0,ios::beg);
            for (int i=0; i<l1; i++)
               {
                  file.read((char*)&b1, sizeof(b1));
                  cout<<"Record Number : "<<i+1;
                  b1.show_bus2();
                }
               file.close();
             goto A;
            }
        case 2:
            {
                b1.reserve();

             goto A;
            }
        case 3:
            {

             goto A;
            }
        }
    case 3:
       exit(0);
  }
}
}


