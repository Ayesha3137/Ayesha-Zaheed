#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int MAX_SPACES = 10;
const int RATE_PER_HOUR = 5;

// ParkingSpace struct definition
struct ParkingSpace {
    int spaceID;
    string status;
    string vehicleNumber;
    int duration;
    string userName; // Store the username who reserved the space
    bool isPaid;     // Track if the payment is completed
};

// User struct definition
struct User {
    string username;
    string password;
};

// Function prototypes
void displayMenu();
void checkAvailability(ParkingSpace spaces[]);
void reserveSpace(ParkingSpace spaces[], string currentUser);
void makePayment(ParkingSpace spaces[], int index);
void searchSpaces(ParkingSpace spaces[]);
void freeSpace(ParkingSpace spaces[]);
void loadParkingData(ParkingSpace spaces[]);
void saveParkingData(ParkingSpace spaces[]);
void displayHelp();
void viewReservations(ParkingSpace spaces[]);
void login(User &currentUser); // Pass currentUser by reference
void registration();
void forgot();
void help();

// Main function
int main() {
    ParkingSpace parkingSpaces[MAX_SPACES];
    User currentUser;

    // Load parking data from file
    loadParkingData(parkingSpaces);

    // Initial login/signup menu
    int choice;
    while (true) {
        // Display the main menu
        cout << " -------------------------------------------------------------" << endl;
        cout << "         WELCOME TO CAR PARKING SYSTEM AT THE AIRPORT        " << endl;
        cout << " -------------------------   MENU   --------------------------" << endl;
        cout << "" << endl;
        cout << " |       PRESS 1 TO REGISTER           |   " << endl;
        cout << " |       PRESS 2 TO LOGIN              |   " << endl;
        cout << " |       PRESS 3 TO FORGOT PASSWORD    |   " << endl;
        cout << " |       PRESS 4 FOR HELP              |   " << endl;
        cout << " |       PRESS 5 TO EXIT               |   " << endl;
        cout << " Please enter your choice: ";
        cin >> choice;

        // Handle invalid input
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(10000, '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
            continue;
        }

        cout << endl;

        // Execute the appropriate function based on user choice
        switch (choice) {
            case 1:
                registration();
                break;
            case 2:
                login(currentUser); // Pass currentUser to the login function
                if (!currentUser.username.empty()) {
                    // If login is successful, break out of the loop and proceed to the parking system menu
                    break;
                }
                continue; // If login fails, stay in the login/registration menu
            case 3:
                forgot();
                break;
            case 4:
                help();
                break;
            case 5:
                cout << "Exiting the system. Thank you!" << endl;
                return 0; // Exit the program
            default:
                cout << "Invalid entry. Please try again." << endl;
                continue;
        }

        // If login is successful, proceed to the parking system menu
        if (!currentUser.username.empty()) {
            break;
        }
    }

    // Main system loop
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkAvailability(parkingSpaces);
                break;
            case 2:
                reserveSpace(parkingSpaces, currentUser.username);
                break;
            case 3:
                searchSpaces(parkingSpaces);
                break;
            case 4:
                makePayment(parkingSpaces, -1);
                break;
            case 5:
                freeSpace(parkingSpaces);
                break;
            case 6:
                viewReservations(parkingSpaces);
                break;
            case 7:
                displayHelp();
                break;
            case 8:
                cout << "Signing out: " << currentUser.username << endl;
                currentUser.username = "";
                currentUser.password = "";
                cout << "You have been signed out. Returning to the login/signup menu." << endl;
                break;
            case 9:
                // Save data before exiting
                saveParkingData(parkingSpaces);
                cout << "Exiting the system. Data saved successfully." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        // After signout, return to the login/registration menu
        if (currentUser.username.empty()) {
            continue;
        }
    }

    return 0;
}

