#include "dodgeball.h"
#include "Pickup.h"
#include "Compact.h"
#include "Sedan.h"
#include "reservation.h"
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <set>

using namespace std;

void OpenOutputFile(ofstream& outputFile_, string& carColor_, string& vehicleType_) {
    //ofstream outputFile_;
    string OutputFileName;
    int vehicle, color;
    //string vehicleType_, carColor_;
    bool vehicleCorrect = false;
    bool colorCorrect = false;
    do {
        cout << "\nPlease choose a vehicle:  \n";
        cout << "----------------------------------------\n";
        cout << "[1.Pickup] [2.Compact] [3.Sedan]\n";
        cin >> vehicle;
        if (vehicle == 1) {
            vehicleType_ = "pickup";
            vehicleCorrect = true;
            do {
                cout << "\nPlease choose a color:  \n";
                cout << "----------------------------------------\n";
                cout << "[1.Purple] [2.Green] [3.Black]\n";
                cin >> color;
                if (color == 1) {
                    carColor_ = "purple";
                    colorCorrect = true;
                }
                else if (color == 2) {
                    carColor_ = "green";
                    colorCorrect = true;
                }
                else if (color == 3) {
                    carColor_ = "black";
                    colorCorrect = true;
                }
                else {
                    cout << "Invalid Color choice. Choose a number between 1 and 3.\n";
                }
            } while (colorCorrect == false);
        }
        else if (vehicle == 2) {
            vehicleType_ = "compact";
            vehicleCorrect = true;
            do {
                cout << "\nPlease choose a color:  \n";
                cout << "----------------------------------------\n";
                cout << "[1.Red] [2.Blue] [3.Yellow]\n";
                cin >> color;
                if (color == 1) {
                    carColor_ = "red";
                    colorCorrect = true;
                }
                else if (color == 2) {
                    carColor_ = "blue";
                    colorCorrect = true;
                }
                else if (color == 3) {
                    carColor_ = "yellow";
                    colorCorrect = true;
                }
                else {
                    cout << "Invalid Color choice. Choose a number between 1 and 3.\n";
                }
            } while (colorCorrect == false);
        }
        else if (vehicle == 3) {
            vehicleType_ = "sedan";
            vehicleCorrect = true;
            do {
                cout << "\nPlease choose a color:  \n";
                cout << "----------------------------------------\n";
                cout << "[1.Blue] [2.Black] [3.Green]\n";
                cin >> color;
                if (color == 1) {
                    carColor_ = "blue";
                    colorCorrect = true;
                }
                else if (color == 2) {
                    carColor_ = "black";
                    colorCorrect = true;
                }
                else if (color == 3) {
                    carColor_ = "green";
                    colorCorrect = true;
                }
                else {
                    cout << "Invalid Color choice. Choose a number between 1 and 3.\n";
                }
            } while (colorCorrect == false);
        }
        else {
            cout << "Invalid Vehicle choice. Choose a number between 1 and 3.\n";
        }
    } while (vehicleCorrect == false);

    OutputFileName = carColor_ + "_" + vehicleType_ + ".txt";
    outputFile_.open(OutputFileName);

    //return outputFile;
}

ofstream openResFile() {
    string outputResFileName = "all_reservations.txt";
    ofstream outputResFile;
    outputResFile.open(outputResFileName);
    if (!outputResFile.is_open()) {
        cout << "\nUnable to open Reservation output file... Program Terminated\n";
        exit(1);
    }
    return outputResFile;
}

//Open the text file
ifstream Opendodgeball()
{
    string inFileName = "dodgeball_team.txt";
    ifstream temp;

    temp.open(inFileName.c_str());

    //check if it was open
    if (!temp.is_open()) {
        cout << "\nUnsuccessfully... Program Terminated\n" << endl;
        exit(1);
    }
    return (temp);
}


