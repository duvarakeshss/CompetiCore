#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
#include<string>
#include<cstdio>
#include<windows.h>
#include<cstdio>
#include<conio.h>
#include<time.h>
#include<fstream>
#include<unistd.h>

using namespace std;

int i=1;
string get_password() {
    string password;
    char c;
    while((c = getch()) != '\r') {
        if(c == '\b') {
            if(!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        } else {
            cout << '*';
            password.push_back(c);
        }
    }
    cout << endl;
    return password;
}

void login()
{
    char a=219;
    system("COLOR 02");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t  ";
    cout<<"             LOADING...\n";
    cout<<"\n\t\t\t\t\t  ";

    for (int i = 1; i <= 36; i++)
        {
            cout<<a;
            Sleep(50);
        }
    int sel=1,opt,flag;
    string l,s,us,ps,user,password;
    while (sel==1)
    {
        system("cls");
        system("color 04");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t       Enter 1 to sign up ";
        cout<<endl<<"\t\t\t\t\t       Enter 2 to login in ";
        cout<<endl<<"\t\t\t\t\t       Enter the choice (1/2):";
        cin>>opt;
        if(opt==1)
        {
                        fstream file_a;
                        file_a.open("file2.txt",ios_base::app);
                        string user,pass;
                        system("cls");
                        cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t             Enter the username :";
                        cin>>user;
                        cout<<"\t\t\t\t\t             Enter the password :";
                        pass=get_password();
                        file_a<<user<<" "<<pass<<endl;
                        file_a.close();

        }
        else if(opt==2)
        {
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t             Enter the username :";
                        cin>>us;
                        cout<<"\t\t\t\t\t             Enter the password :";
                        ps=get_password();
                        ifstream d;
                        d.open("file2.txt");
                        bool found=false;
                        while (d>>l>>s)
                        {
                            if(l==us && s==ps)
                            {
                                found=true;
                                break;

                            }
                        }
                        d.close();
                        if(found)
                        {
                            cout<<"\n\t\t\t\t\t\t     logged in successfully "<<endl;
                            break;
                        }
                        else
                        {
                            cout<<"\n\t\t\t\t\t\t     Invaild user"<<endl;
                        }
        }
        else
        {
            cout<<"\t\t\t\t\t\t\t\tinvaild input";
        }
        //cout<<"\n\n\t\t\t\t\t\t  Enter 1 to continue 0 to exit:";
        //cin>>sel;

    }
}

const char* small_size[5] = {"25-05-23", "26-05-23", "27-05-23", "28-05-23", "29-05-23"};
const char* medium_size[5] = {"01-06-23", "02-06-23", "03-06-23", "04-06-23", "05-06-23"};
const char* large_size[5] = {"08-06-23", "09-06-23", "10-06-23", "11-06-23", "12-06-23"};

class basketball
{
public:
    char team_name[20], opponent_name[20], s, date_to_book[9],vacancy[50];
    int seats=0,tot=0;

public:
    void getdata()
    {
        ofstream file;
        file.open("basket.dat", ios::binary | ios::in | ios::app);
        cout<<"\n\t\t\t\t\tSMALL SIZE\n";
        for(int i = 0; i < 5; i++)
        {
            basketball b1;
            strcpy(b1.date_to_book,small_size[i]);
            strcpy(b1.vacancy,"NOT-BOOKED");
            strcpy(b1.team_name,"NULL");
            strcpy(b1.opponent_name,"NULL");
            cin>>ws;
            b1.tot=0;
            b1.seats=0;
            file.write(reinterpret_cast<const char *>(&b1), sizeof(b1));
            cout << "\t\t" << b1.date_to_book << "\t" << b1.vacancy <<"\t"<< b1.team_name << " vs " << b1.opponent_name << "\t\t" << "\t" << b1.seats <<"\t" << b1.tot << endl;
        }
        cout << "\n\t\t\t\t\tMEDIUM SIZE\n\n";
        for (int i = 0; i < 5; i++)
        {
            basketball b2;
            strcpy(b2.date_to_book,medium_size[i]);
            strcpy(b2.vacancy,"NOT-BOOKED");
            strcpy(b2.team_name,"NULL");
            strcpy(b2.opponent_name,"NULL");
            b2.tot=0;
            b2.seats=0;
            file.write(reinterpret_cast<const char *>(&b2), sizeof(b2));
            cout << "\t\t" <<b2.date_to_book << "\t" << b2.vacancy <<"\t" << b2.team_name << " vs " << b2.opponent_name << "\t\t" << "\t" << b2.seats << "\t" << b2.tot << endl;
        }
        cout << "\n\t\t\t\t\tLARGE SIZE\n\n";
        for (int i = 0; i < 5; i++)
        {
            basketball b3;
            strcpy(b3.date_to_book,large_size[i]);
            strcpy(b3.vacancy,"NOT-BOOKED");
            strcpy(b3.team_name,"NULL");
            strcpy(b3.opponent_name,"NULL");
            b3.tot=0;
            b3.seats=0;
            file.write(reinterpret_cast<const char *>(&b3), sizeof(b3));
            cout << "\t\t" <<b3.date_to_book << "\t" << b3.vacancy << "\t"<<b3.team_name << " vs " << b3.opponent_name << "\t\t" << "\t" << b3.seats << "\t" << b3.tot << endl;
        }
        file.close();
    }

    int check()
    {
        if (strcmp(vacancy,"NOT-BOOKED")==0)
        {
            return 1;
        }
        return 0;
    }

    void update(char date[],char tn[],char on[])
    {
        fstream file;
        file.open("basket.dat", ios::binary | ios::in | ios::out);
        while (file.read(reinterpret_cast<char*>(this), sizeof(*this)))
        {
            if (strcmp(date_to_book, date) == 0)
            {
                if (check() == 1)
                {
                    strcpy(team_name,tn);
                    strcpy(vacancy, "BOOKED");
                    strcpy(opponent_name,on);
                    file.seekp(file.tellp() - sizeof(*this));
                    file.write(reinterpret_cast<const char*>(this), sizeof(*this));
                    break;
                }
                else
                {
                    cout << "\nSorry, this date is already booked!\n";
                    break;
                }
            }
        }
        file.close();
    }

    void display()
    {
        cout << i << setw(20) << date_to_book << setw(20) << vacancy << "\t" <<team_name << "  vs  " <<opponent_name << "\t\t" << tot <<endl;
    }
    void show(int n)
    {
        fstream file("basket.dat",ios::binary | ios::in);
        basketball b;
        int count = 0;
        while(file.read((char*)&b,sizeof(b)))
        {
            if(n==1)
            {
                if(count==0)
                {
                    i=1;
                    cout<<"\n\n\t\t\t\tSMALL SIZE\n\n";
                    cout<<setw(20)<<"DATE"<<setw(20)<<"VACANCY"<< "\t   " << "MATCH\t\t" << "TOTAL" << endl;
                }
                if(count>=0)
                {
                    b.display();
                }
                if(count==4)
                {
                    break;
                }
            }
            else if(n==3)
            {
                if(count==5)
                {
                    i=1;
                    cout<<"\n\n\t\t\t\tMEDIUM SIZE\n\n";
                    cout<<setw(20)<<"DATE"<<setw(20)<<"VACANCY"<< "\t   " << "MATCH\t\t" << "TOTAL" << endl;
                }
                if(count>=5)
                {
                    b.display();
                }
                if(count<5)
                {
                    int p=sizeof(b);
                    file.seekg(+p,ios::cur);
                }
                if(count==9)
                {
                    break;
                }
            }
            else if(n==2)
            {
                if(count==10)
                {
                    i=1;
                    cout<<"\n\n\t\t\t\tLARGE SIZE\n\n";
                    cout<<setw(20)<<"DATE"<<setw(20)<<"VACANCY"<< "\t   " << "MATCH\t\t" << "TOTAL" << endl;
                }
                if(count>=10)
                {
                    b.display();
                }
                if(count<10)
                {
                    int p=sizeof(b);
                    file.seekg(+p,ios::cur);
                }
                if(count==14)
                {
                    break;
                }
            }
            else if(n==4)
            {
                if(count==0)
                {
                    i=1;
                    cout<<"\n\n\t\t\t\tSMALL SIZE\n\n";
                    cout<<setw(20)<<"DATE"<<setw(20)<<"VACANCY"<< "\t   " << "MATCH\t\t" << "TOTAL" << endl;
                }
                if(count==5)
                {
                    cout<<"\n\n\t\t\t\tMEDIUM SIZE\n\n";
                    cout<<setw(20)<<"DATE"<<setw(20)<<"VACANCY"<< "\t   " << "MATCH\t\t" << "TOTAL" << endl;
                }
                if(count==10)
                {
                    cout<<"\n\n\t\t\t\tLARGE SIZE\n\n";
                    cout<<setw(20)<<"DATE"<<setw(20)<<"VACANCY"<< "\t   " << "MATCH\t\t" << "TOTAL" << endl;
                }
                if(count==15)
                {
                    break;
                }
                b.display();
            }
            count++;
        }
        file.close();
    }
    void book_date();
    void modify(char date[])
    {
        fstream file;
        file.open("basket.dat", ios::binary | ios::in | ios::out);
        while (file.read(reinterpret_cast<char*>(this), sizeof(*this)))
        {
            if (strcmp(date_to_book, date) == 0)
            {
                if (check() == 0)
                {
                    strcpy(team_name,"NULL");
                    strcpy(vacancy, "NOT-BOOKED");
                    strcpy(opponent_name,"NULL");
                    file.seekp(file.tellp() - sizeof(*this));
                    file.write(reinterpret_cast<const char*>(this), sizeof(*this));
                    break;
                }
            }
        }
        file.close();
    }
    void update_aud(char date[],int n,int p)
    {
        fstream file;
        file.open("basket.dat", ios::binary | ios::in | ios::out);
        while (file.read(reinterpret_cast<char*>(this), sizeof(*this)))
        {
            if (strcmp(date_to_book, date) == 0)
            {
                if (check() == 0)
                {
                    if(seats>100)
                    {
                        cout<<"\n\t\t\t\tNo seats available\n";
                        break;
                    }
                    else
                    {
                        cout<<"\n\t\t\t\t\tBOOKED\n";
                        sleep(2);
                        cout<<"\n\t\t\t\t\tPAYMENT   :  Rs."<<n*p;
                        tot=tot+n*p;
                        seats=seats+p;
                    }
                    file.seekp(file.tellp() - sizeof(*this));
                    file.write(reinterpret_cast<const char*>(this), sizeof(*this));
                    break;
                }
                else
                {
                    cout<<"\nNO MATCH AVAILABLE ON THAT DAY\n";
                }
            }
        }
        file.close();
    }

};


void basketball::book_date()
{
    char date[9];
    bool date_found=false;
    basketball b;
    system("cls");
    b.getdata();
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tCHOOSE THE SIZE OF THE TOURNAMENT\n"<<endl;
    cout<<"\n\t\t\t\t\t\t1. SMALL SIZE\n"<<endl;
    cout<<"\n\t\t\t\t\t\t2. MEDIUM SIZE\n"<<endl;
    cout<<"\n\t\t\t\t\t\t3. LARGE SIZE\n"<<endl;
    cout<<"\n\t\t\t\t\t\tENTER THE CHOICE : ";
    int choice;
    cin.ignore();
    cin>>choice;
    system("cls");

    show(choice);

    cout<<"\n\n\n\n\n\t\t\t\tEnter the date to be booked : ";
    cin>>date;
    fstream infile("basket.dat",ios::binary | ios::in);
    infile.seekg(0,ios::beg);

    switch(choice)
    {
        case 1:
            cout<<"\n\t\t\t\tEnter the team name : ";
            cin>>ws;
            cin.getline(b.team_name,20);
            cout<<"\n\t\t\t\tEnter the team name : ";
            cin>>ws;
            cin.getline(b.opponent_name,20);
            update(date,b.team_name,b.opponent_name);
            break;
        case 2:
            cout<<"\n\t\t\t\tEnter the team name : ";
            cin>>ws;
            cin.getline(b.team_name,20);
            cout<<"\n\t\t\t\tEnter the opponent team name : ";
            cin>>ws;
            cin.getline(b.opponent_name,20);
            update(date,b.team_name,b.opponent_name);
            break;
        case 3:
            cout<<"\n\t\t\t\tEnter team name : ";
            cin>>ws;
            cin.getline(b.team_name,20);
            cout<<"\n\t\t\t\tEnter the opponent team name : ";
            cin>>ws;
            cin.getline(b.opponent_name,20);
            update(date,b.team_name,b.opponent_name);
            break;
        default:
            cout<<"\nInvalid choice\n";
    }
    infile.close();
    fstream file;
    file.open("basket.dat",ios::in);
    file.seekp(0,ios::beg);
    for(int i=0;i<5;i++)
    {
    while(file.read((char*)&b,sizeof(b)))
    {
        if(strcmp(date_to_book,b.date_to_book)==0)
        {
            file.seekp(-sizeof(b),ios::cur);
            file.write((char*)&(*this),sizeof(*this));
            break;
        }
    }
    file.close();
    }
}

class football
{
public:
    char team_name[20], opponent_name[20], s, date_to_book[9],vacancy[50];
    int tot=0,seats=0;

public:
    void getdata()
    {
        ofstream file;
        file.open("football.dat", ios::binary | ios::in | ios::app);
        cout<<"SMALL SIZE\n";
        for(int i = 0; i < 5; i++)
        {
            football f1;
            strcpy(f1.date_to_book,small_size[i]);
            strcpy(f1.vacancy,"NOT-BOOKED");
            strcpy(f1.team_name,"NULL");
            strcpy(f1.opponent_name,"NULL");
            cin>>ws;
            f1.tot=0;
            f1.seats=0;
            file.write(reinterpret_cast<const char *>(&f1), sizeof(f1));
            cout <<"\t" << f1.date_to_book << "\t" << f1.vacancy << "\t" << f1.team_name << " vs " << f1.opponent_name << "\t\t" << "\t" << f1.seats << "\t" << f1.tot << endl;
        }
        cout << "\nMEDIUM SIZE\n";
        for (int i = 0; i < 5; i++)
        {
            football f2;
            strcpy(f2.date_to_book,medium_size[i]);
            strcpy(f2.vacancy,"NOT-BOOKED");
            strcpy(f2.team_name,"NULL");
            strcpy(f2.opponent_name,"NULL");
            cin>>ws;
            f2.tot=0;
            f2.seats=0;
            file.write(reinterpret_cast<const char *>(&f2), sizeof(f2));
            cout <<"\t" << f2.date_to_book << "\t" << f2.vacancy << "\t" << f2.team_name << " vs " << f2.opponent_name << "\t\t" << "\t" << f2.seats << "\t" << f2.tot << endl;
        }
        cout << "\nLARGE SIZE\n";
        for (int i = 0; i < 5; i++)
        {
            football f3;
            strcpy(f3.date_to_book,large_size[i]);
            strcpy(f3.vacancy,"NOT-BOOKED");
            strcpy(f3.team_name,"NULL");
            strcpy(f3.opponent_name,"NULL");
            cin>>ws;
            f3.tot=0;
            f3.seats=0;
            file.write(reinterpret_cast<const char *>(&f3), sizeof(f3));
            cout <<"\t" << f3.date_to_book << "\t" << f3.vacancy <<"\t" << f3.team_name << " vs " << f3.opponent_name << "\t\t" << "\t" << f3.seats << "\t" << f3.tot << endl;
        }
        file.close();
    }

    int check()
    {
        if (strcmp(vacancy,"NOT-BOOKED")==0)
        {
            return 1;
        }
        return 0;
    }

    void update(char date[],char tn[],char on[])
    {
        fstream file;
        file.open("football.dat", ios::binary | ios::in | ios::out);
        while (file.read(reinterpret_cast<char*>(this), sizeof(*this)))
        {
            if (strcmp(date_to_book, date) == 0)
            {
                if (check() == 1)
                {
                    strcpy(team_name,tn);
                    strcpy(vacancy, "BOOKED");
                    strcpy(opponent_name,on);
                    file.seekp(file.tellp() - sizeof(*this));
                    file.write(reinterpret_cast<const char*>(this), sizeof(*this));
                    break;
                }
                else
                {
                    cout << "\nSorry, this date is already booked!\n";
                    break;
                }
            }
        }
        file.close();
    }

    void display()
    {
        cout << setw(20) << date_to_book << setw(20) << vacancy << "\t" <<team_name << "  vs  " <<opponent_name << "\t\t" << seats << "\t" << tot << endl;
    }
    void show(int n)
    {
        fstream file("football.dat",ios::binary | ios::in);
        football f;
        int count = 0;
        while(file.read((char*)&f,sizeof(f)))
        {
            if(n==1)
            {
                if(count==0)
                {
                    cout<<"\n\n\t\t\t\tSMALL SIZE\n\n";
                    cout<<setw(20)<<"DATE"<<setw(20)<<"VACANCY"<<"\t   " << "MATCH\t\t" << "SEATS" << "\t" << "TOTAL" << endl;
                }
                if(count>=0)
                {
                    f.display();
                }
                if(count==4)
                {
                    break;
                }
            }
            else if(n==3)
            {
                if(count==5)
                {
                    i=1;
                    cout<<"\n\n\t\t\t\tMEDIUM SIZE\n\n";
                    cout<<setw(20)<<"DATE"<<setw(20)<<"VACANCY"<< "\t   " << "MATCH\t\t" << "SEATS" << "\t" << "TOTAL" << endl;
                }
                if(count>=5)
                {
                    f.display();
                }
                if(count<5)
                {
                    int p=sizeof(f);
                    file.seekg(+p,ios::cur);
                }
                if(count==9)
                {
                    break;
                }
            }
            else if(n==2)
            {
                if(count==10)
                {
                    i=1;
                    cout<<"\n\n\t\t\t\tLARGE SIZE\n\n";
                    cout<<setw(20)<<"DATE"<<setw(20)<<"VACANCY"<< "\t   " << "MATCH\t\t" << "SEATS" << "\t" << "TOTAL" << endl;
                }
                if(count>=10)
                {
                    f.display();
                }
                if(count<10)
                {
                    int p=sizeof(f);
                    file.seekg(+p,ios::cur);
                }
                if(count==14)
                {
                    break;
                }
            }
            else if(n==4)
            {
                if(count==0)
                {
                    cout<<"\n\n\t\t\t\tSMALL SIZE\n\n";
                    cout<<setw(20)<<"DATE"<<setw(20)<<"VACANCY"<< "\t   " << "MATCH\t\t" << "SEATS" << "\t" << "TOTAL" << endl;
                }
                if(count==5)
                {
                    cout<<"\n\n\t\t\t\tMEDIUM SIZE\n\n";
                    cout<<setw(20)<<"DATE"<<setw(20)<<"VACANCY"<< "\t   " << "MATCH\t\t" << "SEATS" << "\t" << "TOTAL" << endl;
                }
                if(count==10)
                {
                    cout<<"\n\n\t\t\t\tLARGE SIZE\n\n";
                    cout<<setw(20)<<"DATE"<<setw(20)<<"VACANCY"<< "\t   " << "MATCH\t\t" << "SEATS" << "\t" << "TOTAL" << endl;
                }
                if(count==15)
                {
                    break;
                }
                f.display();
            }
            count++;
        }
        file.close();
    }
    void book_date();
    void modify(char date[])
    {
        fstream file;
        file.open("football.dat", ios::binary | ios::in | ios::out);
        while (file.read(reinterpret_cast<char*>(this), sizeof(*this)))
        {
            if (strcmp(date_to_book, date) == 0)
            {
                if (check() == 0)
                {
                    strcpy(team_name,"NULL");
                    strcpy(vacancy, "NOT-BOOKED");
                    strcpy(opponent_name,"NULL");
                    file.seekp(file.tellp() - sizeof(*this));
                    file.write(reinterpret_cast<const char*>(this), sizeof(*this));
                    break;
                }
            }
        }
        file.close();
    }
    void update_aud(char date[],int n,int p)
    {
        fstream file;
        file.open("football.dat", ios::binary | ios::in | ios::out);
        while (file.read(reinterpret_cast<char*>(this), sizeof(*this)))
        {
            if (strcmp(date_to_book, date) == 0)
            {
                if (check() == 0)
                {
                    if(seats>100)
                    {
                        cout<<"No seats available : ";
                        break;
                    }
                    else
                    {
                        cout<<"\n\t\t\t\t\tBOOKING\n";
                        sleep(2);
                        cout<<"\n\t\t\t\t\tPAYMENT   :  Rs."<<n*p<<endl;
                        tot=tot+n*p;
                        seats=seats+p;
                    }
                    file.seekp(file.tellp() - sizeof(*this));
                    file.write(reinterpret_cast<const char*>(this), sizeof(*this));
                    break;
                }
                else
                {
                    cout<<"\nNO MATCH AVAILABLE ON THAT DAY\n";
                }
            }
        }
        file.close();
    }
};


void football::book_date()
{
    char date[9];
    bool date_found=false;
    football f;
    system("cls");
    f.getdata();
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tCHOOSE THE SIZE OF THE TOURNAMENT\n"<<endl;
    cout<<"\n\t\t\t\t\t\t1. SMALL SIZE\n"<<endl;
    cout<<"\n\t\t\t\t\t\t2. MEDIUM SIZE\n"<<endl;
    cout<<"\n\t\t\t\t\t\t3. LARGE SIZE\n"<<endl;
    cout<<"\n\t\t\t\t\t\tENTER THE CHOICE : ";
    int choice;
    cin.ignore();
    cin>>choice;
    system("cls");

    show(choice);

    cout<<"\n\n\n\n\n\t\t\t\tEnter the date to be booked : ";
    cin>>date;
    fstream infile("football.dat",ios::binary | ios::in);
    infile.seekg(0,ios::beg);

    switch(choice)
    {
        case 1:
            cout<<"\n\t\t\tEnter team name : ";
            cin>>ws;
            cin.getline(f.team_name,20);
            cout<<"\n\t\t\tEnter the opponent team name : ";
            cin>>ws;
            cin.getline(f.opponent_name,20);
            update(date,f.team_name,f.opponent_name);
            break;
        case 2:
            cout<<"\n\t\t\tEnter team name : ";
            cin>>ws;
            cin.getline(f.team_name,20);
            cout<<"\n\t\t\tEnter the opponent team name : ";
            cin>>ws;
            cin.getline(f.opponent_name,20);
            update(date,f.team_name,f.opponent_name);
            break;
        case 3:
            cout<<"\n\t\t\tEnter team name : ";
            cin>>ws;
            cin.getline(f.team_name,20);
            cout<<"\n\t\t\tEnter the opponent team name : ";
            cin>>ws;
            cin.getline(f.opponent_name,20);
            update(date,f.team_name,f.opponent_name);
            break;
        default:
            cout<<"\nInvalid choice\n";
    }
    infile.close();
    fstream file;
    file.open("football.dat",ios::in);
    file.seekp(0,ios::beg);
    for(int i=0;i<5;i++)
    {
    while(file.read((char*)&f,sizeof(f)))
    {
        if(strcmp(date_to_book,f.date_to_book)==0)
        {
            file.seekp(-sizeof(f),ios::cur);
            file.write((char*)&(*this),sizeof(*this));
            break;
        }
    }
    file.close();
    }
}

class cricket
{
public:
    char team_name[20], opponent_name[20], s, date_to_book[9],vacancy[50];
    int tot=0,seats=0;

public:
    void getdata()
    {
        ofstream file;
        file.open("cricket.dat", ios::binary | ios::in | ios::app);
        cout<<"\nSMALL SIZE\n";
        for(int i = 0; i < 5; i++)
        {
            cricket c1;
            strcpy(c1.date_to_book,small_size[i]);
            strcpy(c1.vacancy,"NOT-BOOKED");
            strcpy(c1.team_name,"NULL");
            strcpy(c1.opponent_name,"NULL");
            cin>>ws;
            c1.tot=0;
            c1.seats=0;
            file.write(reinterpret_cast<const char *>(&c1), sizeof(c1));
            cout <<"\t" << c1.date_to_book << "\t" << c1.vacancy << "\t" << c1.team_name << " vs " << c1.opponent_name << "\t\t" << "\t" << c1.seats << "\t" << c1.tot << endl;
        }
        cout << "\nMEDIUM SIZE\n";
        for (int i = 0; i < 5; i++)
        {
            cricket c2;
            strcpy(c2.date_to_book,medium_size[i]);
            strcpy(c2.vacancy,"NOT-BOOKED");
            strcpy(c2.team_name,"NULL");
            strcpy(c2.opponent_name,"NULL");
            cin>>ws;
            c2.tot=0;
            c2.seats=0;
            file.write(reinterpret_cast<const char *>(&c2), sizeof(c2));
            cout <<"\t" << c2.date_to_book << "\t" << c2.vacancy << "\t" << c2.team_name << " vs " << c2.opponent_name << "\t\t" << "\t" << c2.seats << "\t" << c2.tot << endl;
        }
        cout << "\nLARGE SIZE\n";
        for (int i = 0; i < 5; i++)
        {
            cricket c3;
            strcpy(c3.date_to_book,large_size[i]);
            strcpy(c3.vacancy,"NOT-BOOKED");
            strcpy(c3.team_name,"NULL");
            strcpy(c3.opponent_name,"NULL");
            cin>>ws;
            c3.tot=0;
            c3.seats=0;
            file.write(reinterpret_cast<const char *>(&c3), sizeof(c3));
            cout <<"\t" << c3.date_to_book << "\t" << c3.vacancy << "\t" << c3.team_name << " vs " << c3.opponent_name << "\t\t" << "\t" << c3.seats << "\t" << c3.tot << endl;
        }
        file.close();
    }

    int check()
    {
        if (strcmp(vacancy,"NOT-BOOKED")==0)
        {
            return 1;
        }
        return 0;
    }

    void update(char date[],char tn[],char on[])
    {
        fstream file;
        file.open("cricket.dat", ios::binary | ios::in | ios::out);
        while (file.read(reinterpret_cast<char*>(this), sizeof(*this)))
        {
            if (strcmp(date_to_book, date) == 0)
            {
                if (check() == 1)
                {
                    strcpy(team_name,tn);
                    strcpy(vacancy, "BOOKED");
                    strcpy(opponent_name,on);
                    file.seekp(file.tellp() - sizeof(*this));
                    file.write(reinterpret_cast<const char*>(this), sizeof(*this));
                    break;
                }
                else
                {
                    cout << "\nSorry, this date is already booked!\n";
                    break;
                }
            }
        }
        file.close();
    }

    void display()
    {
        cout << setw(20) << date_to_book << setw(20) << vacancy << "\t" <<team_name << "  vs  " <<opponent_name << "\t\t" << seats << "\t" << tot <<endl;
    }
    void show(int n)
    {
        fstream file("cricket.dat",ios::binary | ios::in);
        cricket c;
        int count = 0;
        while(file.read((char*)&c,sizeof(c)))
        {
            if(n==1)
            {
                if(count==0)
                {
                    i=1;
                    cout<<"\n\n\t\t\t\tSMALL SIZE\n\n";
                    cout<<setw(20)<<"DATE"<<setw(20)<<"VACANCY"<< "\t" << "MATCH\t\t" << "SEATS" << "\t" << "TOTAL" << endl;
                }
                if(count>=0)
                {
                    c.display();
                }
                if(count==4)
                {
                    break;
                }
            }
            else if(n==3)
            {
                if(count==5)
                {
                    i=1;
                    cout<<"\n\n\t\t\t\tMEDIUM SIZE\n\n";
                    cout<<setw(20)<<"DATE"<<setw(20)<<"VACANCY"<< "\t" << "MATCH\t\t" << "SEATS" << "\t" << "TOTAL" << endl;
                }
                if(count>=5)
                {
                    c.display();
                }
                if(count<5)
                {
                    int p=sizeof(c);
                    file.seekg(+p,ios::cur);
                }
                if(count==9)
                {
                    break;
                }
            }
            else if(n==2)
            {
                if(count==10)
                {
                    i=1;
                    cout<<"\n\n\t\t\t\tLARGE SIZE\n\n";
                    cout<<setw(20)<<"DATE"<<setw(20)<<"VACANCY"<< "\t" << "MATCH\t\t" << "SEATS" << "\t" << "TOTAL" << endl;
                }
                if(count>=10)
                {
                    c.display();
                }
                if(count<10)
                {
                    int p=sizeof(c);
                    file.seekg(+p,ios::cur);
                }
                if(count==14)
                {
                    break;
                }
            }
            else if(n==4)
            {
                if(count==0)
                {
                    i=1;
                    cout<<"\n\n\t\t\t\tSMALL SIZE\n\n";
                    cout<<setw(20)<<"DATE"<<setw(20)<<"VACANCY"<< "\t" << "MATCH\t\t" << "SEATS" << "\t" << "TOTAL" << endl;
                }
                if(count==5)
                {
                    cout<<"\n\n\t\t\t\tMEDIUM SIZE\n\n";
                    cout<<setw(20)<<"DATE"<<setw(20)<<"VACANCY"<< "\t" << "MATCH\t\t" << "SEATS" << "\t" << "TOTAL" << endl;
                }
                if(count==10)
                {
                    cout<<"\n\n\t\t\t\tLARGE SIZE\n\n";
                    cout<<setw(20)<<"DATE"<<setw(20)<<"VACANCY"<< "\t" << "MATCH\t\t" << "SEATS" << "\t" << "TOTAL" << endl;
                }
                if(count==15)
                {
                    break;
                }
                c.display();
            }
            count++;
        }
        file.close();
    }
    void modify(char date[])
    {
        fstream file;
        file.open("cricket.dat", ios::binary | ios::in | ios::out);
        while (file.read(reinterpret_cast<char*>(this), sizeof(*this)))
        {
            if (strcmp(date_to_book, date) == 0)
            {
                if (check() == 0)
                {
                    strcpy(team_name,"NULL");
                    strcpy(vacancy, "NOT-BOOKED");
                    strcpy(opponent_name,"NULL");
                    file.seekp(file.tellp() - sizeof(*this));
                    file.write(reinterpret_cast<const char*>(this), sizeof(*this));
                    break;
                }
            }
        }
        file.close();
    }
    void book_date();
    void update_aud(char date[],int n,int p)
    {
        fstream file;
        file.open("cricket.dat", ios::binary | ios::in | ios::out);
        while (file.read(reinterpret_cast<char*>(this), sizeof(*this)))
        {
            if (strcmp(date_to_book, date) == 0)
            {
                if (check() == 0)
                {
                    if(seats>100)
                    {
                        cout<<"No seats available : ";
                        break;
                    }
                    else
                    {
                        cout<<"\n\t\t\t\t\tBOOKING\n";
                        sleep(2);
                        cout<<"\n\t\t\t\t\tPAYMENT   :  Rs."<<n*p<<endl;
                        tot=tot+n*p;
                        seats=seats+n;
                    }
                    file.seekp(file.tellp() - sizeof(*this));
                    file.write(reinterpret_cast<const char*>(this), sizeof(*this));
                    break;
                }
                else
                {
                    cout<<"\nNO MATCH AVAILABLE ON THAT DAY\n";
                }
            }
        }
        file.close();
    }
};


void cricket::book_date()
{
    char date[9];
    bool date_found=false;
    int ch;

    cricket c;
    system("cls");
    c.getdata();
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\tCHOOSE THE SIZE OF THE TOURNAMENT\n"<<endl;
    cout<<"\t\t\t\t\t\t1. SMALL SIZE\n"<<endl;
    cout<<"\t\t\t\t\t\t2. MEDIUM SIZE\n"<<endl;
    cout<<"\t\t\t\t\t\t3. LARGE SIZE\n"<<endl;
    cout<<"\n";
    cout<<"\t\t\t\t\t\tENTER THE CHOICE : ";
    cin.ignore();
    cin>>ch;
    system("cls");
    show(ch);
    cout<<"\n\n\n\n\t\t\t\tEnter the date to be booked : ";
    cin>>date;


    fstream infile("football.dat",ios::binary | ios::in);
    infile.seekg(0,ios::beg);

    switch(ch)
    {
        case 1:
            cout<<"\n\t\t\t\tEnter team name : ";
            cin>>ws;
            cin.getline(c.team_name,20);
            cout<<"\n\t\t\t\tEnter the opponent team name : ";
            cin>>ws;
            cin.getline(c.opponent_name,20);
            update(date,c.team_name,c.opponent_name);
            break;
        case 2:
            cout<<"\n\t\t\t\tEnter team name : ";
            cin>>ws;
            cin.getline(c.team_name,20);
            cout<<"\n\t\t\t\tEnter the opponent team name : ";
            cin>>ws;
            cin.getline(c.opponent_name,20);
            update(date,c.team_name,c.opponent_name);
            break;
        case 3:
            cout<<"\n\t\t\t\tEnter team name : ";
            cin>>ws;
            cin.getline(c.team_name,20);
            cout<<"\n\t\t\t\tEnter the opponent team name : ";
            cin>>ws;
            cin.getline(c.opponent_name,20);
            update(date,c.team_name,c.opponent_name);
            break;
        default:
            cout<<"\nInvalid choice\n";
    }
    infile.close();
    fstream file;
    file.open("cricket.dat",ios::in);
    file.seekp(0,ios::beg);
    for(int i=0;i<5;i++)
    {
    while(file.read((char*)&c,sizeof(c)))
    {
        if(strcmp(date_to_book,c.date_to_book)==0)
        {
            file.seekp(-sizeof(c),ios::cur);
            file.write((char*)&(*this),sizeof(*this));
            break;
        }
    }
    file.close();
    }

}

class audience:public basketball,public cricket,public football
{
    public:
        void getdata(int n)
        {
            system("cls");
            if(n==1)
            {
                char s[9];
                int r,count=0,no,n;
                fstream file;
                file.open("basket.dat",ios::binary | ios::in | ios::out);
                basketball b;
                b.show(4);

                cout<<"\n\n\n\n\t\t\tEnter the date of the match do you want to book : ";
                cin >> s;
                cout<<"\n\t\t\tEnter the number of seats do you want to book : ";
                cin>>no;
                b.update_aud(s,no,100);
            }
            else if(n==2)
            {
                char s[9];
                int r,count=0,no,n;
                fstream file;
                file.open("football.dat",ios::binary | ios::in | ios::out);
                football f;
                f.show(4);

                cout<<"\n\n\n\n\t\t\tEnter the date of the match do you want to book : ";
                cin >> s;
                cout<<"\n\t\t\tEnter the number of seats do you want to book : ";
                cin>>no;
                f.update_aud(s,no,100);
            }
            else if(n==3)
            {
                char s[9];
                int r,count=0,no,n;
                fstream file;
                file.open("cricket.dat",ios::binary | ios::in | ios::out);
                cricket c;
                c.show(4);

                cout<<"\n\n\n\n\t\t\tEnter the date of the match do you want to book : ";
                cin >> s;
                cout<<"\n\t\t\tEnter the number of seats do you want to book : ";
                cin>>no;
                c.update_aud(s,no,100);
            }
        }

};

class tournament
{
        private:
                //string;
        public:
                tournament()
                {
                        int n;
                        cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tEnter 1 if you are a player\n\n\t\t\t\t\t\tEnter 2 if you are a audience\n";
                        cin>>n;
                        if(n==1)
                        {
                                int n;
//                                login();
                                begin:
                                system("cls");
                                cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\tSELECT THE SPORT\n\n";
                                cout<<"\t\t\t\t\t\t1.Basket ball\n\n\t\t\t\t\t\t2.Foot Ball\n\n\t\t\t\t\t\t3.Cricket\n";
                                cin>>n;
                                if(n==1)
                                {
                                        system("cls");
                                        basketball b;
                                        int choice;
                                        do {
                                                cout << "\n\n\n\n\n\n\n\n\t\t\t\tBASKETBALL TOURNAMENT BOOKING SYSTEM\n\n";
                                                cout << "\t\t\t\t\t1. Book a date\n\n";
                                                cout << "\t\t\t\t\t2. Show all bookings\n\n";
                                                cout << "\t\t\t\t\t3. Modify\n\n";
                                                cout << "\t\t\t\t\t4. Cancel the booking\n\n";
                                                cout << "\t\t\t\t\t5. Exit\n\n";
                                                cout << "\t\t\t\t\tEnter your choice: ";
                                                cin >> choice;
                                                cin.ignore();
                                                switch(choice) {
                                                    case 1:
                                                        b.book_date();
                                                        break;
                                                    case 2:
                                                        b.show(4);
                                                        break;
                                                    case 3:
                                                        char date1[9],date2[9];
                                                        cout << "\nEnter the old date booked : ";
                                                        cin >> date1;
                                                        cout << "Enter the new details\n";
                                                        b.book_date();
                                                        b.modify(date1);
                                                        break;
                                                    case 4:
                                                        char date[9];
                                                        cout << "Enter the date already booked : ";
                                                        cin>>date;
                                                        b.modify(date);
                                                        break;
                                                    case 5:
                                                        cout << "\n\n\t\tThank you for using the basketball tournament booking system\n\n";
                                                        cout<<"\n\n\t\t\t\tSIGNING OUT...";
                                                        sleep(3);
                                                        break;
                                                    default:
                                                        cout << "\nInvalid choice. Please try again.\n";
                                                }
                                        cout<<"\nLOADING....\n";
                                        sleep(5);
                                        system("cls");
                                        } while(true);
                                }
                                else if(n==2)
                                {
                                        system("cls");
                                        football f;
                                        int choice;
                                        do {
                                                cout << "\n\n\n\n\n\n\n\n\n\t\t\t\tFOOTBALL TOURNAMENT BOOKING SYSTEM\n\n";
                                                cout << "\t\t\t\t\t1. Book a date\n\n";
                                                cout << "\t\t\t\t\t2. Show all bookings\n\n";
                                                cout << "\t\t\t\t\t3. Modify\n\n";
                                                cout << "\t\t\t\t\t4. Cancel booking\n\n";
                                                cout << "\t\t\t\t\t5. Exit\n\n";
                                                cout << "\t\t\t\t\tEnter your choice: ";
                                                cin >> choice;
                                                cin.ignore();
                                                switch(choice) {
                                                    case 1:
                                                        f.book_date();
                                                        break;
                                                    case 2:
                                                        f.show(4);
                                                        break;
                                                    case 3:
                                                        char date1[9],date2[9];
                                                        cout << "\nEnter the old date booked : ";
                                                        cin >> date1;
                                                        cout << "Enter the new details\n";
                                                        f.book_date();
                                                        f.modify(date1);
                                                        break;
                                                    case 4:
                                                        char date[9];
                                                        cout << "Enter the date already booked : ";
                                                        cin>>date;
                                                        f.modify(date);
                                                        break;
                                                    case 5:
                                                        cout << "\n\n\t\tThank you for using the basketball tournament booking system\n\n";
                                                        exit(0);
                                                    default:
                                                        cout << "\nInvalid choice. Please try again.\n";
                                                }
                                        sleep(5);
                                        system("cls");
                                        } while(true);
                                }
                                else if(n==3)
                                {
                                        system("cls");
                                        cricket c;
                                        int choice;
                                        do {
                                                cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tCRICKET TOURNAMENT BOOKING SYSTEM\n\n";
                                                cout << "\t\t\t\t\t\t1. Book a date\n\n";
                                                cout << "\t\t\t\t\t\t2. Show all bookings\n\n";
                                                cout << "\t\t\t\t\t\t3. Modify\n\n";
                                                cout << "\t\t\t\t\t\t4. Cancel booking\n\n";
                                                cout << "\t\t\t\t\t\t5. Exit\n\n";
                                                cout << "\t\t\t\t\t\tEnter your choice: ";
                                                cin >> choice;
                                                cin.ignore();
                                                switch(choice) {
                                                    case 1:
                                                        c.book_date();
                                                        break;
                                                    case 2:
                                                        c.show(4);
                                                        break;
                                                    case 3:
                                                        char date1[9],date2[9];
                                                        cout << "\nEnter the old date booked : ";
                                                        cin >> date1;
                                                        cout << "Enter the new details\n";
                                                        c.book_date();
                                                        c.modify(date1);
                                                        break;
                                                    case 4:
                                                        char date[9];
                                                        cout << "Enter the date already booked : ";
                                                        cin>>date;
                                                        c.modify(date);
                                                    case 5:
                                                        cout << "\n\n\t\tThank you for using the basketball tournament booking system\n\n";
                                                        exit(0);
                                                    default:
                                                        cout << "\nInvalid choice. Please try again.\n";
                                                }
                                        sleep(5);
                                        system("cls");
                                        } while(true);
                                }
                                else
                                {
                                        cout<<"\nEnter the Correct Game : ";
                                        goto begin;
                                }
                        }
                        else
                        {
                            int choice;
 //                         login();
                            system("cls");
                            cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\tSELECT THE SPORT\n\n";
                            cout<<"\t\t\t\t\t\t1.Basket ball\n\n\t\t\t\t\t\t2.Foot Ball\n\n\t\t\t\t\t\t3.Cricket\n";
                            cin>>choice;
                            audience a;
                            a.getdata(choice);
                        }
                }
};


int main()
{
    tournament t;
    return 0;
}
