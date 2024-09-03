#include <iostream>
#include <cmath>

using namespace std;

class EventOrganizer {
public:
    EventOrganizer(string event_name, string first_name, string last_name, int num_guests, int duration_minutes) {
        this->event_name = event_name;
        this->first_name = first_name;
        this->last_name = last_name;
        this->num_guests = num_guests;
        this->duration_minutes = duration_minutes;
    }

    void calculate_costs() {
        const double CostPerHour = 18.50;
        const double CostPerMinute = 0.40;
        const double CostOfDinner = 20.70;

        int numberOfServers = ceil((double)num_guests / 20);
        double CostForOneServer = (duration_minutes / 60) * CostPerHour + (duration_minutes % 60) * CostPerMinute;
        double TotalFoodCost = num_guests * CostOfDinner;
        double AverageCost = TotalFoodCost / num_guests;
        double TotalCost = TotalFoodCost + (CostForOneServer * numberOfServers);
        double DepositAmount = TotalCost * 0.25;

        cout<<"\n=================Event Details:===================";
        cout << "\n->Event Name:" << event_name << endl;
        cout << "->Organizer:" << first_name << " " << last_name << endl;
        cout << "->Number of Guests:" << num_guests << endl;
        cout << "->Duration (minutes):" << duration_minutes << endl;
        cout << "->Number of Servers:" << numberOfServers << endl;
        cout << "->Cost per Server:" << CostForOneServer << endl;
        cout << "->Total Food Cost:" << TotalFoodCost << endl;
        cout << "->Average Cost per Person:" << AverageCost << endl;
        cout << "->Total Cost:" << TotalCost << endl;
        cout << "->Deposit Amount:" << DepositAmount << endl;
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

    EventOrganizer event(event_name, first_name, last_name, num_guests, duration_minutes);
    event.calculate_costs();

    return 0;
}
