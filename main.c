#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct person {
    char name[100];
    int age;
    int phone;
    int pass;
} s;

void displaySplashScreen() {
    FILE* splashFile = fopen("splash.txt", "a");
    if (splashFile == NULL) {
        printf("Failed to open splash file.\n");
        return;
    }

    char c;
    while ((c = fgetc(splashFile)) != EOF) {
        putchar(c);
    }

    fclose(splashFile);
    sleep(5);
    system("clear");
}

void trainerInfo() {
    printf("Name: Sanzid Rahman\n");
    printf("Age: 32\n");
    printf("Experience: 2 time Mr. Bangladesh and experience as a professional trainer.\n");
    printf("Gender: male\n");
    printf("Phone: 01304399773\n");
    printf("Mail: sanzidrahman@gmail.com\n");
    printf("\n");
}

void paymentMethod(int choice) {
    printf("1. bkash\n");
    printf("2. nagad\n");
    printf("Enter a choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Successfully paid through bkash.\n");
            break;
        case 2:
            printf("Successfully paid through nagad.\n");
            break;
        default:
            printf("Invalid option.\n");
            break;
    }
}

void sign() {
    printf("To get free membership, enter your information:\n");
    printf("Enter your name: ");
    getchar();
    fgets(s.name, sizeof(s.name), stdin);
    printf("Enter your age: ");
    scanf("%d", &s.age);
    printf("Enter a phone number: ");
    scanf("%d", &s.phone);
    printf("Enter a password: ");
    scanf("%d", &s.pass);
    printf("\nYou are now our gym member.\n");
}

void login() {
    int password;
    int choice;
    printf("Enter a password: ");
    scanf("%d", &password);
    if (s.pass == password) {
        printf("Name: %s\n", s.name);
        printf("Phone: %d\n", s.phone);
        printf("Welcome to our gym page.\n");
        printf("Menu:\n");
        printf("1. See trainer info\n");
        printf("2. Pay for next month\n");
        printf("3. Buy supplements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (choice != 4) {
            switch (choice) {
                case 1:
                    trainerInfo();
                    break;
                case 2:
                    pay();
                    break;
                case 3:
                    supplements();
                    break;
                default:
                    printf("Invalid option.\n");
                    break;
            }
            printf("Menu:\n");
            printf("1. See trainer info\n");
            printf("2. Pay for next month\n");
            printf("3. Buy supplements\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
        }
        printf("Exiting the program!\n");
    } else {
        printf("Invalid password.\n");
    }
}

void pay() {
    int choice;
    printf("Get package:\n");
    printf("1. 1 month - 1200 TK\n");
    printf("2. 3 months - 3500 TK\n");
    printf("3. 6 months - 6600 TK\n");
    printf("4. 12 months - 12000 TK\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    switch (choice) {
        case 1:
            paymentMethod(choice);
            printf("Successfully paid for 1 month.\n");
            break;
        case 2:
            paymentMethod(choice);
            printf("Successfully paid for 3 months.\n");
            break;
        case 3:
            paymentMethod(choice);
            printf("Successfully paid for 6 months.\n");
            break;
        case 4:
            paymentMethod(choice);
            printf("Successfully paid for 12 months.\n");
            break;
        default:
            printf("Invalid option.\n");
            break;
    }
}

void supplements() {
    printf("Select a supplement that you want to buy:\n");
    printf("1. Fat burner\n");
    printf("2. Chocolate bar\n");
    printf("3. Whey protein supplement\n");
    printf("4. BCAA\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            paymentMethod(choice);
            break;
        case 2:
            paymentMethod(choice);
            break;
        case 3:
            paymentMethod(choice);
            break;
        case 4:
            paymentMethod(choice);
            break;
        default:
            printf("Invalid option.\n");
            break;
    }
}

int main() {
    displaySplashScreen();
    int choice;
    do {
        printf("Menu:\n");
        printf("1. Sign up\n");
        printf("2. Log in\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                sign();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("Exiting the program!\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
