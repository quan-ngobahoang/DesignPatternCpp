#include <iostream>
#include <string>
#include <vector>

using namespace std;
class ICommand
{
public:
    virtual ~ICommand() {}
    virtual void execute() = 0;
};

class LogCommand : public ICommand
{
private:
    string _pay_load;

public:
    LogCommand(string pay_load) : _pay_load(pay_load) {}
    void execute() override
    {
        cout << "Logging: " << _pay_load << endl;
    }
};

class Receiver
{
public:
    void ProcessBtnAudio(const string &pData)
    {
        cout << "Receiver Audio: " << pData << endl;
    }
    void ProcessBTVehicle(const string &pConnectivity)
    {
        cout << "Receiver Connectivity: " << pConnectivity << endl;
    }
};

class ComplexCommand : public ICommand
{
private:
    Receiver *receiver;
    string pData_Details;
    string pConnectivity_Details;

public:
    ComplexCommand(Receiver *receiver, string pData_Details, string pConnectivity_Details) : receiver(receiver), pData_Details(pData_Details), pConnectivity_Details(pConnectivity_Details) {}

    void execute() override
    {
        receiver->ProcessBtnAudio(pData_Details);
        receiver->ProcessBTVehicle(pConnectivity_Details);
    }
};

int main(int argc, char *argv[])
{
    LogCommand lc("USB_SUCCESS:MESSAGE_SEND");
    lc.execute();

    Receiver rec;
    ComplexCommand cc(&rec, "audioOn", "connectivitySuccess");
    cc.execute();
}