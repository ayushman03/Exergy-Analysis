#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double W_out; // Output work in kW
    double Q_in ; // Heat input in kW
    double T_amb; // Ambient temperature in °C

    double n = 1.4; // Polytropic index of air
    double R = 287; // Gas constant of air in J/kg-K

    double Cp = 1.5*1000; // Specific heat capacity of gasoline in J/kg-K
    double HV = 45*1000; // Heating value of gasoline in J/kg

    double T_in, T_out, h_in, h_out, h_amb, s_in, s_out, s_amb, X_in, X_out, X;
    double p_in; // Inlet pressure in bar
    double p_out; // Outlet pressure in bar
    double p_amb; // Ambient pressure in bar
    cout<<"\nEnter Inlet pressure in bar : ";
    cin>>p_in;
    cout<<"\nEnter Outlet pressure in bar : ";
    cin>>p_out;
    cout<<"\nEnter Ambient pressure in bar : ";
    cin>>p_amb;
    cout<<"\nEnter Heat Input in kW : ";
    cin>>Q_in;
    cout<<"\nEnter Output Work in kW : ";
    cin>>W_out;
    cout<<"\nEnter Ambient temperature in celsius : ";
    cin>>T_amb;
    cout<<"\nData Assumed: "<<endl;
    cout<<"\nPolytropic index of air : "<<n<<endl;
    cout<<"\nGas constant of air : "<<R<<" J/kg-K"<<endl;
    cout<<"\nSpecific heat capacity of gasoline : "<<Cp<<" J/kg-K"<<endl;
    cout<<"\nHeating value of gasoline : "<<HV<<" J/kg" <<endl;

    // Convert pressure values from bar to Pa
    p_in *= 1e5;
    p_out *= 1e5;
    p_amb *= 1e5;

    // Calculate the temperature of the air entering and leaving the engine
    T_in = T_amb + Q_in / (W_out + Q_in) * (1250 - T_amb);
    T_out = T_in - W_out / Q_in * (T_in - T_amb);

    // Calculate the specific enthalpy of the air at each state
    h_in = Cp * T_in;
    h_out = Cp * T_out;
    h_amb = Cp * T_amb;

    // Calculate the specific entropy of the air at each state
    s_in = Cp * log(T_in/T_amb) - R * log(p_in/p_amb);
    s_out = Cp * log(T_out/T_amb) - R * log(p_out/p_amb);
    s_amb = Cp * log(T_amb/T_amb) - R * log(p_amb/p_amb);

    // Calculate the exergy at each state
    X_in = h_in - h_amb - T_amb * (s_in - s_amb);
    X_out = h_out - h_amb - T_amb * (s_out - s_amb);

    // Calculate the exergy efficiency
    X = (X_in - X_out) / X_in;

    cout << "\nExergy Efficiency: " << X << endl;

    return 0;
}
