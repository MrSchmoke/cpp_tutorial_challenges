#include <iostream>
#include <cmath>

using namespace std;

double fahrenheit_to_celsius(double);
double fahrenheit_to_kelvin(double);
void temperature_conversion(double);

//declaring prototypes and functions - temperature conversions
int main1(){
    double fahrenheit_temperature {32.32};
    temperature_conversion(fahrenheit_temperature);

    return 0;
}

void temperature_conversion(double fahrenheit_temperature) {
    double celsius_temperature {fahrenheit_to_celsius(fahrenheit_temperature)};
    double kelvin_temperature {fahrenheit_to_kelvin(fahrenheit_temperature)};
    cout << "The fahrenheit temperature " << fahrenheit_temperature << " degrees is equivalent to " << celsius_temperature << " degrees celsius and " << kelvin_temperature << " degrees kelvin.";
}

double fahrenheit_to_celsius(double temperature) {
    return round((5.0/9.0)*(temperature-32));
}
double fahrenheit_to_kelvin(double temperature) {
    return round(fahrenheit_to_celsius(temperature)+273);
}
