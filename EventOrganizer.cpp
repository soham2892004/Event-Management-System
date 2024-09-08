#include <iostream>


using namespace std;

class EventManagement
 {
public:
    //constructer Initialize Data Members
    EventManagement(string event_name, string first_name, string last_name, int num_guests, int duration_minutes) {
        this->event_name = event_name;
        this->first_name = first_name;
        this->last_name = last_name;
        this->num_guests = num_guests;
        this->duration_minutes = duration_minutes;
    }

    void calculation() {
        //constant variables for fix value cost calculation
        const double CostPerHour = 18.50;
        const double CostPerMinute = 0.40;
        const double CostOfDinner = 20.70;

        //calculate number of server
        int numberOfServers = num_guests / 20;

        //calculate cost for one server
        double CostForOneServer = (duration_minutes / 60) * CostPerHour + (duration_minutes % 60) * CostPerMinute;

        //calculate total food cost
        double TotalFoodCost = num_guests * CostOfDinner;

        //calculate average cost for person
        double AverageCost = TotalFoodCost / num_guests;

        //calculate total cost for event
        double TotalCost = TotalFoodCost + (CostForOneServer * numberOfServers);

        //calculate deposit amount(it's 25% of total cost)
        double DepositAmount = TotalCost * 0.25;

        //display event's all details and costs
        cout<<"\n=================Event Details:===================";
        cout << "\n->Event Name:" << event_name << endl;
        cout << "\n->Organizer:" << first_name << " " << last_name << endl;
        cout << "\n->Number of Guests:" << num_guests << endl;
        cout << "\n->Duration (minutes):" << duration_minutes << endl;
        cout << "\n->Number of Servers:" << numberOfServers << endl;
        cout << "\n->Cost per Server:" << CostForOneServer << endl;
        cout << "\n->Total Food Cost:" << TotalFoodCost << endl;
        cout << "\n->Average Cost per Person:" << AverageCost << endl;
        cout << "\n->Total Cost:" << TotalCost << endl;
        cout << "\n->Deposit Amount:" << DepositAmount << endl;
    }

private:
    string event_name;
    string first_name;
    string last_name;
    int num_guests;
    int duration_minutes;
};

int main() {
    string event_name, first_name, last_name;
    int num_guests, duration_minutes;
    cout<<"--------------------Event Managament System-------------------------";

    //input value event name,first and last name for customer,number of guest,number of minutes
    cout << "\nEnter the name of the event: ";
    cin>>event_name;

    cout << "Enter customer's first name: ";
    cin>>first_name;

    cout << "Enter customer's last name: ";
    cin>>last_name;

    cout << "Enter the number of guests: ";
    cin >> num_guests;

    cout << "\nEnter the number of minutes in the event: ";
    cin >> duration_minutes;

    //create an EventManagement instance and calculation for all cost
    EventManagement event(event_name, first_name, last_name, num_guests, duration_minutes);
    event.calculation();

    return 0;
}