// Function to handle user login
void login(User &currentUser) {
    int count = 0;
    string userID, password, id, pass;
    cout << " =================================================================== " << endl;
    cout << "                            LOGIN                               " << endl;
    cout << " =================================================================== " << endl;
    cout << " Please enter the username and password " << endl;
    cout << " USERNAME: ";
    cin >> userID;
    cout << " PASSWORD: ";
    cin >> password;

    // Open the records file
    ifstream input("records.txt");

    // Handle file opening error
    if (!input) {
        cout << "Error opening file. Please ensure the records file exists." << endl;
        return;
    }

    // Check if the entered credentials match any record in the file
    while (input >> id >> pass) {
        if (id == userID && pass == password) {
            count = 1;
            break;
        }
    }
    input.close();

    // Display login result
    if (count == 1) {
        cout << "  | " << userID << " | Your LOGIN is successful | Thanks for logging in! " << endl;
        currentUser.username = userID;
        currentUser.password = password;
    } else {
        cout << "  | LOGIN ERROR  | Please check your username and password " << endl;
    }
}

// Function to handle user registration
void registration() {
    string RuserID, Rpassword, proceed;
    cout << " =================================================================== " << endl;
    cout << "                             REGISTRATION                              " << endl;
    cout << " =================================================================== " << endl;
    cout << " Continue? [y/n]: ";
    cin >> proceed;

    // Check if user wants to proceed with registration
    if (proceed != "y") {
        cout << "Registration aborted." << endl;
        return;
    }

    cout << " ENTER THE USERNAME: ";
    cin >> RuserID;

    cout << " ENTER THE PASSWORD: ";
    cin >> Rpassword;

    // Open the records file in append mode
    ofstream f1("records.txt", ios::app);

    // Handle file opening error
    if (!f1) {
        cout << "Error opening file for writing. Please try again." << endl;
        return;
    }

    // Write the new user credentials to the file
    f1 << RuserID << " " << Rpassword << endl;
    f1.close();

    cout << " =================================================================== " << endl;
    cout << "                         REGISTRATION IS SUCCESSFUL!                          " << endl;
    cout << " =================================================================== " << endl;
}

// Function to handle password recovery
void forgot() {
    int option;
    cout << " =================================================================== " << endl;
    cout << "                             FORGOT PASSWORD                            " << endl;
    cout << " =================================================================== " << endl;
    cout << " | You forgot the password?           | " << endl;
    cout << " |   PRESS 1 TO SEARCH YOUR ID BY USERNAME    | " << endl;
    cout << " |   PRESS 2 TO GO BACK TO MAIN MENU     | " << endl;
    cout << " |   ENTER YOUR CHOICE:   | ";
    cin >> option;

    // Handle invalid input
    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(10000, '\n'); // Ignore invalid input
        cout << "Invalid input. Please enter a number between 1 and 2.\n";
        return;
    }

    switch (option) {
        case 1: {
            int count = 0;
            string FuserID, Fid, Fpass;
            cout << " Enter the username which you remember: ";
            cin >> FuserID;

            // Open the records file
            ifstream f2("records.txt");

            // Handle file opening error
            if (!f2) {
                cout << "Error opening file. Please ensure the records file exists." << endl;
                return;
            }

            // Search for the username in the file
            while (f2 >> Fid >> Fpass) {
                if (Fid == FuserID) {
                    count = 1;
                    break;
                }
            }
            f2.close();

            // Display the result of the search
            if (count == 1) {
                cout << " =================================================================== " << endl;
                cout << " | Your account ID found! " << endl;
                cout << " | Your password is: " << Fpass << endl;
                cout << " =================================================================== " << endl;
            } else {
                cout << " =================================================================== " << endl;
                cout << "                           Sorry! Your account not found!                            " << endl;
                cout << " =================================================================== " << endl;
            }
            break;
        }
        case 2:
            break;
        default:
            cout << " Wrong choice! Please try again." << endl;
            forgot(); // Recursive call to retry password recovery
            break;
    }
}

// Function to provide user help and guidance
void help() {
    cout << " =================================================================== " << endl;
    cout << "                             HELP SECTION                            " << endl;
    cout << " =================================================================== " << endl;
    cout << " | 1. LOGIN: Enter your username and password to log in.            | " << endl;
    cout << " | 2. REGISTER: Create a new account by entering a username and password. | " << endl;
    cout << " | 3. FORGOT PASSWORD: Recover your password by entering your username.  | " << endl;
    cout << " | 4. EXIT: Exit the application.                                   | " << endl;
    cout << " =================================================================== " << endl;
}