int main()
{

    // reservation reserved[24];
    Pickup Truck[3];// creates three objects of the pickup truck class
    Compact Pact[3];
    Sedan Dan[3];
    //truck[index].setColor
    //initulize file and assign it
    ifstream inFile;
    inFile = Opendodgeball();

    //vetors for song and strings for NAME ARTIST AND URL
    vector<team_mem> nun_Driver;
    string first_name;
    string NunDriver_last;
    int credits_;

    vector<team_mem> Driver;
    string Driver_first;
    string Driver_last;

    vector<reservation> reserved;

    vector<reservation> purplePickup;
    vector<reservation> greenPickup;
    vector<reservation> blackPickup;
    vector<reservation> redCompact;
    vector<reservation> blueCompact;
    vector<reservation> yellowCompact;
    vector<reservation> blueSedan;
    vector<reservation> blackSedan;
    vector<reservation> greenSedan;

    reservation tempres;
    team_mem tempmem;
    team_mem tempName;


    for (int i = 0; i < 9; i++) {
        inFile >> Driver_first >> Driver_last;
        team_mem tempmem(Driver_first, Driver_last, -1);
        Driver.push_back(tempmem);
    }
    Truck[0].setDriver("Pat");
    Truck[0].setColor("Purple");
    Truck[1].setDriver("Jane");
    Truck[1].setColor("Green");
    Truck[2].setDriver("Tim");
    Truck[2].setColor("Black");

    Pact[0].setDriver("Ben");
    Pact[0].setColor("Red");
    Pact[1].setDriver("Art");
    Pact[1].setColor("Blue");
    Pact[2].setDriver("Ann");
    Pact[2].setColor("Yellow");

    Dan[0].setDriver("Grace");
    Dan[0].setColor("Blue");
    Dan[1].setDriver("Lary");
    Dan[1].setColor("Black");
    Dan[2].setDriver("Jessie");
    Dan[2].setColor("Green");

    bool seat_ = false;
    bool color_t = false;

    for (int i = 0; i < 24; i++) {
        inFile >> first_name >> Driver_last >> credits_;
        team_mem tempName(first_name, NunDriver_last, credits_);
        nun_Driver.push_back(tempName);
    }
    int opt;

    //do while not 9 
    do {
        cout << "Please choose a option 1 - 7" << endl << endl;
        cout << " 1. Create Reservation" << endl;
        cout << " 2. Modify Reservation" << endl;
        cout << " 3. Delete reservation" << endl;
        cout << " 4. Display vehicles" << endl;
        cout << " 5. Print vehicle Assignments" << endl;
        cout << " 6. Print Reservations" << endl;
        cout << " 7. Quit" << endl;
        cout << " Enter Option: ";
        cin >> opt;

        //checks option does case statement
        switch (opt)
        {
        case 1: {

            cout << "Create Reservation" << endl;
            cout << "------------------------" << endl;
            bool validPass = false;
            int index = 99;

            string firstName;
            cout << "Enter First Name: ";
            cin >> firstName;
            for (int j = 0; j < nun_Driver.size(); j++) {
                if (nun_Driver[j].getName() == firstName) {
                    validPass = true;
                    index = j;
                }
            }
            if (!validPass) {
                cout << firstName << " was not found on the list\n";
                break;
            }
            int credits = nun_Driver[index].getCredit();

            if (credits == 0) {
                cout << firstName << " has zero credits. Unable to make reservation. Must provide their own transportation.\n";
                break;
            }

            // display the cars and seats
            cout << "\nDisplay Vehicles\n";

            for (int i = 0; i < 3; i++)
            {
                Truck[i].displayPickup();
            }
            for (int i = 0; i < 3; i++)
            {
                Pact[i].displayCompact();
            }
            for (int i = 0; i < 3; i++)
            {
                Dan[i].displaySedan();
            }
            cout << firstName << " has " << credits << " credits available\n";
            int vehicle;
            string vehicleType;
            int seatSelect;
            bool Confirm = false;
            string seat;
            int color_num = 0;
            bool getOut = false;
            string color_ = "notdone";
            cout << "\nSelect a specific vehicle\n";
            cout << "\n1.Truck" << "   2.Sedan" << "    3.Compact" << endl;
            cout << "Enter Number: " << endl;
            cin >> vehicle;
            if (vehicle == 1)
            {
                for (int i = 0; i < 3; i++)
                {
                    Truck[i].displayPickup();
                }
                color_t = false;
                do {
                    seat_ = false;
                    cout << "Select a specific Color\n";
                    cout << "Select speficic color [1.Purple] [2.Green] [3.Black]" << endl;
                    cin >> color_num;
                    //PURPLE
                    if (color_num == 1) {
                        if (Truck[0].getFront() == "X") {
                            do {
                                cout << "Select speficic seat [1.Front] " << endl;
                                cout << "Enter: ";
                                cin >> seatSelect;
                                if (seatSelect == 1) {
                                    if (Truck[0].getFrontCredit() <= credits) {
                                        Truck[0].setFront(firstName);
                                        vehicleType = "Pickup";
                                        seat = "Front";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                        getOut = true;
                                    }
                                }
                                else {
                                    cout << "\nseat not available. No space in this vehicle\n";
                                }

                            } while (getOut == false);

                            color_ = "Purple";
                            color_t = true;
                        }
                        else {
                            cout << "\nNo seats available. Please choose a different color or vehicle\n";

                        }


                    }
                    //GREEN
                    else if (color_num == 2) {
                        if (Truck[1].getFront() == "X") {
                            do {
                                cout << "Select speficic seat [1.Front] " << endl;
                                cout << "Enter: ";
                                cin >> seatSelect;
                                if (seatSelect == 1) {
                                    if (Truck[1].getFrontCredit() <= credits) {
                                        Truck[1].setFront(firstName);
                                        vehicleType = "Pickup";
                                        seat = "Front";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                        getOut = true;
                                    }

                                }
                                else {
                                    cout << "\n Please choose a valid seat option\n";
                                }
                            } while (getOut == false);
                            color_ = "Green";
                            color_t = true;
                        }
                        else {
                            cout << "\nNo seats available. Please choose a different color or vehicle\n";

                        }

                    }
                    //BLACK
                    else if (color_num == 3) {
                        if (Truck[2].getFront() == "X") {
                            do {
                                cout << "Select speficic seat [1.Front] " << endl;
                                cout << "Enter: ";
                                cin >> seatSelect;
                                if (seatSelect == 1) {
                                    if (Truck[2].getFrontCredit() <= credits) {
                                        Truck[2].setFront(firstName);
                                        vehicleType = "Pickup";
                                        seat = "Front";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                        getOut = true;
                                    }
                                }
                                else {
                                    cout << "\n Please choose a valid seat option\n";
                                }
                            } while (getOut == false);
                            color_ = "Black";
                            color_t = true;
                        }
                        else {
                            cout << "\nNo seats available. Please choose a different color\n";
                            //color_ = "Done";
                        }
                    }
                    else {
                        cout << "invalid Color" << endl;
                    }
                } while (color_t == false);
            }


            else if (vehicle == 2)
            {
                for (int i = 0; i < 3; i++)
                {
                    Dan[i].displaySedan();
                }
                do {
                    seat = "notdone";
                    cout << "Select a specific Color\n";
                    cout << "Select speficic color [1.Blue] [2.Black] [3.Green] " << endl;
                    cin >> color_num;

                    //blue
                    if (color_num == 1) {
                        Dan[0].displaySedan();
                        do {
                            cout << "Select speficic seat [1.Front] [2.BackMid] [3.BackLeft] [4.BackRight] " << endl;
                            cout << "Enter: ";
                            cin >> seatSelect;
                            if (seatSelect == 1) {
                                if (Dan[0].getFront() == "X") {
                                    if (Dan[0].getFrontCredit() <= credits) {
                                        Dan[0].setFront(firstName);
                                        vehicleType = "Sedan";
                                        seat = "Front";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }

                            }
                            else if (seatSelect == 2) {
                                if (Dan[0].getBackMid() == "X") {
                                    if (Dan[0].getBackMidCredit() <= credits) {
                                        Dan[0].setBackMid(firstName);
                                        vehicleType = "Sedan";
                                        seat = "BackMid";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 3) {
                                if (Dan[0].getBackLeft() == "X") {
                                    if (Dan[0].getBackLeftCredit() <= credits) {
                                        Dan[0].setBackLeft(firstName);
                                        vehicleType = "Sedan";
                                        seat = "BackLeft";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 4) {
                                if (Dan[0].getBackRight() == "X") {
                                    if (Dan[0].getBackRightCredit() <= credits) {
                                        Dan[0].setBackRight(firstName);
                                        vehicleType = "Sedan";
                                        seat = "BackRight";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 5) {
                                getOut = true;
                            }
                        } while (getOut == false);
                        color_ = "Blue";
                        color_t = true;
                    }



                    //BLACK
                    else if (color_num == 2) {
                        Dan[1].displaySedan();
                        do {
                            cout << "Select speficic seat [1.Front] [2.BackMid] [3.BackLeft] [4.BackRight]" << endl;
                            cout << "Enter: ";
                            cin >> seatSelect;
                            if (seatSelect == 1) {
                                if (Dan[1].getFront() == "X") {
                                    if (Dan[1].getFrontCredit() <= credits) {
                                        Dan[1].setFront(firstName);
                                        vehicleType = "Sedan";
                                        seat = "Front";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }

                            }
                            else if (seatSelect == 2) {
                                if (Dan[1].getBackMid() == "X") {
                                    if (Dan[1].getBackMidCredit() <= credits) {
                                        Dan[1].setBackMid(firstName);
                                        vehicleType = "Sedan";
                                        seat = "BackMid";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 3) {
                                if (Dan[1].getBackLeft() == "X") {
                                    if (Dan[1].getBackLeftCredit() <= credits) {
                                        Dan[1].setBackLeft(firstName);
                                        vehicleType = "Sedan";
                                        seat = "BackLeft";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 4) {
                                if (Dan[1].getBackRight() == "X") {
                                    if (Dan[1].getBackRightCredit() <= credits) {
                                        Dan[1].setBackRight(firstName);
                                        vehicleType = "Sedan";
                                        seat = "BackRight";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 5) {
                                getOut = true;
                            }
                        } while (getOut == false);

                        color_ = "Black";
                        color_t = true;

                    }




                    //GREEN
                    else if (color_num == 3) {
                        Dan[2].displaySedan();
                        do {
                            cout << "Select speficic seat [1.Front] [2.BackMid] [3.BackLeft] [4.BackRight] " << endl;
                            cout << "Enter: ";
                            cin >> seatSelect;
                            if (seatSelect == 1) {
                                if (Dan[2].getFront() == "X") {
                                    if (Dan[2].getFrontCredit() <= credits) {
                                        Dan[2].setFront(firstName);
                                        vehicleType = "Sedan";
                                        seat = "Front";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }

                            }
                            else if (seatSelect == 2) {
                                if (Dan[2].getBackMid() == "X") {
                                    if (Dan[2].getBackMidCredit() <= credits) {
                                        Dan[2].setBackMid(firstName);
                                        vehicleType = "Sedan";
                                        seat = "BackMid";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 3) {
                                if (Dan[2].getBackLeft() == "X") {
                                    if (Dan[2].getBackLeftCredit() <= credits) {
                                        Dan[2].setBackLeft(firstName);
                                        vehicleType = "Sedan";
                                        seat = "BackLeft";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 4) {
                                if (Dan[2].getBackRight() == "X") {
                                    if (Dan[2].getBackRightCredit() <= credits) {
                                        Dan[2].setBackRight(firstName);
                                        vehicleType = "Sedan";
                                        seat = "BackRight";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat\n";

                                }
                            }
                            else if (seatSelect == 5) {
                                getOut = true;
                            }
                            else {
                                cout << "invalid Color" << endl;
                            }
                        } while (getOut == false);

                    }
                    color_ = "Green";
                    color_t = true;
                } while (color_t == false);
            }























            else if (vehicle == 3)
            {
                for (int i = 0; i < 3; i++)
                {
                    Pact[i].displayCompact();
                }
                do {
                    seat = "notdone";
                    cout << "Select a specific Color\n";
                    cout << "Select speficic color [1.Red] [2.Blue] [3.Yellow]" << endl;
                    cin >> color_num;

                    //RED
                    if (color_num == 1) {
                        Pact[0].displayCompact();
                        do {
                            cout << "Select speficic seat [1.Front] [2.BackLeft] [3.BackRight] " << endl;
                            cout << "Enter: ";
                            cin >> seatSelect;
                            if (seatSelect == 1) {
                                if (Pact[0].getFront() == "X") {
                                    if (Pact[0].getFrontCredit() <= credits) {
                                        Pact[0].setFront(firstName);
                                        vehicleType = "Compact";
                                        seat = "Front";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }

                            }

                            else if (seatSelect == 2) {
                                if (Pact[0].getBackLeft() == "X") {
                                    if (Pact[0].getBackLeftCredit() <= credits) {
                                        Pact[0].setBackLeft(firstName);
                                        vehicleType = "Compact";
                                        seat = "BackLeft";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 3) {
                                if (Pact[0].getBackRight() == "X") {
                                    if (Pact[0].getBackRightCredit() <= credits) {
                                        Pact[0].setBackRight(firstName);
                                        vehicleType = "Compact";
                                        seat = "BackRight";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 4) {
                                getOut = true;
                            }
                        } while (getOut == false);
                        color_ = "Red";
                        color_t = true;
                    }











                    //Blue
                    else if (color_num == 2) {
                        Pact[1].displayCompact();
                        do {
                            cout << "Select speficic seat [1.Front] [2.BackLeft] [3.BackRight] " << endl;
                            cout << "Enter: ";
                            cin >> seatSelect;
                            if (seatSelect == 1) {
                                if (Pact[1].getFront() == "X") {
                                    if (Pact[1].getFrontCredit() <= credits) {
                                        Pact[1].setFront(firstName);
                                        vehicleType = "Compact";
                                        seat = "Front";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }

                            }

                            else if (seatSelect == 2) {
                                if (Pact[1].getBackLeft() == "X") {
                                    if (Pact[1].getBackLeftCredit() <= credits) {
                                        Pact[1].setBackLeft(firstName);
                                        vehicleType = "Compact";
                                        seat = "BackLeft";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 3) {
                                if (Pact[1].getBackRight() == "X") {
                                    if (Pact[1].getBackRightCredit() <= credits) {
                                        Pact[1].setBackRight(firstName);
                                        vehicleType = "Compact";
                                        seat = "BackRight";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 4) {
                                getOut = true;
                            }
                        } while (getOut == false);

                        color_ = "Blue";
                        color_t = true;
                    }








                    //Yellow
                    else if (color_num == 3) {
                        Pact[2].displayCompact();
                        do {
                            cout << "Select speficic seat [1.Front] [2.BackLeft] [3.BackRight] " << endl;
                            cout << "Enter: ";
                            cin >> seatSelect;
                            if (seatSelect == '1') {
                                if (Pact[2].getFront() == "X") {
                                    if (Pact[2].getFrontCredit() <= credits) {
                                        Pact[2].setFront(firstName);
                                        vehicleType = "Compact";
                                        seat = "Front";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }

                            }
                            else if (seatSelect == 2) {
                                if (Pact[2].getBackLeft() == "X") {
                                    if (Pact[2].getBackLeftCredit() <= credits) {
                                        Pact[2].setBackLeft(firstName);
                                        vehicleType = "Compact";
                                        seat = "BackLeft";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 3) {
                                if (Pact[2].getBackRight() == "X") {
                                    if (Pact[2].getBackRightCredit() <= credits) {
                                        Pact[2].setBackRight(firstName);
                                        vehicleType = "Compact";
                                        seat = "BackRight";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat\n";

                                }
                            }
                            else if (seatSelect == 4) {
                                getOut = true;
                            }
                        } while (getOut == false);

                        color_ = "Yellow";
                        color_t = true;
                    }

                    else {
                        cout << "invalid Color" << endl;
                    }
                } while (color_t == false);
            }


            if (seat_ == true) {
                int num_pin = 26;
                int max = 99;
                int pin;

                vector<int> randNumber;
                srand(time(NULL));
                int nextRand;
                int current_size;
                set<int> pin_;

                while (pin_.size() < num_pin)
                {
                    nextRand = rand() % (max + 1);
                    current_size = pin_.size();
                    pin_.insert(nextRand);
                    if (current_size == pin_.size())
                    {
                    }
                    else {
                        randNumber.push_back(nextRand);
                    }
                }
                pin = nextRand;
                reservation tempres(firstName, vehicleType, color_, pin, seat);
                reserved.push_back(tempres);
                cout << "you have successfully made a reservation. Your Pin is :" << pin << endl;
            }
            else if (seat_ == false) {
                cout << "\nUnable to make reservation. Please Try Again.\n";
            }
            else {
                cout << "\nUnknown Issue. Please Try Again\n";
            }





            break; }
        case 2: {
            bool foundCheck = false;
            bool resChanged = false;
            string nameSer;
            int PINSer;
            cout << "Modify Reservation" << endl;
            cout << "------------------------" << endl;
            do {
                do {
                    cout << "\nWhat is the name used on the Reservation?: ";
                    cin >> nameSer;
                    cout << "\nWhat is the PIN for the Reservation?: ";
                    cin >> PINSer;
                    for (int k = 0; k < reserved.size(); ++k) {
                        if (reserved.at(k).getName() == nameSer && reserved.at(k).getPin() == PINSer) {


                            cout << "\nRervation Found. Deleting reservation...\n";
                            reserved.erase(reserved.begin() + k);

                            foundCheck = true;
                        }
                        else {
                            cout << "\nName and/or Pin do not match or may not exits. Try Again.\n";
                        }
                    }
                } while (foundCheck == false);
                bool validPass = false;
                int index = 99;

                string firstName = nameSer;
                for (int j = 0; j < nun_Driver.size(); j++) {
                    if (nun_Driver[j].getName() == firstName) {
                        validPass = true;
                        index = j;
                    }
                }
                if (!validPass) {
                    cout << firstName << " was not found on the list\n";
                    break;
                }
                /* int credits = nun_Driver[index].getCredit();
                 cout << firstName << " has " << credits << " credits available\n";*/
                int credits = nun_Driver[index].getCredit();
                if (credits == 0) {
                    cout << firstName << " has zero credits. Unable to make reservation. Must provide their own transportation.\n";
                    break;
                }
                if (Truck[0].getFront() == firstName) {
                    Truck[0].setFront("X");
                }

                //GREEN

                else   if (Truck[1].getFront() == firstName) {
                    Truck[1].setFront("X");
                }

                //BLACK

                else if (Truck[2].getFront() == firstName) {
                    Truck[2].setFront("X");
                }

                //blue

                else if (Dan[0].getFront() == firstName) {
                    Dan[0].setFront("X");
                }

                else if (Dan[0].getBackMid() == firstName) {
                    Dan[0].setBackMid("X");

                }

                else if (Dan[0].getBackLeft() == firstName) {
                    Dan[0].setBackLeft("X");
                }

                else  if (Dan[0].getBackRight() == firstName) {
                    Dan[0].setBackRight("X");

                }



                //BLACK

                else if (Dan[1].getFront() == firstName) {
                    Dan[1].setFront("X");

                }

                else if (Dan[1].getBackMid() == firstName) {
                    Dan[1].setBackMid("X");

                }

                else if (Dan[1].getBackLeft() == firstName) {
                    Dan[1].setBackLeft("X");

                }

                else if (Dan[1].getBackRight() == firstName) {
                    Dan[1].setBackRight("X");

                }

                //GREEN

                else if (Dan[2].getFront() == firstName) {
                    Dan[2].setFront("X");
                }

                else if (Dan[2].getBackMid() == firstName) {
                    Dan[2].setBackMid("X");

                }

                else if (Dan[2].getBackLeft() == firstName) {
                    Dan[2].setBackLeft("X");

                }

                else if (Dan[2].getBackRight() == firstName) {
                    Dan[2].setBackRight("X");

                }

                //RED
                else if (Pact[0].getFront() == firstName) {
                    Pact[0].setFront("X");
                }

                else if (Pact[0].getBackLeft() == firstName) {
                    Pact[0].setBackLeft("X");
                }

                else if (Pact[0].getBackRight() == firstName) {
                    Pact[0].setBackRight("X");
                }

                //Blue

                else if (Pact[1].getFront() == firstName) {
                    Pact[1].setFront("X");
                }

                else if (Pact[1].getBackLeft() == firstName) {
                    Pact[1].setBackLeft("X");
                }

                else if (Pact[1].getBackRight() == firstName) {
                    Pact[1].setBackRight("X");
                }

                //Yellow

                else if (Pact[2].getFront() == firstName) {
                    Pact[2].setFront("X");
                }

                else if (Pact[2].getBackLeft() == firstName) {
                    Pact[2].setBackLeft("X");
                }

                else if (Pact[2].getBackRight() == firstName) {
                    Pact[2].setBackRight("X");
                }



                cout << "\nDisplay Vehicles\n";

                for (int i = 0; i < 3; i++)
                {
                    Truck[i].displayPickup();
                }
                for (int i = 0; i < 3; i++)
                {
                    Pact[i].displayCompact();
                }
                for (int i = 0; i < 3; i++)
                {
                    Dan[i].displaySedan();
                }
                cout << "\nReservation removed. Please make a new reservation.\n";
                cout << "------------------------" << endl;
                cout << firstName << " has " << credits << " credits available\n";

                int vehicle;
                string vehicleType;
                int seatSelect;
                bool Confirm = false;
                string seat;
                int color_num = 0;
                bool getOut = false;
                string color_ = "notdone";
                cout << "\nSelect a specific vehicle\n";
                cout << "\n1.Truck" << "   2.Sedan" << "    3.Compact" << endl;
                cout << "Enter Number: " << endl;
                cin >> vehicle;
                if (vehicle == 1)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        Truck[i].displayPickup();
                    }
                    color_t = false;
                    do {
                        seat_ = false;
                        //cout << "Select a specific Color\n";
                        cout << "Select speficic color [1.Purple] [2.Green] [3.Black]" << endl;
                        cin >> color_num;
                        //PURPLE
                        if (color_num == 1) {
                            if (Truck[0].getFront() == "X") {
                                do {
                                    cout << "Select speficic seat [1.Front] " << endl;
                                    cout << "Enter: ";
                                    cin >> seatSelect;
                                    if (seatSelect == 1) {
                                        if (Truck[0].getFrontCredit() <= credits) {
                                            Truck[0].setFront(firstName);
                                            vehicleType = "Pickup";
                                            seat = "Front";
                                            seat_ = true;
                                            getOut = true;
                                        }
                                        else {
                                            cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                            seat_ = false;
                                            getOut = true;
                                        }
                                    }
                                    else {
                                        cout << "\nseat not available. No space in this vehicle\n";
                                    }

                                } while (getOut == false);

                                color_ = "Purple";
                                color_t = true;
                            }
                            else {
                                cout << "\nNo seats available. Please choose a different color or vehicle\n";

                            }


                        }
                        //GREEN
                        else if (color_num == 2) {
                            if (Truck[1].getFront() == "X") {
                                do {
                                    cout << "Select speficic seat [1.Front] " << endl;
                                    cout << "Enter: ";
                                    cin >> seatSelect;
                                    if (seatSelect == 1) {
                                        if (Truck[1].getFrontCredit() <= credits) {
                                            Truck[1].setFront(firstName);
                                            vehicleType = "Pickup";
                                            seat = "Front";
                                            seat_ = true;
                                            getOut = true;
                                        }
                                        else {
                                            cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                            seat_ = false;
                                            getOut = true;
                                        }

                                    }
                                    else {
                                        cout << "\n Please choose a valid seat option\n";
                                    }
                                } while (getOut == false);
                                color_ = "Green";
                                color_t = true;
                            }
                            else {
                                cout << "\nNo seats available. Please choose a different color or vehicle\n";


                            }

                        }
                        //BLACK
                        else if (color_num == 3) {
                            if (Truck[2].getFront() == "X") {
                                do {
                                    cout << "Select speficic seat [1.Front] " << endl;
                                    cout << "Enter: ";
                                    cin >> seatSelect;
                                    if (seatSelect == 1) {
                                        if (Truck[2].getFrontCredit() <= credits) {
                                            Truck[2].setFront(firstName);
                                            vehicleType = "Pickup";
                                            seat = "Front";
                                            seat_ = true;
                                            getOut = true;
                                        }
                                        else {
                                            cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                            seat_ = false;
                                            getOut = true;
                                        }
                                    }
                                    else {
                                        cout << "\n Please choose a valid seat option\n";
                                    }
                                } while (getOut == false);
                                color_ = "Black";
                                color_t = true;
                            }
                            else {
                                cout << "\nNo seats available. Please choose a different color\n";

                            }
                        }
                        else {
                            cout << "invalid Color" << endl;
                        }
                    } while (color_t == false);

                }





                else if (vehicle == 2)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        Dan[i].displaySedan();
                    }
                    do {
                        seat = "notdone";
                        //cout << "Select a specific Color\n";
                        cout << "Select speficic color [1.Blue] [2.Black] [3.Green] " << endl;
                        cin >> color_num;

                        //blue
                        if (color_num == 1) {
                            Dan[0].displaySedan();
                            do {
                                cout << "Select speficic seat [1.Front] [2.BackMid] [3.BackLeft] [4.BackRight] " << endl;
                                cout << "Enter: ";
                                cin >> seatSelect;
                                if (seatSelect == 1) {
                                    if (Dan[0].getFront() == "X") {
                                        if (Dan[0].getFrontCredit() <= credits) {
                                            Dan[0].setFront(firstName);
                                            vehicleType = "Sedan";
                                            seat = "Front";
                                            seat_ = true;
                                            getOut = true;
                                        }
                                        else {
                                            cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                            seat_ = false;
                                        }
                                    }
                                    else {
                                        cout << "\nSeat not available. Please choose a different seat,color\n";

                                    }

                                }
                                else if (seatSelect == 2) {
                                    if (Dan[0].getBackMid() == "X") {
                                        if (Dan[0].getBackMidCredit() <= credits) {
                                            Dan[0].setBackMid(firstName);
                                            vehicleType = "Sedan";
                                            seat = "BackMid";
                                            seat_ = true;
                                            getOut = true;
                                        }
                                        else {
                                            cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                            seat_ = false;
                                        }
                                    }
                                    else {
                                        cout << "\nSeat not available. Please choose a different seat,color\n";

                                    }
                                }
                                else if (seatSelect == 3) {
                                    if (Dan[0].getBackLeft() == "X") {
                                        if (Dan[0].getBackLeftCredit() <= credits) {
                                            Dan[0].setBackLeft(firstName);
                                            vehicleType = "Sedan";
                                            seat = "BackLeft";
                                            seat_ = true;
                                            getOut = true;
                                        }
                                        else {
                                            cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                            seat_ = false;
                                        }
                                    }
                                    else {
                                        cout << "\nSeat not available. Please choose a different seat,color\n";

                                    }
                                }
                                else if (seatSelect == 4) {
                                    if (Dan[0].getBackRight() == "X") {
                                        if (Dan[0].getBackRightCredit() <= credits) {
                                            Dan[0].setBackRight(firstName);
                                            vehicleType = "Sedan";
                                            seat = "BackRight";
                                            seat_ = true;
                                            getOut = true;
                                        }
                                        else {
                                            cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                            seat_ = false;
                                        }
                                    }
                                    else {
                                        cout << "\nSeat not available. Please choose a different seat,color\n";

                                    }
                                }
                                else if (seatSelect == 5) {
                                    getOut = true;
                                }
                            } while (getOut == false);
                        }
                        color_ = "Blue";
                        color_t = true;
                    } while (color_t == false);
                }









                //BLACK
                else if (color_num == 2) {
                    Dan[1].displaySedan();
                    do {
                        cout << "Select speficic seat [1.Front] [2.BackMid] [3.BackLeft] [4.BackRight] " << endl;
                        cout << "Enter: ";
                        cin >> seatSelect;
                        if (seatSelect == 1) {
                            if (Dan[1].getFront() == "X") {
                                if (Dan[1].getFrontCredit() <= credits) {
                                    Dan[1].setFront(firstName);
                                    vehicleType = "Sedan";
                                    seat = "Front";
                                    seat_ = true;
                                    getOut = true;
                                }
                                else {
                                    cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                    seat_ = false;
                                }
                            }
                            else {
                                cout << "\nSeat not available. Please choose a different seat,color\n";

                            }

                        }
                        else if (seatSelect == 2) {
                            if (Dan[1].getBackMid() == "X") {
                                if (Dan[1].getBackMidCredit() <= credits) {
                                    Dan[1].setBackMid(firstName);
                                    vehicleType = "Sedan";
                                    seat = "BackMid";
                                    seat_ = true;
                                    getOut = true;
                                }
                                else {
                                    cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                    seat_ = false;
                                }
                            }
                            else {
                                cout << "\nSeat not available. Please choose a different seat,color\n";

                            }
                        }
                        else if (seatSelect == 3) {
                            if (Dan[1].getBackLeft() == "X") {
                                if (Dan[1].getBackLeftCredit() <= credits) {
                                    Dan[1].setBackLeft(firstName);
                                    vehicleType = "Sedan";
                                    seat = "BackLeft";
                                    seat_ = true;
                                    getOut = true;
                                }
                                else {
                                    cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                    seat_ = false;
                                }
                            }
                            else {
                                cout << "\nSeat not available. Please choose a different seat,color\n";

                            }
                        }
                        else if (seatSelect == 4) {
                            if (Dan[1].getBackRight() == "X") {
                                if (Dan[1].getBackRightCredit() <= credits) {
                                    Dan[1].setBackRight(firstName);
                                    vehicleType = "Sedan";
                                    seat = "BackRight";
                                    seat_ = true;
                                    getOut = true;
                                }
                                else {
                                    cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                    seat_ = false;
                                }
                            }
                            else {
                                cout << "\nSeat not available. Please choose a different seat,color\n";

                            }
                        }
                        else if (seatSelect == 5) {
                            getOut = true;
                        }
                    } while (getOut == false);

                    color_ = "Black";
                    color_t = true;

                }





                //GREEN
                else if (color_num == 3) {
                    Dan[2].displaySedan();
                    do {
                        cout << "Select speficic seat [1.Front] [2.BackMid] [3.BackLeft] [4.BackRight] " << endl;
                        cout << "Enter: ";
                        cin >> seatSelect;
                        if (seatSelect == 1) {
                            if (Dan[2].getFront() == "X") {
                                if (Dan[2].getFrontCredit() <= credits) {
                                    Dan[2].setFront(firstName);
                                    vehicleType = "Sedan";
                                    seat = "Front";
                                    seat_ = true;
                                    getOut = true;
                                }
                                else {
                                    cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                    seat_ = false;
                                }
                            }
                            else {
                                cout << "\nSeat not available. Please choose a different seat,color\n";

                            }

                        }
                        else if (seatSelect == 2) {
                            if (Dan[2].getBackMid() == "X") {
                                if (Dan[2].getBackMidCredit() <= credits) {
                                    Dan[2].setBackMid(firstName);
                                    vehicleType = "Sedan";
                                    seat = "BackMid";
                                    seat_ = true;
                                    getOut = true;
                                }
                                else {
                                    cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                    seat_ = false;
                                }
                            }
                            else {
                                cout << "\nSeat not available. Please choose a different seat,color\n";

                            }
                        }
                        else if (seatSelect == 3) {
                            if (Dan[2].getBackLeft() == "X") {
                                if (Dan[2].getBackLeftCredit() <= credits) {
                                    Dan[2].setBackLeft(firstName);
                                    vehicleType = "Sedan";
                                    seat = "BackLeft";
                                    seat_ = true;
                                    getOut = true;
                                }
                                else {
                                    cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                    seat_ = false;
                                }
                            }
                            else {
                                cout << "\nSeat not available. Please choose a different seat,color\n";

                            }
                        }
                        else if (seatSelect == 4) {
                            if (Dan[2].getBackRight() == "X") {
                                if (Dan[2].getBackRightCredit() <= credits) {
                                    Dan[2].setBackRight(firstName);
                                    vehicleType = "Sedan";
                                    seat = "BackRight";
                                    seat_ = true;
                                    getOut = true;
                                }
                                else {
                                    cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                    seat_ = false;
                                }
                            }
                            else {
                                cout << "\nSeat not available. Please choose a different seat\n";

                            }
                        }
                        else if (seatSelect == 5) {
                            getOut = true;
                        }
                        else {
                            cout << "invalid Color" << endl;
                        }
                    } while (getOut == false);
                    color_ = "Green";
                    color_t = true;
                }
                //while (color_t == false);





                else if (vehicle == 3)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        Pact[i].displayCompact();
                    }
                    do {
                        seat = "notdone";
                        //cout << "Select a specific Color\n";
                        cout << "Select speficic color [1.Red] [2.Blue] [3.Yellow]" << endl;
                        cin >> color_num;

                        //RED
                        if (color_num == 1) {
                            Pact[0].displayCompact();
                            do {
                                cout << "Select speficic seat [1.Front] [2.BackLeft] [3.BackRight]" << endl;
                                cout << "Enter: ";
                                cin >> seatSelect;
                                if (seatSelect == 1) {
                                    if (Pact[0].getFront() == "X") {
                                        if (Pact[0].getFrontCredit() <= credits) {
                                            Pact[0].setFront(firstName);
                                            vehicleType = "Compact";
                                            seat = "Front";
                                            seat_ = true;
                                            getOut = true;
                                        }
                                        else {
                                            cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                            seat_ = false;
                                        }
                                    }
                                    else {
                                        cout << "\nSeat not available. Please choose a different seat,color\n";

                                    }

                                }

                                else if (seatSelect == 2) {
                                    if (Pact[0].getBackLeft() == "X") {
                                        if (Pact[0].getBackLeftCredit() <= credits) {
                                            Pact[0].setBackLeft(firstName);
                                            vehicleType = "Compact";
                                            seat = "BackLeft";
                                            seat_ = true;
                                            getOut = true;
                                        }
                                        else {
                                            cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                            seat_ = false;
                                        }
                                    }
                                    else {
                                        cout << "\nSeat not available. Please choose a different seat,color\n";

                                    }
                                }
                                else if (seatSelect == 3) {
                                    if (Pact[0].getBackRight() == "X") {
                                        if (Pact[0].getBackRightCredit() <= credits) {
                                            Pact[0].setBackRight(firstName);
                                            vehicleType = "Compact";
                                            seat = "BackRight";
                                            seat_ = true;
                                            getOut = true;
                                        }
                                        else {
                                            cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                            seat_ = false;
                                        }
                                    }
                                    else {
                                        cout << "\nSeat not available. Please choose a different seat,color\n";

                                    }
                                }
                                else if (seatSelect == 4) {
                                    getOut = true;
                                }
                            } while (getOut == false);
                            color_ = "Red";
                            color_t = true;
                        }




                        //Blue
                        else if (color_num == 2) {
                            Pact[1].displayCompact();
                            do {
                                cout << "Select speficic seat [1.Front] [2.BackLeft] [3.BackRight]" << endl;
                                cout << "Enter: ";
                                cin >> seatSelect;
                                if (seatSelect == 1) {
                                    if (Pact[1].getFront() == "X") {
                                        if (Pact[1].getFrontCredit() <= credits) {
                                            Pact[1].setFront(firstName);
                                            vehicleType = "Compact";
                                            seat = "Front";
                                            seat_ = true;
                                            getOut = true;
                                        }
                                        else {
                                            cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                            seat_ = false;
                                        }
                                    }
                                    else {
                                        cout << "\nSeat not available. Please choose a different seat,color\n";

                                    }

                                }

                                else if (seatSelect == 2) {
                                    if (Pact[1].getBackLeft() == "X") {
                                        if (Pact[1].getBackLeftCredit() <= credits) {
                                            Pact[1].setBackLeft(firstName);
                                            vehicleType = "Compact";
                                            seat = "BackLeft";
                                            seat_ = true;
                                            getOut = true;
                                        }
                                        else {
                                            cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                            seat_ = false;
                                        }
                                    }
                                    else {
                                        cout << "\nSeat not available. Please choose a different seat,color\n";

                                    }
                                }
                                else if (seatSelect == 3) {
                                    if (Pact[1].getBackRight() == "X") {
                                        if (Pact[1].getBackRightCredit() <= credits) {
                                            Pact[1].setBackRight(firstName);
                                            vehicleType = "Compact";
                                            seat = "BackRight";
                                            seat_ = true;
                                            getOut = true;
                                        }
                                        else {
                                            cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                            seat_ = false;
                                        }
                                    }
                                    else {
                                        cout << "\nSeat not available. Please choose a different seat,color\n";

                                    }
                                }
                                else if (seatSelect == 4) {
                                    getOut = true;
                                }
                            } while (getOut == false);

                            color_ = "Blue";
                            color_t = true;
                        }



                        //Yellow
                        else if (color_num == 3) {
                            Pact[2].displayCompact();
                            do {
                                cout << "Select speficic seat [1.Front] [2.BackLeft] [3.BackRight] " << endl;
                                cout << "Enter: ";
                                cin >> seatSelect;
                                if (seatSelect == '1') {
                                    if (Pact[2].getFront() == "X") {
                                        if (Pact[2].getFrontCredit() <= credits) {
                                            Pact[2].setFront(firstName);
                                            vehicleType = "Compact";
                                            seat = "Front";
                                            seat_ = true;
                                            getOut = true;
                                        }
                                        else {
                                            cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                            seat_ = false;
                                        }
                                    }
                                    else {
                                        cout << "\nSeat not available. Please choose a different seat,color\n";

                                    }

                                }
                                else if (seatSelect == 2) {
                                    if (Pact[2].getBackLeft() == "X") {
                                        if (Pact[2].getBackLeftCredit() <= credits) {
                                            Pact[2].setBackLeft(firstName);
                                            vehicleType = "Compact";
                                            seat = "BackLeft";
                                            seat_ = true;
                                            getOut = true;
                                        }
                                        else {
                                            cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                            seat_ = false;
                                        }
                                    }
                                    else {
                                        cout << "\nSeat not available. Please choose a different seat,color\n";

                                    }
                                }
                                else if (seatSelect == 3) {
                                    if (Pact[2].getBackRight() == "X") {
                                        if (Pact[2].getBackRightCredit() <= credits) {
                                            Pact[2].setBackRight(firstName);
                                            vehicleType = "Compact";
                                            seat = "BackRight";
                                            seat_ = true;
                                            getOut = true;
                                        }
                                        else {
                                            cout << endl << firstName << " does not have enough credits. Please select a different option\n";
                                            seat_ = false;
                                        }
                                    }
                                    else {
                                        cout << "\nSeat not available. Please choose a different seat\n";

                                    }
                                }
                                else if (seatSelect == 4) {
                                    getOut = true;
                                }
                            } while (getOut == false);

                            color_ = "Yellow";
                            color_t = true;
                        }

                        else {
                            cout << "invalid Color" << endl;
                        }
                    } while (color_t == false);
                }


                if (seat_ == true) {
                    int num_pin = 26;
                    int max = 99;
                    int pin = 0;

                    vector<int> randNumber;
                    srand(time(NULL));
                    int nextRand;
                    int current_size;
                    set<int> pin_;

                    while (pin_.size() < num_pin)
                    {
                        nextRand = rand() % (max + 1);
                        current_size = pin_.size();
                        pin_.insert(nextRand);
                        if (current_size == pin_.size()) {
                        }
                        else {
                            randNumber.push_back(nextRand);
                        }
                    }
                    pin = nextRand;
                    reservation tempres(firstName, vehicleType, color_, pin, seat);
                    reserved.push_back(tempres);
                    cout << "you have successfully made a new reservation. Your new Pin is :" << pin << endl;
                    //foundCheck = true;
                    resChanged = true;
                }
                else if (seat_ == false) {
                    cout << "\nUnable to make reservation. Please Try Again.\n";
                }
                else {
                    cout << "\nUnknown Issue. Please Try Again\n";
                }
            } while (resChanged == false);//do while loops if res no chnaged 


            break; }


        case 3: {
            string nameS;
            int pin = 0;
            bool resdone = false;
            cout << "Delete reservation" << endl;
            cout << "------------------------" << endl;
            do {
                cout << "\nWhat is the name used on the Reservation? ";
                cin >> nameS;
                cout << "\nWhat is the PIN for the Reservation?: ";
                cin >> pin;
                for (int k = 0; k < reserved.size(); ++k) {
                    if (reserved.at(k).getName() == nameS && reserved.at(k).getPin() == pin) {
                        cout << "\nServation Found. Deleting reservation...\n";
                        reserved.erase(reserved.begin() + k);
                        resdone = true;
                        break;
                    }
                    else {
                        cout << "\nName and/or Pin do not match or may not exits. Try Again.\n";
                    }
                }
            } while (resdone == false);
            //PURPLE
            if (Truck[0].getFront() == nameS) {
                Truck[0].setFront("X");
            }

            //GREEN

            else   if (Truck[1].getFront() == nameS) {
                Truck[1].setFront("X");
            }

            //BLACK

            else if (Truck[2].getFront() == nameS) {
                Truck[2].setFront("X");
            }

            //blue

            else if (Dan[0].getFront() == nameS) {
                Dan[0].setFront("X");
            }

            else if (Dan[0].getBackMid() == nameS) {
                Dan[0].setBackMid("X");

            }

            else if (Dan[0].getBackLeft() == nameS) {
                Dan[0].setBackLeft("X");
            }

            else  if (Dan[0].getBackRight() == nameS) {
                Dan[0].setBackRight("X");

            }



            //BLACK

            else if (Dan[1].getFront() == nameS) {
                Dan[1].setFront("X");

            }

            else if (Dan[1].getBackMid() == nameS) {
                Dan[1].setBackMid("X");

            }

            else if (Dan[1].getBackLeft() == nameS) {
                Dan[1].setBackLeft("X");

            }

            else if (Dan[1].getBackRight() == nameS) {
                Dan[1].setBackRight("X");

            }

            //GREEN

            else if (Dan[2].getFront() == nameS) {
                Dan[2].setFront("X");
            }

            else if (Dan[2].getBackMid() == nameS) {
                Dan[2].setBackMid("X");

            }

            else if (Dan[2].getBackLeft() == nameS) {
                Dan[2].setBackLeft("X");

            }

            else if (Dan[2].getBackRight() == nameS) {
                Dan[2].setBackRight("X");

            }

            //RED
            else if (Pact[0].getFront() == nameS) {
                Pact[0].setFront("X");
            }

            else if (Pact[0].getBackLeft() == nameS) {
                Pact[0].setBackLeft("X");
            }

            else if (Pact[0].getBackRight() == nameS) {
                Pact[0].setBackRight("X");
            }

            //Blue

            else if (Pact[1].getFront() == nameS) {
                Pact[1].setFront("X");
            }

            else if (Pact[1].getBackLeft() == nameS) {
                Pact[1].setBackLeft("X");
            }

            else if (Pact[1].getBackRight() == nameS) {
                Pact[1].setBackRight("X");
            }

            //Yellow

            else if (Pact[2].getFront() == nameS) {
                Pact[2].setFront("X");
            }

            else if (Pact[2].getBackLeft() == nameS) {
                Pact[2].setBackLeft("X");
            }

            else if (Pact[2].getBackRight() == nameS) {
                Pact[2].setBackRight("X");
            }



            cout << "\nReservation removed.\n";
            cout << "------------------------" << endl;
            break; }

        case 4: {
            //ends program
            cout << endl;
            cout << "Display Vehicles";
            for (int i = 0; i < 3; i++)
            {
                Truck[i].displayPickup();
            }
            for (int i = 0; i < 3; i++)
            {
                Pact[i].displayCompact();
            }
            for (int i = 0; i < 3; i++)
            {
                Dan[i].displaySedan();
            }

            break; }
        case 5: {
            cout << "Print Vehicle Assignments" << endl;
            cout << "--------------------------" << endl;
            string carColor, vehicleType;
            ofstream outputFile;
            OpenOutputFile(outputFile, carColor, vehicleType);
            if (outputFile.is_open()) {
                outputFile << "Passenger List for " << carColor << " " << vehicleType << " : \n";
                cout << "Passenger List for " << carColor << " " << vehicleType << " : \n";
                outputFile << "-------------------------------------------------------\n";
                cout << "------------------------------------------------------- \n";
                if (vehicleType == "pickup") {
                    if (carColor == "purple") {

                        outputFile << "Driver: " << Truck[0].getDriver() << endl;
                        cout << "Driver: " << Truck[0].getDriver() << endl;
                        outputFile << "Front seat: " << Truck[0].getFront() << endl;
                        cout << "Front seat: " << Truck[0].getFront() << endl;
                        outputFile << "-------------------------------------------------------\n";
                        cout << "-------------------------------------------------------\n";

                    }
                    else if (carColor == "green") {

                        outputFile << "Driver: " << Truck[1].getDriver() << endl;
                        cout << "Driver: " << Truck[1].getDriver() << endl;
                        outputFile << "Front seat: " << Truck[1].getFront() << endl;
                        cout << "Front seat: " << Truck[1].getFront() << endl;
                        outputFile << "-------------------------------------------------------\n";
                        cout << "-------------------------------------------------------\n";

                    }
                    else if (carColor == "black") {

                        outputFile << "Driver: " << Truck[2].getDriver() << endl;
                        cout << "Driver: " << Truck[2].getDriver() << endl;
                        outputFile << "Front seat: " << Truck[2].getFront() << endl;
                        cout << "Front seat: " << Truck[2].getFront() << endl;
                        outputFile << "-------------------------------------------------------\n";
                        cout << "-------------------------------------------------------\n";

                    }
                    else {
                        cout << "Unknown error. Color does not match a vehicle.";
                    }
                }
                else if (vehicleType == "compact") {
                    if (carColor == "red") {

                        outputFile << "Driver: " << Pact[0].getDriver() << endl;
                        cout << "Driver: " << Pact[0].getDriver() << endl;
                        outputFile << "Front seat: " << Pact[0].getFront() << endl;
                        cout << "Front seat: " << Pact[0].getFront() << endl;
                        outputFile << "BackLeft: " << Pact[0].getBackLeft() << endl;
                        cout << "BackLeft: " << Pact[0].getBackLeft() << endl;
                        outputFile << "BackRight: " << Pact[0].getBackRight() << endl;
                        cout << "BackRight: " << Pact[0].getBackRight() << endl;
                        outputFile << "-------------------------------------------------------\n";
                        cout << "-------------------------------------------------------\n";

                    }
                    else if (carColor == "blue") {

                        outputFile << "Driver: " << Pact[1].getDriver() << endl;
                        cout << "Driver: " << Pact[1].getDriver() << endl;
                        outputFile << "Front seat: " << Pact[1].getFront() << endl;
                        cout << "Front seat: " << Pact[1].getFront() << endl;
                        outputFile << "BackLeft: " << Pact[1].getBackLeft() << endl;
                        cout << "BackLeft: " << Pact[1].getBackLeft() << endl;
                        outputFile << "BackRight: " << Pact[1].getBackRight() << endl;
                        cout << "BackRight: " << Pact[1].getBackRight() << endl;
                        outputFile << "-------------------------------------------------------\n";
                        cout << "-------------------------------------------------------\n";

                    }
                    else if (carColor == "yellow") {

                        outputFile << "Driver: " << Pact[2].getDriver() << endl;
                        cout << "Driver: " << Pact[2].getDriver() << endl;
                        outputFile << "Front seat: " << Pact[2].getFront() << endl;
                        cout << "Front seat: " << Pact[2].getFront() << endl;
                        outputFile << "BackLeft: " << Pact[2].getBackLeft() << endl;
                        cout << "BackLeft: " << Pact[2].getBackLeft() << endl;
                        outputFile << "BackRight: " << Pact[2].getBackRight() << endl;
                        cout << "BackRight: " << Pact[2].getBackRight() << endl;
                        outputFile << "-------------------------------------------------------\n";
                        cout << "-------------------------------------------------------\n";

                    }
                    else {
                        cout << "Unknown error. Color does not match a vehicle.";
                    }

                }
                else if (vehicleType == "sedan") {
                    if (carColor == "blue") {

                        outputFile << "Driver: " << Dan[0].getDriver() << endl;
                        cout << "Driver: " << Dan[0].getDriver() << endl;
                        outputFile << "Front seat: " << Dan[0].getFront() << endl;
                        cout << "Front seat: " << Dan[0].getFront() << endl;
                        outputFile << "BackLeft: " << Dan[0].getBackLeft() << endl;
                        cout << "BackLeft: " << Dan[0].getBackLeft() << endl;
                        outputFile << "BackMid: " << Dan[0].getBackMid() << endl;
                        cout << "BackMid: " << Dan[0].getBackMid() << endl;
                        outputFile << "BackRight: " << Dan[0].getBackRight() << endl;
                        cout << "BackRight: " << Dan[0].getBackRight() << endl;
                        outputFile << "-------------------------------------------------------\n";
                        cout << "-------------------------------------------------------\n";

                    }
                    else if (carColor == "black") {

                        outputFile << "Driver: " << Dan[1].getDriver() << endl;
                        cout << "Driver: " << Dan[1].getDriver() << endl;
                        outputFile << "Front seat: " << Dan[1].getFront() << endl;
                        cout << "Front seat: " << Dan[1].getFront() << endl;
                        outputFile << "BackLeft: " << Dan[1].getBackLeft() << endl;
                        cout << "BackLeft: " << Dan[1].getBackLeft() << endl;
                        outputFile << "BackMid: " << Dan[1].getBackMid() << endl;
                        cout << "BackMid: " << Dan[1].getBackMid() << endl;
                        outputFile << "BackRight: " << Dan[1].getBackRight() << endl;
                        cout << "BackRight: " << Dan[1].getBackRight() << endl;
                        outputFile << "-------------------------------------------------------\n";
                        cout << "-------------------------------------------------------\n";

                    }
                    else if (carColor == "green") {

                        outputFile << "Driver: " << Dan[2].getDriver() << endl;
                        cout << "Driver: " << Dan[2].getDriver() << endl;
                        outputFile << "Front seat: " << Dan[2].getFront() << endl;
                        cout << "Front seat: " << Dan[2].getFront() << endl;
                        outputFile << "BackLeft: " << Dan[2].getBackLeft() << endl;
                        cout << "BackLeft: " << Dan[2].getBackLeft() << endl;
                        outputFile << "BackMid: " << Dan[2].getBackMid() << endl;
                        cout << "BackMid: " << Dan[2].getBackMid() << endl;
                        outputFile << "BackRight: " << Dan[2].getBackRight() << endl;
                        cout << "BackRight: " << Dan[2].getBackRight() << endl;
                        outputFile << "-------------------------------------------------------\n";
                        cout << "-------------------------------------------------------\n";

                    }
                    else {
                        cout << "Unknown error. Color does not match a vehicle.";
                    }
                }
                else {
                    cout << "Unknown error. Vehicle does not exits.";
                }
            }
            else {
                cout << "\nUnable to open file.\n";
            }
            outputFile.close();
            break; }
        case 6: {
            //ends program
            cout << "6. Print Reservations " << endl;
            cout << "------------------------" << endl;

            string PASSword = "Arhect";
            cout << "------------------------\n";
            cout << "Administrator Password: ";
            cin >> PASSword;
            if (PASSword == "Arhect") {
                ofstream outputResFile = openResFile();
                //clears vectors before populating  
                purplePickup.clear();
                greenPickup.clear();
                blackPickup.clear();
                redCompact.clear();
                blueCompact.clear();
                yellowCompact.clear();
                blueSedan.clear();
                blackSedan.clear();
                greenSedan.clear();

                // vector<reservation> reserved;
                for (int g = 0; g < reserved.size(); ++g) {
                    if (reserved.at(g).get_carType() == "Pickup") {
                        if (reserved.at(g).get_carColor() == "Purple") {
                            purplePickup.push_back(reserved[g]);
                        }
                        else if (reserved.at(g).get_carColor() == "Green") {
                            greenPickup.push_back(reserved[g]);
                        }
                        else if (reserved.at(g).get_carColor() == "Black") {
                            blackPickup.push_back(reserved[g]);
                        }
                        //else {
                          //  cout << "\nError sorting Pickup reservations by color\n";
                        //}
                    }
                    else if (reserved.at(g).get_carType() == "Sedan") {
                        if (reserved.at(g).get_carColor() == "Blue") {
                            blueSedan.push_back(reserved[g]);
                        }
                        else if (reserved.at(g).get_carColor() == "Black") {
                            blackSedan.push_back(reserved[g]);
                        }
                        else if (reserved.at(g).get_carColor() == "Green") {
                            greenSedan.push_back(reserved[g]);
                        }
                        //else {
                          //  cout << "\nError sorting Sedan reservations by color\n";
                        //}
                    }
                    else if (reserved.at(g).get_carType() == "Compact") {
                        if (reserved.at(g).get_carColor() == "Red") {
                            redCompact.push_back(reserved[g]);
                        }
                        else if (reserved.at(g).get_carColor() == "Blue") {
                            blueCompact.push_back(reserved[g]);
                        }
                        else if (reserved.at(g).get_carColor() == "Yellow") {
                            yellowCompact.push_back(reserved[g]);
                        }
                       // else {
                         //   cout << "\nError sorting Compact reservations by color\n";
                        //}
                    }
                    //else {
                      //  cout << "\nError sorting reservations by Vehicle\n";
                    //}
                }// end of looping through reservations vector

                outputResFile << "\nVehicle assignment List for Purple Pick-up\n";
                cout << "Vehicle assignment List for Purple Pick-up\n";
                outputResFile << "----------------------------------------------------\n";
                cout << "----------------------------------------------------\n";
                outputResFile << "Driver: Pat \n";
                cout << "Driver: Pat \n";

                for (int l = 0; l < purplePickup.size(); ++l) {
                    outputResFile << "Name: " << purplePickup.at(l).getName() << " Location: " << purplePickup.at(l).getSeat() << endl;
                    cout << "Name: " << purplePickup.at(l).getName() << " Location: " << purplePickup.at(l).getSeat() << endl;
                }

                outputResFile << "----------------------------------------------------\n";
                cout << "----------------------------------------------------\n";

                outputResFile << "Vehicle assignment List for Green Pick-up\n";
                cout << "Vehicle assignment List for Green Pick-up\n";
                outputResFile << "----------------------------------------------------\n";
                cout << "----------------------------------------------------\n";
                outputResFile << "Driver: Jane \n";
                cout << "Driver: Jane \n";
                for (int l = 0; l < greenPickup.size(); ++l) {
                    outputResFile << "Name: " << greenPickup.at(l).getName() << " Location: " << greenPickup.at(l).getSeat() << endl;
                    cout << "Name: " << greenPickup.at(l).getName() << " Location: " << greenPickup.at(l).getSeat() << endl;
                }

                outputResFile << "----------------------------------------------------\n";
                cout << "----------------------------------------------------\n";

                outputResFile << "Vehicle assignment List for Black Pick-up\n";
                cout << "Vehicle assignment List for Black Pick-up\n";
                outputResFile << "----------------------------------------------------\n";
                cout << "----------------------------------------------------\n";
                outputResFile << "Driver: Tim \n";
                cout << "Driver: Tim \n";
                for (int l = 0; l < blackPickup.size(); ++l) {
                    outputResFile << "Name: " << blackPickup.at(l).getName() << " Location: " << blackPickup.at(l).getSeat() << endl;
                    cout << "Name: " << blackPickup.at(l).getName() << " Location: " << blackPickup.at(l).getSeat() << endl;
                }

                outputResFile << "----------------------------------------------------\n";
                cout << "----------------------------------------------------\n";

                outputResFile << "Vehicle assignment List for Red Pick-up\n";
                cout << "Vehicle assignment List for Red Compact\n";
                outputResFile << "----------------------------------------------------\n";
                cout << "----------------------------------------------------\n";
                outputResFile << "Driver: Ben \n";
                cout << "Driver: Ben \n";
                for (int l = 0; l < redCompact.size(); ++l) {
                    outputResFile << "Name: " << redCompact.at(l).getName() << " Location: " << redCompact.at(l).getSeat() << endl;
                    cout << "Name: " << redCompact.at(l).getName() << " Location: " << redCompact.at(l).getSeat() << endl;
                }

                outputResFile << "----------------------------------------------------\n";
                cout << "----------------------------------------------------\n";

                outputResFile << "Vehicle assignment List for Blue Pick-up\n";
                cout << "Vehicle assignment List for Blue Compact\n";
                outputResFile << "----------------------------------------------------\n";
                cout << "----------------------------------------------------\n";
                outputResFile << "Driver: Art \n";
                cout << "Driver: Art \n";
                for (int l = 0; l < blueCompact.size(); ++l) {
                    outputResFile << "Name: " << blueCompact.at(l).getName() << " Location: " << blueCompact.at(l).getSeat() << endl;
                    cout << "Name: " << blueCompact.at(l).getName() << " Location: " << blueCompact.at(l).getSeat() << endl;
                }

                outputResFile << "----------------------------------------------------\n";
                cout << "----------------------------------------------------\n";

                outputResFile << "Vehicle assignment List for Yellow Pick-up\n";
                cout << "Vehicle assignment List for Yellow Compact\n";
                outputResFile << "----------------------------------------------------\n";
                cout << "----------------------------------------------------\n";
                outputResFile << "Driver: Ann \n";
                cout << "Driver: Ann \n";
                for (int l = 0; l < yellowCompact.size(); ++l) {
                    outputResFile << "Name: " << yellowCompact.at(l).getName() << " Location: " << yellowCompact.at(l).getSeat() << endl;
                    cout << "Name: " << yellowCompact.at(l).getName() << " Location: " << yellowCompact.at(l).getSeat() << endl;
                }

                outputResFile << "----------------------------------------------------\n";
                cout << "----------------------------------------------------\n";

                outputResFile << "Vehicle assignment List for Blue Pick-up\n";
                cout << "Vehicle assignment List for Blue Sedan\n";
                outputResFile << "----------------------------------------------------\n";
                cout << "----------------------------------------------------\n";
                outputResFile << "Driver: Grace \n";
                cout << "Driver: Grace \n";
                for (int l = 0; l < blueSedan.size(); ++l) {
                    outputResFile << "Name: " << blueSedan.at(l).getName() << " Location: " << blueSedan.at(l).getSeat() << endl;
                    cout << "Name: " << blueSedan.at(l).getName() << " Location: " << blueSedan.at(l).getSeat() << endl;
                }

                outputResFile << "----------------------------------------------------\n";
                cout << "----------------------------------------------------\n";

                outputResFile << "Vehicle assignment List for Black Pick-up\n";
                cout << "Vehicle assignment List for Black Sedan\n";
                outputResFile << "----------------------------------------------------\n";
                cout << "----------------------------------------------------\n";
                outputResFile << "Driver: Lary \n";
                cout << "Driver: Lary \n";
                for (int l = 0; l < blackSedan.size(); ++l) {
                    outputResFile << "Name: " << blackSedan.at(l).getName() << " Location: " << blackSedan.at(l).getSeat() << endl;
                    cout << "Name: " << blackSedan.at(l).getName() << " Location: " << blackSedan.at(l).getSeat() << endl;
                }

                outputResFile << "----------------------------------------------------\n";
                cout << "----------------------------------------------------\n";

                outputResFile << "Vehicle assignment List for Green Pick-up\n";
                cout << "Vehicle assignment List for Green Sedan\n";
                outputResFile << "----------------------------------------------------\n";
                cout << "----------------------------------------------------\n";
                outputResFile << "Driver: Jessie \n";
                cout << "Driver: Jessie \n";
                for (int l = 0; l < greenSedan.size(); ++l) {
                    outputResFile << "Name: " << greenSedan.at(l).getName() << " Location: " << greenSedan.at(l).getSeat() << endl;
                    cout << "Name: " << greenSedan.at(l).getName() << " Location: " << greenSedan.at(l).getSeat() << endl;
                }

                outputResFile << "----------------------------------------------------\n";
                cout << "----------------------------------------------------\n";

                outputResFile.close();
            }
            else {
                cout << "Incorrect Admin Password.\n";
            }
            break; }
        case 7: {
            //ends program
            cout << "Option 7: Quitting Program......." << endl << endl;
            exit(0);
            break; }
        default:
            //defualt 
            cout << "Invalid choice. Please enter a number from 1 - 7";

        }



    } while (opt != '6');
}//main