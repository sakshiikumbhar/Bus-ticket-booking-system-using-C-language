#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<inttypes.h>
struct Ticketbooking
{
    char name[100];
    char city[100];
    char mail[50];
    char gender[50];
    long long int mobilenumber;
    long password;
    char birthCity[20];
};
//struct Ticketbooking user;
struct Ticketbooking U;
struct BusInformation
{
    char busname[20];
    char time[30];
    int seat [20];
    int price;
    // int busnumber;
};
struct BusInformation Buses[9];
void account();
void logout();
void Menu();
void Bus();
int getBookedSeats(int busIndex, int bookedSeats[]);
int userLogin=0;

struct Ticketbooking CreateAccount(struct Ticketbooking user)
{
    printf("\t\t\t1.Enter name of user: ");
    gets(user.name);
    printf("\t\t\t2.Enter the city: ");
    scanf("%s",user.city);
    printf("\t\t\t3.Enter user mobile number[only numbers]: ");
    scanf("%lld",&user.mobilenumber);
    printf("\t\t\t4.Enter user gender[M/F/O]: ");
    scanf("%s",user.gender);
    printf("\t\t\t5.Enter mail address: ");
    scanf("%s",user.mail);
    printf("\t\t\t6.Create your pin[4 digit number pin] : ");
    scanf("%ld",&user.password);
    printf("\t\t\t7.Security question:\n\t\t\t-->Enter birth city : ");
    scanf("%s",user.birthCity);

    return user;
}
void message()
{
    system("cls");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Date and time: %d-%02d-%02d %02d:%02d:%02d\n",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    if(userLogin==1)
    {
        printf("Current user:%s",U.name);
    }
    printf("\n\t\t\t\t---------------------ONLINE TICKET BOOKING---------------------\n");
    printf("\t\t\t\t   Hey user welcome to ******* online ticket booking service\n\n");
    printf("   ==================================================================================================================================");
}
void ToDisplay()
{

    int rchoice;
    message();
    printf("\n\n\t-->>USER DETAILS ARE:\n\t\t\t    1.Name: ");
    puts(U.name);
    printf("\t\t\t    2.City: %s",U.city);
    printf("\n\t\t\t    3.Mobile number: %lld",U.mobilenumber);
    printf("\n\t\t\t    4.Gender: %s",U.gender);
    printf("\n\t\t\t    5.Mail address: %s",U.mail);
    printf("\n\t\t\t    6.Pin: %ld",U.password);
    printf("\n\t\t\t    7.BirthCity: %s",U.birthCity);

    printf("\n\n\tBack to account menu press 1 and for Main menu press 2 and to logout press 3\n\tEnter your choice: ");
    scanf("%d",&rchoice);
    if(rchoice==1)
    {
        account();
    }
    else if(rchoice==2)
    {
        system("cls");
        Menu();
    }
    else if(rchoice==3)
    {
        logout();
    }
    else
    {
        printf("Invalid input.\n");
    }
}
void EditUser()
{
    int echoice;
    int eisreap=0;

    do
    {
        if(eisreap==0||eisreap==1)
        {
            system("cls");
            message();
            printf("\n\n\t-->What you want to edit in your profile?");
            printf("\n\t\t\t\t\t1.Name:\n\t\t\t\t\t2.City:\n\t\t\t\t\t3.Mobile Number:\n\t\t\t\t\t4.Gender:\n\t\t\t\t\t5.Mail id:\n\t\t\t\t\t6.Pin:");
            printf("\n\t-------------------------------------------------------------");
            printf("\n\tEnter your choice: ");
            scanf("%d",&echoice);
            switch(echoice)
            {
            case 1:
            {
                printf("\n\tCurrent name: ");
                puts(U.name);
                printf("\tEnter new name: ");
                scanf(" %[^\n]", U.name);
                printf("\tUpdated Name: %s\n",U.name);
                break;
            }
            case 2:
            {
                printf("\n\tCurrent City: %s",U.city);
                printf("\n\tEnter new city: ");
                scanf("%s",U.city);
                printf("\tUpdated city: %s\n",U.city);
                break;
            }
            case 3:
            {
                printf("\n\tCurrent Mobile number: %lld",U.mobilenumber);
                printf("\n\tEnter new Mobile number: ");
                scanf("%lld",&U.mobilenumber);
                printf("\tUpdated Mobile number: %lld\n",U.mobilenumber);
                break;
            }
            case 4:
            {
                printf("\n\tCurrent Gender: %s",U.gender);
                printf("\n\tEnter new Gender: ");
                scanf("%s",U.gender);
                printf("\tUpdated Gender: %s\n",U.gender);
                break;
            }
            case 5:
            {
                printf("\n\tCurrent Mail id: %s",U.mail);
                printf("\n\tEnter new Mail id: ");
                scanf("%s",U.mail);
                printf("\tUpdated Mail id: %s\n",U.mail);
                break;
            }
            case 6:
            {
                printf("\n\tCurrent Pin: %ld",U.password);
                printf("\n\tEnter new pin: ");
                scanf("%ld",&U.password);
                printf("\tUpdated Pin: %ld\n",U.password);
                break;
            }
            }
        }
        printf("\n\t\tDo you want to more edit your profile press 1\n\t\tBack to account menu press 2\n\t\tBack to main menu press 3\n\t\tTo logout press 4\n\t\tEnter your choice: ");
        scanf("%d",&eisreap);
    }
    while(eisreap==1);
    if(eisreap==3)
    {
        system("cls");
        Menu();
    }
    else if(eisreap==2)
    {
        system("cls");
        account();
    }
    else if(eisreap==4)
    {
        logout(U);
    }
}
void account()
{
    system("cls");
    int achoice;
    message();
    printf("\n\n\t\t-->>Account:\n\t\t\t   1.Display user profile: \n\t\t\t   2.Edit user profile: \n\t\t\t   3.Main menu: \n\t\t\t   4.Logout:  \n\t\t\t   Enter your choice:");
    scanf("%d",&achoice);
    switch(achoice)
    {
    case 1:
    {
        system("cls");
        ToDisplay();
        break;
    }
    case 2:
    {
        system("cls");
        EditUser();
        break;
    }
    case 3:
    {
        system("cls");
        Menu();
        break;
    }
    case 4:
    {
        logout();
        break;
    }
    default:
    {
        printf("Invalid input..Please try again.\n");
        break;
    }
    }
}