// Parking System Module
void displayMenu() {
    cout << endl << "----- Airport Car Parking System -----" << endl;
    cout << "1. Check Availability" << endl;
    cout << "2. Reserve Space" << endl;
    cout << "3. Search for Space" << endl;
    cout << "4. Make Payment" << endl;
    cout << "5. Free Space" << endl;
    cout << "6. View Reservations" << endl;
    cout << "7. Help" << endl;
    cout << "8. Sign Out" << endl;
    cout << "9. Exit" << endl;
}

void checkAvailability(ParkingSpace spaces[]) {
    cout << endl << "Available Parking Spaces:" << endl;
    bool available = false;
    for (int i = 0; i < MAX_SPACES; i++) {
        if (spaces[i].status == "available") {
            cout << "Space ID: " << spaces[i].spaceID << endl;
            available = true;
        }
    }
    if (!available) {
        cout << "No spaces are available at the moment." << endl;
    }
}

void reserveSpace(ParkingSpace spaces[], string currentUser) {
    int spaceID;
    cout << endl << "Enter the Space ID you want to reserve: ";
    cin >> spaceID;

    // Validate space ID
    if (spaceID < 1 || spaceID > MAX_SPACES) {
        cout << "Invalid Space ID. Please try again." << endl;
        return;
    }

    // Find the space with the given ID
    for (int i = 0; i < MAX_SPACES; i++) {
        if (spaces[i].spaceID == spaceID) {
            if (spaces[i].status == "available") {
                cout << "Enter your vehicle number: ";
                cin >> spaces[i].vehicleNumber;
                cout << "Enter the duration (in hours): ";
                cin >> spaces[i].duration;
                spaces[i].status = "occupied";
                spaces[i].userName = currentUser; // Save the username
                spaces[i].isPaid = false;         // Payment status initially false
                cout << "Space reserved successfully!" << endl;

                makePayment(spaces, i);
                saveParkingData(spaces); // Save data after reservation
                return;
            } else {
                cout << "Space is already occupied." << endl;
                return;
            }
        }
    }
    cout << "Invalid Space ID. Please try again." << endl;
}

void makePayment(ParkingSpace spaces[], int index) {
    if (index == -1) {
        cout << "Enter the Space ID you want to make payment for: ";
        int spaceID;
        cin >> spaceID;

        // Validate space ID
        if (spaceID < 1 || spaceID > MAX_SPACES) {
            cout << "Invalid Space ID. Please try again." << endl;
            return;
        }

        // Find the space with the given ID
        for (int i = 0; i < MAX_SPACES; i++) {
            if (spaces[i].spaceID == spaceID) {
                if (spaces[i].status == "occupied") {
                    int totalCost = spaces[i].duration * RATE_PER_HOUR;
                    cout << endl << "Total cost: $" << totalCost << endl;
                    cout << "Confirm payment (Y/N): ";
                    char confirmation;
                    cin >> confirmation;

                    if (confirmation == 'Y' || confirmation == 'y') {
                        cout << "Payment successful. Reservation confirmed." << endl;
                        spaces[i].isPaid = true; // Mark payment as completed
                        saveParkingData(spaces); // Save data after payment
                    } else {
                        cout << "Payment failed. Reservation canceled." << endl;
                        // Revert reservation changes
                        spaces[i].status = "available";
                        spaces[i].vehicleNumber = "";
                        spaces[i].duration = 0;
                        spaces[i].userName = "";
                        spaces[i].isPaid = false;
                        saveParkingData(spaces); // Save data after cancellation
                    }
                    return;
                } else {
                    cout << "Space is not reserved." << endl;
                    return;
                }
            }
        }
        cout << "Invalid Space ID. Please try again." << endl;
        return;
    }

    // Payment logic for reservation
    int totalCost = spaces[index].duration * RATE_PER_HOUR;
    cout << endl << "Total cost: $" << totalCost << endl;
    cout << "Confirm payment (Y/N): ";
    char confirmation;
    cin >> confirmation;

    if (confirmation == 'Y' || confirmation == 'y') {
        cout << "Payment successful. Reservation confirmed." << endl;
        spaces[index].isPaid = true; // Mark payment as completed
        saveParkingData(spaces); // Save data after payment
    } else {
        cout << "Payment failed. Reservation canceled." << endl;
        // Revert reservation changes
        spaces[index].status = "available";
        spaces[index].vehicleNumber = "";
        spaces[index].duration = 0;
        spaces[index].userName = "";
        spaces[index].isPaid = false;
        saveParkingData(spaces); // Save data after cancellation
    }
}

