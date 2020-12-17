/* Theatre Member's Club */

//Header Files
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

/* All the structures starts from here*/
struct nameType
{
    char firstName[15];
    char middleName[15];
    char lastName[15];
    char userName[15];
    char userFullName[50];
};
struct passwordType
{
    char userPassword[15];
};
struct userType
{
    struct nameType name;
    struct passwordType password;
    char userEmail[25];
    char userAddress[80];
    char userBio[100];
    char userContact[15];
};
struct movieType
{
    char movieName[15];
    int movieNumber;
    float averageRatings;
    char movieDetails[500];
    char movieDate[20];
    char movieTime[20];
    int moviePrice;
};

struct Activity
{
    int discount;
    char activeUser[20];
    float totalMoviePrice;
    char movieBooked[25];
    int totalSeat;
};
struct FeedBack
{
    float rating;
    char watchedMovie[25];
    char review[500];
    char person[20];
};
/* All the structures ends from here*/

/* All the Global Variable Declaration starts from here*/
COORD coord = {0,0};
struct userType user;
long int userSize = sizeof(user);
struct userType developer;
long int developerSize = sizeof(developer);
struct movieType movie;
long int movieSize = sizeof(movie);
struct Activity registeredUser;
long int activitySize = sizeof(registeredUser);
struct FeedBack movieFeedback;
long int feedbackSize = sizeof(movieFeedback);
char *message = "Thank you for being with us. If you have any query, please contact on this number 17271.";
char *location = "Location: Plot no. 282, Dania, 3rd Floor";
/* All the Global Variable Declaration ends from here*/
/* gotoxy function to move the cursor in specified position of console*/
void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
/* 1. This function display Main Menu */
void displayMainMenu()
{
    gotoxy(50,5);
    printf("W E L C O M E");
    gotoxy(45,7);
    printf("THEATRE MEMBER'S CLUB");
    gotoxy(50,11);
    printf("Main Menu");
    gotoxy(45,14);
    printf("1. Create New Account");
    gotoxy(45,16);
    printf("2. Login As Admin");
    gotoxy(45,18);
    printf("3. Login As User");
    gotoxy(45,20);
    printf("4. Exit");
    fflush(stdin);
}
/* 2. This function display Admin's Menu */
void displayAdminMenu()
{
    gotoxy(45,5);
    printf("W E L C O M E   A D M I N");
    gotoxy(45,7);
    printf("THEATRE MEMBER'S CLUB");
    gotoxy(50,11);
    printf("Admin's Menu");
    gotoxy(45,14);
    printf("1. Senior Admin");
    gotoxy(45,16);
    printf("2. Junior Admin");
    gotoxy(45,18);
    printf("3. Exit");
    gotoxy(45,20);
    printf("0. Main Menu");
    fflush(stdin);
}
/* 3. This function display Senior Developer's Menu */
void displaySeniorDeveloperMenu()
{
    gotoxy(45,5);
    printf("W E L C O M E   A D M I N");
    gotoxy(47,7);
    printf("THEATRE MEMBER'S CLUB");
    gotoxy(47,11);
    printf("Senior Admin's Menu");
    gotoxy(47,14);
    printf("1. User's Watch List");
    gotoxy(47,16);
    printf("2. Add New Movie");
    gotoxy(47,18);
    printf("3. Delete Movie");
    gotoxy(47,20);
    printf("4. User's Record");
    gotoxy(47,22);
    printf("5. Exit");
    gotoxy(47,24);
    printf("0. Previous Menu");
    fflush(stdin);
}
/* 4. This function display Junior Developer's Menu */
void displayJuniorDeveloperMenu()
{
    gotoxy(45,5);
    printf("W E L C O M E   A D M I N");
    gotoxy(47,7);
    printf("THEATRE MEMBER'S CLUB");
    gotoxy(48,11);
    printf("Junior Admin's Menu");
    gotoxy(47,14);
    printf("1. Modify Movie");
    gotoxy(47,16);
    printf("2. See Movie List");
    gotoxy(47,18);
    printf("3. See User List");
    gotoxy(47,20);
    printf("4. See Review List");
    gotoxy(47,22);
    printf("5. See Booking List");
    gotoxy(47,24);
    printf("6. Exit");
    gotoxy(47,26);
    printf("0. Previous Menu");
    fflush(stdin);
}
/* 5. This Function display Registered User's Menu */
void displayUserMenu()
{
    gotoxy(45,5);
    printf("W E L C O M E   U S E R");
    gotoxy(46,7);
    printf("THEATRE MEMBER'S CLUB");
    gotoxy(50,9);
    printf("User's Menu");
    gotoxy(50,11);
    printf("1. Book Movie");
    gotoxy(50,13);
    printf("2. Search Movie");
    gotoxy(50,15);
    printf("3. Latest Offer");
    gotoxy(50,17);
    printf("4. Latest Movie");
    gotoxy(50,19);
    printf("5. Delete Record");
    gotoxy(50,21);
    printf("6. Modify Record");
    gotoxy(50,23);
    printf("7. Profile");
    gotoxy(50,25);
    printf("8. View Bookings");
    gotoxy(50,27);
    printf("9. Review Movie");
    gotoxy(50,29);
    printf("10. Exit");
    gotoxy(50,31);
    printf("0. Main Menu");
    fflush(stdin);
}
/* 6. Create New Account for unregistered User*/
void createNewAccount()
{
    FILE *registration;
    userSize = sizeof(user);
    registration = fopen("Login Record.txt", "a");
    fseek(registration,0,SEEK_END);
    printf("\n\t\t\t\t\tCreate New Account");
    printf("\nEnter User Name: ");
    scanf(" %[^\n]", &user.name.userName);
    printf("\nEnter Password: ");
    scanf(" %[^\n]", &user.password.userPassword);
    while(strlen(user.password.userPassword)<10){ //string work 01
        printf("\n\t\t\t\t\tGive Strong Password having 10 Characters! \n");
        printf("\t\t\t\t\tEnter Your Password: ");
        scanf(" %[^\n]", &user.password.userPassword);
    }
    printf("\nEnter Your First Name: ");
    scanf(" %[^\n]",user.name.firstName);
    printf("\nEnter Your Middle Name: ");
    scanf(" %[^\n]",user.name.middleName);
    printf("\nEnter Your Last Name: ");
    scanf(" %[^\n]",user.name.lastName);
    strcpy(user.name.userFullName, user.name.firstName);
    strcat(user.name.userFullName, " ");
    strcat(user.name.userFullName, user.name.middleName);
    strcat(user.name.userFullName, " ");
    strcat(user.name.userFullName, user.name.lastName);
    printf("\nYour Full Name: %s\n",user.name.userFullName);
    printf("\nEnter Your Address: ");
    scanf(" %[^\n]",&user.userAddress);
    printf("\nWrite About You: ");
    scanf(" %[^\n]",&user.userBio);
    printf("\nEnter Your Phone: ");
    scanf(" %[^\n]",&user.userContact);
    fwrite(&user, userSize, 1, registration);
    fclose(registration);
    fflush(stdin);
}
/* 7. Log in as Registered User */
void userLogIn()
{
    FILE *registration;
    int userOption=1;
    char press[2];
    registration = fopen("Login Record.txt", "r");
    rewind(registration);
    char userNameCheck[20], userPasswordCheck[15];
    printf("\t\t\t\t\tLog in to Your Account\n\n");
    printf("\t\t\t\t\tEnter Your Username: ");
    scanf(" %[^\n]",userNameCheck);
    printf("\t\t\t\t\tEnter Your Password: ");
    scanf(" %[^\n]",userPasswordCheck);
    while(fread(&user,userSize,1,registration)==1){
        if(strcmp(userNameCheck, user.name.userName)==0){
            if(strcmp(userPasswordCheck, user.password.userPassword)==0){
                printf("\t\t\t\t\tACCESS GRANTED!\n");
                while(userOption){
                    system("cls");
                    displayUserMenu();
                    printf("\n\n\n");
                    printf("\t\t\t\t\tChoose The Option Number: ");
                    scanf("%d",&userOption);
                    switch(userOption){
                        case 1:
                            system("cls");
                            bookMovie();
                            printf("\nPress anything and enter to continue: ");
                            scanf(" %[^\n]", &press);
                            break;
                        case 2:
                            system("cls");
                            searchMovie();
                            printf("\nPress anything and enter to continue: ");
                            scanf(" %[^\n]", &press);
                            break;
                        case 3:
                            system("cls");
                            discountOffer();
                            printf("\nPress anything and enter to continue: ");
                            scanf(" %[^\n]", &press);
                            break;
                        case 4:

                            displayLatestMovie();
                            printf("\nPress anything and enter to continue: ");
                            scanf(" %[^\n]", &press);
                            break;
                        case 5:
                            system("cls");
                            deleteUser();
                            printf("\nPress anything and enter to continue: ");
                            scanf(" %[^\n]", &press);
                            break;
                        case 6:
                            system("cls");
                            userModify();
                            printf("\nPress anything and enter to continue: ");
                            scanf(" %[^\n]", &press);
                            break;
                        case 7:
                            system("cls");
                            displayUserRecord();
                            showUserWatchlist();
                            showFeedBack();
                            printf("\nPress anything and enter to continue: ");
                            scanf(" %[^\n]", &press);
                            break;
                        case 8:
                            system("cls");
                            showUserWatchlist();
                            printf("\nPress anything and enter to continue: ");
                            scanf(" %[^\n]", &press);
                            break;
                        case 9:
                            system("cls");
                            giveFeedback();
                            printf("\nPress anything and enter to continue: ");
                            scanf(" %[^\n]", &press);
                            break;
                        case 10:
                            system("cls");
                            exitMessage();
                            exit(1);
                            break;
                    }
                }
            }
        }
    }
    fclose(registration);
    fflush(stdin);
}
/* 8. Developer's login*/
void developerLogIn()
{
    FILE *developerLog;
    developerLog = fopen("Developer Record.txt", "r+");
    fseek(developerLog,0,SEEK_END);
    printf("\n\t\t\t\t\tDeveloper Login");
    printf("\n\t\t\t\t\tEnter Your Name: ");
    scanf(" %[^\n]",&developer.name.userName);
    printf("\t\t\t\t\tEnter Your Password: ");
    scanf(" %[^\n]",&developer.password.userPassword);
    printf("\t\t\t\t\tACCESS GRANTED!\n");
    fwrite(&developer, developerSize, 1, developerLog);
    fclose(developerLog);
    fflush(stdin);
    printf("\n\n\n");
}
/* 9. This function add new movie */
void addNewMovie()
{
    FILE *movieDetails;
    char another;
    movieDetails = fopen("Movie Record.txt", "r+");
    if(movieDetails==NULL){
        movieDetails = fopen("Movie Record.txt", "wb+");
        if(movieDetails==NULL){
            printf("Cannot Open File.\n");
            exit(1);
        }
    }
    fseek(movieDetails,0,SEEK_END);
    printf("\n\t\t\t\t\tAdd New Movie");
    another = 'y';
    while(another=='y'){
        printf("\nEnter Movie Name: ");
        scanf(" %[^\n]", &movie.movieName);
        printf("Enter Average Rating: ");
        scanf("%f", &movie.averageRatings);
        printf("Enter Movie Details: ");
        scanf(" %[^\n]", &movie.movieDetails);
        printf("Enter The Date: ");
        scanf(" %[^\n]", &movie.movieDate);
        printf("Enter The Time: ");
        scanf(" %[^\n]", &movie.movieTime);
        printf("Enter The Price: ");
        scanf(" %d", &movie.moviePrice);
        fwrite(&movie, movieSize, 1, movieDetails);
        printf("\nAdd Another Movie(y/n) ");
        fflush(stdin);
        another = getche();
    }
    fclose(movieDetails);
    fflush(stdin);
    printf("\n\n\n");
}
/* 10. This function display latest movie*/
void displayLatestMovie()
{
    system("cls");
    FILE *movieDetails;
    movieDetails = fopen("Movie Record.txt", "r+");
    if(movieDetails==NULL){
        movieDetails = fopen("Movie Record.txt", "wb+");
        if(movieDetails==NULL){
            printf("Cannot Open File.\n");
            exit(1);
        }
    }
    rewind(movieDetails);

    printf("\n\t\t\t\t\tLatest Movies");
    while (fread(&movie, movieSize, 1, movieDetails)==1)
        printf("\nMovie Name: %s\nRatings: %.1f\nMovie Details: %s\nDate: %s\nTime: %s\nPrice: %d\n", movie.movieName, movie.averageRatings, movie.movieDetails, movie.movieDate, movie.movieTime, movie.moviePrice);
    fflush(stdin);
    fclose(movieDetails);
}
/* 11. This Function will modify the modify */
void modifyMovie()
{
    FILE *movieDetails;
    movieDetails = fopen("Movie Record.txt", "r+");
    if(movieDetails==NULL){
        movieDetails = fopen("Movie Record.txt", "wb+");
        if(movieDetails==NULL){
            printf("Cannot Open File.\n");
            exit(1);
        }
    }

    printf("\n\t\t\t\t\tModify Movie");
    char another = 'y', movieCheck[20];
    while(another=='y'){
        printf("\nEnter The Movie Name to Modify: ");
        scanf(" %[^\n]", &movieCheck);
        rewind(movieDetails);
        while (fread(&movie, movieSize, 1, movieDetails)==1){
            if(strcmp(movie.movieName, movieCheck)==0){
                printf("\nEnter Movie Name: ");
                scanf(" %[^\n]", &movie.movieName);
                printf("Enter Average Rating: ");
                scanf("%f", &movie.averageRatings);
                printf("Enter Movie Details: ");
                scanf(" %[^\n]", &movie.movieDetails);
                printf("Enter The Date: ");
                scanf(" %[^\n]", &movie.movieDate);
                printf("Enter The Time: ");
                scanf(" %[^\n]", &movie.movieTime);
                printf("Enter The Price: ");
                scanf(" %d", &movie.moviePrice);
                fseek(movieDetails,-movieSize,SEEK_CUR);
                fwrite(&movie, movieSize, 1, movieDetails);
                break;
            }
        }
        printf("\nModify another record(y/n)");
        fflush(stdin);
        another = getche();
    }
    fclose(movieDetails);
}
/* 12. This function does the search for movies */
void searchMovie()
{
    FILE *movieDetails;
    movieDetails = fopen("Movie Record.txt", "r+");
    if(movieDetails==NULL){
        movieDetails = fopen("Movie Record.txt", "wb+");
        if(movieDetails==NULL){
            printf("Cannot Open File.\n");
            exit(1);
        }
    }

    printf("\n\t\t\t\t\tSearch Movie");
    char another = 'y', movieCheck[20];
    while(another=='y'){
        printf("\nEnter The Movie Name to Search: ");
        scanf(" %[^\n]", &movieCheck);
        rewind(movieDetails);
        while (fread(&movie, movieSize, 1, movieDetails)==1){
            if(strcmp(movie.movieName, movieCheck)==0){
                printf("\nMovie Name: %s\nRatings: %.1f\nMovie Details: %s\nDate: %s\nTime: %s\nPrice: %d\n", movie.movieName, movie.averageRatings, movie.movieDetails, movie.movieDate, movie.movieTime, movie.moviePrice);
                break;
            }
        }
        printf("\nSearch another Movie(y/n)");
        fflush(stdin);
        another = getche();
    }
    fclose(movieDetails);
}
/* 13. This function does the delete movie */
void deleteMovie()
{
    FILE *movieDetails, *tempMovie;
    movieDetails = fopen("Movie Record.txt", "r+");
    if(movieDetails==NULL){
        movieDetails = fopen("Movie Record.txt", "wb+");
        if(movieDetails==NULL){
            printf("Cannot Open File.\n");
            exit(1);
        }
    }

    printf("\n\t\t\t\t\tDelete Movie");
    char another = 'y', movieCheck[20];;
    while(another=='y'){
        printf("\nEnter Movie Name to delete: ");
        scanf(" %[^\n]", &movieCheck);
        tempMovie = fopen("Temp Movie.txt", "w");
        rewind(movieDetails);
        while (fread(&movie, movieSize, 1, movieDetails)==1){
            if(strcmp(movie.movieName, movieCheck)!=0){
                fwrite(&movie, movieSize, 1, tempMovie);
            }
        }
        fclose(movieDetails);
        fclose(tempMovie);
        remove("Movie Record.txt");
        rename("Temp Movie.txt","Movie Record.txt");
        movieDetails = fopen("Movie Record.txt", "r+");
        printf("Delete another movie(y/n)");
        fflush(stdin);
        another = getche();
    }
    fclose(movieDetails);
}
/* 14. This Function does the Modify user record */
void userModify()
{
    FILE *registration;
    registration = fopen("Login Record.txt", "r+");
    if(registration==NULL){
        registration = fopen("Login Record.txt", "wb+");
        if(registration==NULL){
            printf("Cannot Open File.\n");
            exit(1);
        }
    }

    printf("\n\t\t\t\t\tModify User");
    char another = 'y', userCheck[20];
    while(another=='y'){
        printf("\nEnter The User Name to Modify: ");
        scanf(" %[^\n]", &userCheck);
        rewind(registration);
        while (fread(&user, userSize, 1, registration)==1){
            if(strcmp(user.name.userName, userCheck)==0){
                printf("\nEnter User Name: ");
                scanf(" %[^\n]", &user.name.userName);
                printf("\nEnter Password: ");
                scanf(" %[^\n]", &user.password.userPassword);
                while(strlen(user.password.userPassword)<10){ //string work 01
                    printf("\n\t\t\t\t\tGive Strong Password having 10 Characters! \n");
                    printf("\t\t\t\t\tEnter Your Password: ");
                    scanf(" %[^\n]", &user.password.userPassword);
                }
                printf("\nEnter Your First Name: ");
                scanf(" %[^\n]",user.name.firstName);
                printf("\nEnter Your Middle Name: ");
                scanf(" %[^\n]",user.name.middleName);
                printf("\nEnter Your Last Name: ");
                scanf(" %[^\n]",user.name.lastName);
                strcpy(user.name.userFullName, user.name.firstName);
                strcat(user.name.userFullName, " ");
                strcat(user.name.userFullName, user.name.middleName);
                strcat(user.name.userFullName, " ");
                strcat(user.name.userFullName, user.name.lastName);
                printf("\nYour Full Name: %s\n",user.name.userFullName);
                printf("\nEnter Your Address: ");
                scanf(" %[^\n]",&user.userAddress);
                printf("\nWrite About You: ");
                scanf(" %[^\n]",&user.userBio);
                printf("\nEnter Your Phone: ");
                scanf(" %[^\n]",&user.userContact);
                fseek(registration,-userSize,SEEK_CUR);
                fwrite(&user, userSize, 1, registration);
                break;
            }
        }
        printf("\nModify Again?(y/n): ");
        fflush(stdin);
        another = getche();
    }
    fclose(registration);
}
/* 10. This function display latest movie*/
void displayUserRecord()
{
    FILE *registration;
    char userCheck[20];
    registration = fopen("Login Record.txt", "r+");
    if(registration==NULL){
        registration = fopen("Login Record.txt", "wb+");
        if(registration==NULL){
            printf("Cannot Open File.\n");
            exit(1);
        }
    }
    rewind(registration);

    printf("\n\t\t\t\t\tUser's Personal Information");
    printf("\nEnter Username To see Record: ");
    scanf(" %[^\n]",&userCheck);
    while (fread(&user, userSize, 1, registration)==1){
        if(strcmp(user.name.userName, userCheck)==0){
        printf("User Full Name: %s\nUsername: %s\nAddress: %s\nContact: %s\nEmail: %s\nBio: %s\n",user.name.userFullName,user.name.userName,user.userAddress,user.userContact,user.userEmail,user.userBio);
        }
    }
    fflush(stdin);
    fclose(registration);
}
void deleteUser()
{
    FILE *registration, *tempUser;
    registration = fopen("Login Record.txt", "r+");
    if(registration==NULL){
        registration = fopen("Login Record.txt", "wb+");
        if(registration==NULL){
            printf("Cannot Open File.\n");
            exit(1);
        }
    }

    printf("\n\t\t\t\t\tDelete User Record");
    char another = 'y', userCheck[20];;
    while(another=='y'){
        printf("\nEnter User Name to delete: ");
        scanf(" %[^\n]", &userCheck);
        tempUser = fopen("Temp User.txt", "w");
        rewind(registration);
        while (fread(&user, userSize, 1, registration)==1){
            if(strcmp(user.name.userName, userCheck)!=0){
                fwrite(&user, userSize, 1, tempUser);
            }
        }
        fclose(registration);
        fclose(tempUser);
        remove("Login Record.txt");
        rename("Temp User.txt","Login Record.txt");
        registration = fopen("Login Record.txt", "r+");
        fflush(stdin);
        fclose(registration);
        exit(1);
    }

}
void displayUserList()
{
    FILE *registration;
    registration = fopen("Login Record.txt", "r+");
    if(registration==NULL){
        registration = fopen("Login Record.txt", "wb+");
        if(registration==NULL){
            printf("Cannot Open File.\n");
            exit(1);
        }
    }
    rewind(registration);

    printf("\n\t\t\t\t\tUser List");
    while (fread(&user, userSize, 1, registration)==1){
        printf("\nUser Full Name: %s\nUsername: %s\nAddress: %s\nContact: %s\nEmail: %s\nBio: %s\n",user.name.userFullName,user.name.userName,user.userAddress,user.userContact,user.userEmail,user.userBio);
    }
    fflush(stdin);
    fclose(registration);
}
/* 4. This function counts the discount offer for the customer*/
int discountOffer()
{

    printf("\n\t\t\t\t\tDiscount Offer");
    int bookedMovies;

    printf("\n\t\t\t\t\tEnter the number of movies you have booked: ");
    scanf("%d",&bookedMovies);
    if(bookedMovies>=5){
        registeredUser.discount = 20;
    }
    else if(bookedMovies==0){
        registeredUser.discount = 25;
    }
    else{
        registeredUser.discount = 10;
    }
    printf("\t\t\t\t\tYou got %d%% discount!\n",registeredUser.discount);
    return registeredUser.discount;
    printf("\n\n\n");

}
/* 8. This function does the calculation of booking price with discount of the movie*/
float calculatePrice(int price,int movieDiscount, int totalSeat)
{
    float totalPrice;
    totalPrice = (price-(price*(movieDiscount/100.00)))*totalSeat;
    return totalPrice;
}
/* 9. This function shows the details calculation of price of the movie*/
void bookMovie()
{
    FILE *movieDetails, *activityDetails;
    movieDetails = fopen("Movie Record.txt", "r+");
    activityDetails = fopen("Activity Record.txt", "a");
    if(movieDetails==NULL){
        movieDetails = fopen("Movie Record.txt", "wb+");
        if(movieDetails==NULL){
            printf("Cannot Open File.\n");
            exit(1);
        }
    }
    if(activityDetails==NULL){
        activityDetails = fopen("Activity Record.txt", "wb+");
        if(activityDetails==NULL){
            printf("Cannot Open File.\n");
            exit(1);
        }
    }

    printf("\n\t\t\t\t\tBook Movie");
    char another = 'y', movieCheck[20];
    fseek(activityDetails,0,SEEK_END);
    while(another=='y'){
        printf("\nEnter The Movie Name to Book: ");
        scanf(" %[^\n]", &movieCheck);
        rewind(movieDetails);
        while(fread(&movie, movieSize, 1, movieDetails)==1){
            if(strcmp(movie.movieName, movieCheck)==0){
                printf("Please Enter your username again: ");
                scanf(" %[^\n]", &registeredUser.activeUser);
                printf("Enter Number of Seats To Book: ");
                scanf("%d", &registeredUser.totalSeat);
                printf("Enter the movie name again to Confirm: ");
                scanf(" %[^\n]", &registeredUser.movieBooked);
                system("cls");
                discountOffer();
                registeredUser.totalMoviePrice = calculatePrice(movie.moviePrice, registeredUser.discount, registeredUser.totalSeat);
                fwrite(&registeredUser, activitySize, 1, activityDetails);
                printf("\n\t\t\t\t\tTicket\n");
                printf("Username: %s\nTotal Seats: %d\nMovie Name: %s\nMovie Price: %d BDT\nDiscount: %d%%\n---------------------\nTotal Price: %.2f BDT\n\nHAPPY WATCHING\n", registeredUser.activeUser, registeredUser.totalSeat, registeredUser.movieBooked, movie.moviePrice, registeredUser.discount, registeredUser.totalMoviePrice);
            }
        }
        printf("\nBook another Movie(y/n)");
        fflush(stdin);
        another = getche();
    }
    fclose(movieDetails);
    fclose(activityDetails);
}
void exitMessage()
{
    printf("\n%s\n",message);
    printf("\n%s\n",location);
}
void showUserWatchlist()
{
    FILE *activityDetails;
    activityDetails = fopen("Activity Record.txt", "r+");
    if(activityDetails==NULL){
        activityDetails = fopen("Activity Record.txt", "wb+");
        if(activityDetails==NULL){
            printf("Cannot Open File.\n");
            exit(1);
        }
    }

    printf("\n\t\t\t\t\tWatch List");
    char another = 'y', userCheck[20];
    rewind(activityDetails);
    while(another=='y'){
        printf("\nEnter The UserName to see Watchlist: ");
        scanf(" %[^\n]", &userCheck);
        printf("%s 's Watchlist: \n", userCheck);
        while(fread(&registeredUser, activitySize, 1, activityDetails)==1){
            if(strcmp(registeredUser.activeUser, userCheck)==0){
                printf("%s\n", registeredUser.movieBooked);
            }
        }
        printf("\nSee Another watchlist? (y/n)");
        fflush(stdin);
        another = getche();
    }
    fclose(activityDetails);
}
void displayBookibgList()
{
    FILE *activityDetails;
    activityDetails = fopen("Activity Record.txt", "r+");
    if(activityDetails==NULL){
        activityDetails = fopen("Activity Record.txt", "wb+");
        if(activityDetails==NULL){
            printf("Cannot Open File.\n");
            exit(1);
        }
    }
    rewind(activityDetails);

    printf("\n\t\t\t\t\tBooking List");
    while (fread(&registeredUser, activitySize, 1, activityDetails)==1){
        printf("\nUsername: %s\nMovie Name: %s\nDiscount: %d\nTotal Seat: %d\nTotal Price: %.2f BDT\n", registeredUser.activeUser, registeredUser.movieBooked, registeredUser.discount, registeredUser.totalSeat, registeredUser.totalMoviePrice);
    }
    fflush(stdin);
    fclose(activityDetails);
}
void giveFeedback()
{
    FILE *feed;
    feed = fopen("FeedBack Record.txt", "a");
    if(feed==NULL){
        printf("Cannot Open File\n");
        exit(1);
    }

    printf("\n\t\t\t\t\tFeedBack");
    fseek(feed,0,SEEK_END);
    printf("\nEnter Your Name: ");
    scanf(" %[^\n]", &movieFeedback.person);
    printf("Enter Movie Name: ");
    scanf(" %[^\n]", movieFeedback.watchedMovie);
    printf("Rate out of 10: ");
    scanf("%f", &movieFeedback.rating);
    printf("Please Give Us Your Valuable Feedback: ");
    scanf(" %[^\n]", &movieFeedback.review);
    fwrite(&movieFeedback, feedbackSize, 1, feed);
    fflush(stdin);
    fclose(feed);

}
void showFeedBack()
{
    FILE *feed;
    char userCheck[20];
    feed = fopen("FeedBack Record.txt", "r+");
    if(feed==NULL){
        printf("Cannot Open File\n");
        exit(1);
    }

    printf("\n\t\t\t\t\tSee FeedBack");
    rewind(feed);
    printf("\nEnter Your Username to see feedBacks: ");
    scanf(" %[^\n]", &userCheck);
    while(fread(&movieFeedback, feedbackSize, 1, feed)==1){
        if(strcmp(movieFeedback.person, userCheck)==0){
            printf("Movie Name: %s\nRating: %.2f\nReview: %s\n\n", movieFeedback.watchedMovie, movieFeedback.rating, movieFeedback.review);
        }
    }
    fflush(stdin);
    fclose(feed);
}
void displayFeedbackList()
{
    FILE *feed;
    feed = fopen("FeedBack Record.txt", "r+");
    if(feed==NULL){
        feed = fopen("FeedBack Record.txt", "wb+");
        if(feed==NULL){
            printf("Cannot Open File.\n");
            exit(1);
        }
    }
    rewind(feed);

    printf("\n\t\t\t\t\tFeedBack List");
    while (fread(&movieFeedback, feedbackSize, 1, feed)==1){
        printf("\nUsername: %s\nMovie Name: %s\nRating: %.2f\nReview: %s\n", movieFeedback.person, movieFeedback.watchedMovie, movieFeedback.rating, movieFeedback.review);
    }
    fflush(stdin);
    fclose(feed);
}
void processOptions()
{
    char press[2];
    int optionNumber=1, adminOption=1, juniorOption=1, seniorOption=1;//constant
    while(optionNumber){
        system("cls");
        displayMainMenu();
        printf("\n\t\t\t\t\tChoose the option number: ");
        scanf("%d", &optionNumber);
        switch(optionNumber){
            case 1:
                system("cls");
                createNewAccount();
                printf("\t\t\tCongratulations! Now you are a new member. For booking and offers please login.\n\n");
                printf("\nPress anything and enter to continue: ");
                scanf(" %[^\n]", &press);
                break;

            case 2:
                system("cls");
                while(adminOption){
                    system("cls");
                    displayAdminMenu();
                    printf("\n\n\n");
                    printf("\t\t\t\t\tChoose The designation number: ");
                    scanf("%d",&adminOption);
                    printf("\n\t\t\t\t\tPlease Log in to Continue\n\n");
                    developerLogIn();
                    switch(adminOption){
                        case 1:
                            system("cls");
                            while(seniorOption){
                                system("cls");
                                displaySeniorDeveloperMenu();
                                printf("\n\n\n");
                                printf("\t\t\t\t\tChoose The Option number: ");
                                scanf("%d",&seniorOption);
                                switch(seniorOption)
                                {
                                    case 1:
                                        system("cls");
                                        showUserWatchlist();
                                        printf("\nPress anything and enter to continue: ");
                                        scanf(" %[^\n]", &press);
                                        break;
                                    case 2:
                                        system("cls");
                                        addNewMovie();
                                        printf("\nPress anything and enter to continue: ");
                                        scanf(" %[^\n]", &press);
                                        break;
                                    case 3:
                                        system("cls");
                                        deleteMovie();
                                        printf("\nPress anything and enter to continue: ");
                                        scanf(" %[^\n]", &press);
                                        break;
                                    case 4:
                                        system("cls");
                                        displayUserRecord();
                                        showUserWatchlist();
                                        showFeedBack();
                                        printf("\nPress anything and enter to continue: ");
                                        scanf(" %[^\n]", &press);
                                        break;
                                    case 5:
                                        system("cls");
                                        exitMessage();
                                        exit(1);
                                        break;
                                }
                            }
                            break;
                        case 2:
                            system("cls");
                            while(juniorOption){
                                system("cls");
                                displayJuniorDeveloperMenu();
                                printf("\n\n\n");
                                printf("\t\t\t\t\tChoose The Option number: ");
                                scanf("%d",&juniorOption);
                                switch(juniorOption){
                                    case 1:
                                        system("cls");
                                        modifyMovie();
                                        printf("\nPress anything and enter to continue: ");
                                        scanf(" %[^\n]", &press);
                                        break;
                                    case 2:
                                        system("cls");
                                        displayLatestMovie();
                                        printf("\nPress anything and enter to continue: ");
                                        scanf(" %[^\n]", &press);
                                        break;
                                    case 3:
                                        system("cls");
                                        displayUserList();
                                        printf("\nPress anything and enter to continue: ");
                                        scanf(" %[^\n]", &press);
                                        break;
                                    case 4:
                                        system("cls");
                                        displayFeedbackList();
                                        printf("\nPress anything and enter to continue: ");
                                        scanf(" %[^\n]", &press);
                                        break;

                                    case 5:
                                        system("cls");
                                        displayBookibgList();
                                        printf("\nPress anything and enter to continue: ");
                                        scanf(" %[^\n]", &press);
                                        break;
                                    case 6:
                                        system("cls");
                                        exitMessage();
                                        exit(1);
                                }
                            }
                            break;
                        case 3:
                            system("cls");
                            exitMessage();
                            exit(0);
                            break;

                    }
                }
                break;
            case 3:
                system("cls");
                userLogIn();
                printf("\nPress anything and enter to continue: ");
                scanf(" %[^\n]", &press);
                break;
            case 4:
                system("cls");
                exitMessage();
                exit(1);
                break;

        }
    }
}
int main()
{
    processOptions();
    return 0;
}