void payment(int seats[], int seatCount)
{
    system("cls");
    message();
    int confirmIndex=2;
    int totalPayment= Buses[0].price * seatCount;
    printf("\n\n\t\t\t-->Payment:\n\t\t\t\tTotal payment amount= %d Rs \n\t\t\t\tYour booking is confirmed\n\n\t\t\tPress 1 to continue", totalPayment);
    scanf("%d",&confirmIndex);
    Bus();
}
void printBus ()
{
    printf("\n test\n");
    for(int i=0; i<20; i++)
    {
        printf("%d ", Buses[0].seat[i]);
    }
}
int checkForBookedSeat(int seatNo[], int busesIndex, int seatCount)
{
    int isAlreadyBooked = 0;
    for (int i=0; i < seatCount; i++)
    {
        if(Buses[busesIndex].seat[seatNo[i]- 1] == 1)
        {
            isAlreadyBooked = 1;
            break;
        }
    }
    return isAlreadyBooked;
}

void Seat1(int busIndex, int timeIndex)
{
    int seatCount;
    int seatNo[20];
    int busesIndex = (busIndex - 1) * 3 + (timeIndex-1);
    int alreadyBookSeatChoice;
    do
    {
        system("clear");
        message();
        printf("\n\t\t\tAvailable seats are: \n\n\t\t\t");
        for(int i=0; i<20; i++)
        {
            if(Buses[busesIndex].seat[i] == 0)
            {
                printf("Empty  -> %d", i+1 );
            }
            else
            {
                printf("Resevered -> %d", i+1 );
            }
            if(i % 2 == 1)
            {
                printf("\n\t\t\t");
            }
            else
            {
                printf("\t\t\t");
            }
        }
        printf("\n\t\t\tEnter how many seats: ");
        scanf("%d",&seatCount);

        printf("\n\t\t\tEnter seats no : ");
        for(int i=0; i<seatCount; i++)
        {
            scanf("%d",&seatNo[i]);
        }
        int isAlreadyBooked = checkForBookedSeat(seatNo, busesIndex, seatCount);
        if (isAlreadyBooked == 1)
        {
            printf("\n\t\t\tSelected Seats are already reserved.\n\t\t\tPress 1 to select seat again: ");
            scanf("%d",&alreadyBookSeatChoice);
        }
        else
        {
            alreadyBookSeatChoice = 2;
        }
    }
    while(alreadyBookSeatChoice == 1);
    for(int i=0; i<seatCount; i++)
    {
        Buses[busesIndex].seat[seatNo[i]- 1] = 1;
    }
    //Seat1();
    payment(seatNo, seatCount);
}
void bookBus(int busChoice)
{
    system("cls");
    message();
    int pnchoice;
    char busname[20];
    int busIndex = busChoice-1;
    if(busIndex == 0)
    {
        strcpy(busname, "Pune to Nashik");
    }
    else if(busIndex == 1)
    {
        strcpy(busname, "Pune to Mumbai");
    }
    else if(busIndex == 2)
    {
        strcpy(busname, "Pune to Sangli");
    }
    printf("\n\n\t\t-->%s:\n\t\t\tBus Schedules:\n\t\t\t\n\t\t\tDeparture\tArrival", busname);
    printf("\n\t\t-------------------------------------------");
    printf("\n\t\t\t1.08:30AM   -   02:00PM\n\t\t\t2.11:30AM   -   06:00PM\n\t\t\t3.02:00PM   -   08:30PM\n\n\t\t\tEnter your choice: ");
    scanf("%d",&pnchoice);
    Seat1(busChoice, pnchoice);
}
void Bookticket()
{
    system("cls");
    message();
    int choice;
    printf("\n\t\t-->>Book Tickets:\n\t\t\tAvailable bus schedules: ");
    printf("\n\t\t\t1.Pune to Nashik\n\t\t\t2.Pune to Mumbai\n\t\t\t3.Pune to Sangli\n\t\t\tEnter your choice: ");
    scanf("%d",&choice);
    bookBus(choice);
}
void CancleSeat1(int busIndex, int timeIndex)
{
    int seatCount, choice;
    int seatNo[20];
    system("cls");
    message();
    int bookedSeats[20];
    int busesIndex = (busIndex - 1) * 3 + (timeIndex-1);
    int bookedseatIndex = getBookedSeats(busesIndex, bookedSeats);
    printf("\n\n\t\t-->>Cancel ticket");
    if(bookedseatIndex > 0)
    {
        printf("\n\t\t\tBus Name => %s\n\t\t\tBus Time => %s\n\t\t\tNo. of Booking => %d\n\t\t\tBooked seat Nos => ", Buses[busesIndex].busname, Buses[busesIndex].time, bookedseatIndex);
        for (int j=0; j< bookedseatIndex; j++)
        {
            printf("%d ", bookedSeats[j]);
        }
        printf("\n\t\t\tPrice per ticket => %dRs", Buses[busesIndex].price);
        printf("\n\t\t\tPaid Amount => %d * %d = %dRs\n\n", Buses[busesIndex].price, bookedseatIndex, bookedseatIndex * Buses[busesIndex].price);
    }
    else
    {
        printf("\n\t\t\tNo booking\n");
        printf("Enter 1 to menu\n");
        scanf("%d",&choice);
        Bus();
    }
    printf("\n\t\tEnter how many seats you want to cancel: ");
    scanf("%d",&seatCount);

    printf("\n\t\tEnter seats no : ");
    for(int i=0; i<seatCount; i++)
    {
        scanf("%d",&seatNo[i]);
    }
    for(int i=0; i<seatCount; i++)
    {
        Buses[busesIndex].seat[seatNo[i]- 1] = 0;
    }
    Bus();
}
void CancleBus(int busChoice)
{
    system("cls");
    message();
    int pnchoice;
    char busname[20];
    int busIndex = busChoice-1;
    if(busIndex == 0)
    {
        strcpy(busname, "Pune to Nashik");
    }
    else if(busIndex == 1)
    {
        strcpy(busname, "Pune to Mumbai");
    }
    else if(busIndex == 2)
    {
        strcpy(busname, "Pune to sangli");
    }
    printf("\n\n\t\t-->%s:\n\t\t\tBus Schedules:\n\t\t\t\n\t\t\tDeparture\tArrival", busname);
    printf("\n\t\t-------------------------------------------");
    printf("\n\t\t\t1.08:30AM   -   02:00PM\n\t\t\t2.11:30AM   -   06:00PM\n\t\t\t3.02:00PM   -   08:30PM\n\n\t\tEnter your choice: ");
    scanf("%d",&pnchoice);
    CancleSeat1(busChoice, pnchoice);
}
void Cancleticket()
{
    system("cls");
    message();
    int choice;
    printf("\n\n\t\t\t-->>Book Tickets:\n\t\t\t\tAvailable bus schedules: ");
    printf("\n\t\t\t\t1.Pune to Nashik\n\t\t\t\t2.Pune to Mumbai\n\t\t\t\t3.Pune to Sangli\n\t\t\t\tEnter your choice: ");
    scanf("%d",&choice);
    CancleBus(choice);
}
int getBookedSeats(int busIndex, int bookedSeats[])
{
    int bookedseatIndex = 0;
    for(int i=0; i< 20; i++)
    {
        if(Buses[busIndex].seat[i] == 1)
        {
            bookedSeats[bookedseatIndex] = i + 1;
            bookedseatIndex++;
        }
    }
    return bookedseatIndex;
}
void BookingStatus ()
{
    int bookedSeats[20];
    system("cls");
    message();
    printf("\n\n\t\t-->>Booking Status");
    int flag = 1,choice;
    for (int i=0; i< 9; i++)
    {
        int bookedseatIndex = getBookedSeats(i, bookedSeats);
        if(bookedseatIndex > 0)
        {
            printf("\n\t\t\tBus Name => %s\n\t\t\tBus Time => %s\n\t\t\tNo. of Booking => %d\n\t\t\tBooked seat Nos => ", Buses[i].busname, Buses[i].time, bookedseatIndex);
            for (int j=0; j< bookedseatIndex; j++)
            {
                printf("%d ", bookedSeats[j]);
            }
            printf("\n\t\t\tPrice per ticket => %dRs", Buses[i].price);
            printf("\n\t\t\tPaid Amount => %d * %d = %dRs\n\n", Buses[i].price, bookedseatIndex, bookedseatIndex * Buses[i].price);
            flag=0;
        }
    }
    if(flag)
    {
        printf("\n\t\t\tNo booking");
    }
    printf("\n\t\tEnter 1 to bus menu and 2 for main menu\n");
    scanf("%d",&choice);
    if(choice == 1)
    {
        Bus();
    }
    else if(choice == 2)
    {
        Menu();
    }
}
void Bus()
{
    system("cls");
    message();
    int bchoice;
    printf("\n\n\t\t-->>Bus_buss_busbus: ");
    printf("\n\t\t\t\t   1.Book Tickets\n\t\t\t\t   2.Cancel Booking\n\t\t\t\t   3.Booking Status\n\t\t\t\t   4.Main menu\n\t\t\t   Enter your choice: ");
    scanf("%d",&bchoice);
    switch(bchoice)
    {
    case 1:
    {
        Bookticket();
        break;
    }
    case 2:
    {
        Cancleticket();
        break;
    }
    case 3:
    {
        BookingStatus();
        break;
    }
    case 4:
    {
        Menu();
        break;
    }
    }
}
void help()
{
    int rchoice;
    system("cls");
    message();
    printf("\n\n\t\t-->>Help:");
    printf("\n\t\t\t1.Toll Free - Helpline Number: xxxx xx xxxx");
    printf("\n\t\t\t2.Mail - ********@***.org/");
    printf("\n\t\t\t3.Facebbook - facebook.com/*****Online_bus_service/");
    printf("\n\t\t\t4.Twitter - twitter.com/****OnlineBusService/\n");
    printf("\n\t\t\tBack to account menu press 1");
    scanf("%d",&rchoice);
    Menu();
}
void about()
{
    int aboutchoice;
    system("cls");
    message();
    printf("\n\n\t\t\tOUR MOTTO : SAFE AND ACCIDENT FREE BUS SERVICE\n\n");
    printf("\n\t\t\tBack to account menu press 1");
    scanf("%d",&aboutchoice);
    Menu();
}
void lgoutmessage()
{
    system("cls");
    message();
    printf("\n\n\n\n\t\t\t\t'Dear user you have been successfully logout from this session.'\n");
    printf("\t\t\t\t\t\t---Thank you & visit again---\n");
    printf("\t\t\t\t\t\t\t    ***\n\n\n");
}
void logout()
{
    int lgout;
    printf("\n\t\tAre you sure to logout?\n\t\tIf Yes press 1 and to continue with main menu press 2\n\t\tEnter your choice: ");
    scanf("%d",&lgout);
    if(lgout==1)
    {
        userLogin=0;
        lgoutmessage();
    }
    else
    {
        system("cls");
        Menu();
    }
}
void Menu()
{
//    struct BusInformation bus;
    int mchoice;
    int isreap=1;
    system("cls");
    message();
    printf("\n\n\t\t-->>MENU:\n");
    printf("\t\t\t1.Account: \n\t\t\t2.Bus_buss_busbus: \n\t\t\t3.Help: \n\t\t\t4.About us: \n\t\t\t5.Logout: \n\t\tEnter your choice: ");
    scanf("%d",&mchoice);
    if(mchoice==1)
    {
        account();
    }
    if(mchoice==2)
    {
        Bus();
    }
    if(mchoice==3)
    {
        help();
    }
    if(mchoice==4)
    {
        about();
    }
    if(mchoice==5)
    {
        logout();
    }
}
void getBusName(int busIndex, char *busName)
{
    switch(busIndex)
    {
    case 0:
    {
        busName = "PN";
    }
    case 1:
    {
        busName = "PM";
    }
    case 2:
    {
        busName = "PS";
    }
    }
}
void feedBusData(struct BusInformation Buses[9])
{
    int i,j,k;
    for(i=0; i<3; i++)
    {
        for(j=0; j< 3; j++)
        {
            int seat[20];
            struct BusInformation B1;
            if(i == 0)
            {
                strcpy(B1.busname, "Pune to Nashik");
                B1.price = 450;
            }
            else if(i == 1)
            {
                strcpy(B1.busname, "Pune to Mumbai");
                B1.price = 250;
            }
            else if(i == 2)
            {
                strcpy(B1.busname, "Pune to sangli");
                B1.price = 350;
            }
            if(j == 0)
            {
                strcpy(B1.time, "08:30AM - 02:00PM");
            }
            else if(j == 1)
            {
                strcpy(B1.time, "11:30AM - 06:00PM");
            }
            else if(j == 2)
            {
                strcpy(B1.time, "02:00PM - 08:30PM");
            }
            int busIndex = i * 3 + j;
            Buses[busIndex] = B1;
            for(k=0; k<20; k++)
            {
                Buses[busIndex].seat[k]=0;
            }
        }
    }
}
void forgetPassword()
{

}
int main()
{
    struct Ticketbooking user;
    // struct Ticketbooking U;
    feedBusData(Buses);
    long long login;
    long pass;
    int choice;
    int nchoice=1;
    message();
    printf("\n\t\t-->>Before you start please create your account..\n\n");
    U=CreateAccount(user);
    //BusDetails(bus);
    system("cls");
    do
    {
        if(nchoice==1)
        {
            message();
            printf("\n\n\t\t\t\t\t\t    Congratulation...");
            //printf("");
            // printf("''");
            //puts(U.name);
            printf("\n\t\t\t\t\t\t\t'%s'\n",U.name);
            //printf("''");
            printf("\t\t\t\t\tYour account has been created successfully!!");
            printf("\n\t\t\t      [Use your mobile number as your username and password is your pin]\n");
            printf("\t\t\t\t..............................................................");
            printf("\n\n\t\t\t-->>LOGIN CREDENTIALS:");
            printf("\n\t\t\t\t   1.Enter username: ");
            scanf("%lld",&login);
            printf("\t\t\t\t   2.Enter pin: ");
            scanf("%ld",&pass);
            if(login==U.mobilenumber&&pass==U.password)
            {
                system("cls");
                userLogin=1;
                printf("\t\t\t\tYou log in succesfully\n");
                printf("\t\t\t\tGo ahead...\n");
                nchoice++;
                Menu();
            }
            else
            {
                system("cls");
                message();
                printf("\n\t\t\t\tOps something went wrong..\n\t\t\t\tPlease try again\n\n\t\t\t\tPress 1 for login page and 0 for exit and press 2 for forget password: ");
                scanf("%d",&nchoice);
                system("cls");
                if(nchoice==2)
                {
                    char ans[20];
                    int choice;
                    do
                    {
                        message();
                        printf("\n\t\t-->>Forget Password:");
                        printf("\n\t\t\tEnter your Birth City: ");
                        scanf("%s",ans);
                        //printf("%s and %s",ans,U.birthCity);

                        if(!strcmp(ans,U.birthCity))
                        {
                            printf("\n\t\t\t    1.Username: %lld",U.mobilenumber);
                            printf("\n\t\t\t    2.Pin: %ld\n",U.password);
                            printf("\n\t\t\tFor relogin press 1: ");
                            scanf("%d",&nchoice);
                            break;

                        }
                        else
                        {
                            printf("wrong ans.try again..press 1 to retrie again");
                            scanf("%d",&choice);
                        }

                    }
                    while(choice==1);

                }
            }
        }
    }
    while(nchoice==1);
    if(nchoice==0)
    {
        system("cls");
        message();
        printf("\n\n\t\t\t\t\t\t---Thank you & visit again---\n");
        printf("\t\t\t\t\t\t\t    ***\n\n\n");
    }
    return 0;
}