void freeSpace(ParkingSpace spaces[]) {
    int spaceID;
    cout << endl << "Enter the Space ID you want to free: ";
    cin >> spaceID;

    // Validate space ID
    if (spaceID < 1 || spaceID > MAX_SPACES) {
        cout << "Invalid Space ID. Please try again." << endl;
        return;
    }

    for (int i = 0; i < MAX_SPACES; i++) {
        if (spaces[i].spaceID == spaceID) {
            if (spaces[i].status == "occupied") {
                spaces[i].status = "available";
                spaces[i].vehicleNumber = "";
                spaces[i].duration = 0;
                spaces[i].userName = "";
                spaces[i].isPaid = false;
                cout << "Space freed successfully." << endl;
                saveParkingData(spaces); // Save data after freeing space
                return;
            } else {
                cout << "Space is already available." << endl;
                return;
            }
        }
    }
    cout << "Invalid Space ID. Please try again." << endl;
}

void loadParkingData(ParkingSpace spaces[]) {
    ifstream infile("parking_data.txt");
    if (!infile) {
        // Initialize parking spaces with default values
        for (int i = 0; i < MAX_SPACES; i++) {
            spaces[i].spaceID = i + 1;
            spaces[i].status = "available";
            spaces[i].vehicleNumber = "";
            spaces[i].duration = 0;
            spaces[i].userName = "";
            spaces[i].isPaid = false;
        }
        cout << "No saved parking data found. Initializing new data." << endl;
        return;
    }

    string line;
    int i = 0;
    while (getline(infile, line) && i < MAX_SPACES) {
        stringstream ss(line);
        ss >> spaces[i].spaceID >> spaces[i].status >> spaces[i].vehicleNumber >> spaces[i].duration >> spaces[i].userName >> spaces[i].isPaid;
        i++;
    }
    infile.close();
    cout << "Parking data loaded successfully." << endl;
}

void saveParkingData(ParkingSpace spaces[]) {
    ofstream outfile("parking_data.txt");
    if (!outfile) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    // Write data to file
    for (int i = 0; i < MAX_SPACES; i++) {
        outfile << spaces[i].spaceID << " " << spaces[i].status << " " << spaces[i].vehicleNumber << " " << spaces[i].duration << " " << spaces[i].userName << " " << spaces[i].isPaid << endl;
    }
    outfile.close();
    cout << "Parking data saved successfully." << endl;
}

void searchSpaces(ParkingSpace spaces[]) {
    cout << endl << "Available Parking Spaces:" << endl;
    bool available = false;
    for (int i = 0; i < MAX_SPACES; i++) {
        if (spaces[i].status == "available") {
            cout << "Space ID: " << spaces[i].spaceID << endl;
            available = true;
        }
    }
    if (!available) {
        cout << "No spaces are available at the moment." << endl;
    }
}

void viewReservations(ParkingSpace spaces[]) {
    cout << endl << "Reserved Parking Spaces:" << endl;
    bool reserved = false;
    for (int i = 0; i < MAX_SPACES; i++) {
        if (spaces[i].status == "occupied") {
            cout << "Space ID: " << spaces[i].spaceID << endl;
            cout << "Vehicle Number: " << spaces[i].vehicleNumber << endl;
            cout << "Duration: " << spaces[i].duration << " hours" << endl;
            cout << "Reserved by: " << spaces[i].userName << endl;
            cout << "Payment Status: " << (spaces[i].isPaid ? "Paid" : "Not Paid") << endl;
            reserved = true;
        }
    }
    if (!reserved) {
        cout << "No spaces are reserved at the moment." << endl;
    }
}

void displayHelp() {
    cout << endl << "Help Section:" << endl;
    cout << "1. Check Availability: View available parking spaces." << endl;
    cout << "2. Reserve Space: Reserve a parking space." << endl;
    cout << "3. Search for Space: Search for available parking spaces." << endl;
    cout << "4. Make Payment: Confirm payment for a reserved space." << endl;
    cout << "5. Free Space: Release a reserved parking space." << endl;
    cout << "6. View Reservations: View details of reserved spaces." << endl;
    cout << "7. Help: Display this help section." << endl;
    cout << "8. Sign Out: Log out of the current user account." << endl;
    cout << "9. Exit: Save data and exit the system." << endl;
}
