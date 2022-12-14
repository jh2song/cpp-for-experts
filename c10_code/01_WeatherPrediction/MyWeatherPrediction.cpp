#include <iostream>

#include "MyWeatherPrediction.h"

using namespace std;

void MyWeatherPrediction::setCurrentTempCelsius(int temp)
{
	int fahrenheitTemp = convertCelsiusToFahrenheit(temp);
	setCurrentTempFahrenheit(fahrenheitTemp);
}

int MyWeatherPrediction::getTomorrowTempCelsius() const
{
	int fahrenheitTemp = getTomorrowTempFahrenheit();
	return convertFahrenheitToCelsius(fahrenheitTemp);
}

void MyWeatherPrediction::showResult() const
{
	cout << "Tomorrow's temperature will be " <<
		getTomorrowTempCelsius() << " degrees Celsius (" <<
		getTomorrowTempFahrenheit() << " degrees Fahrenheit)" << endl;

	cout << "The chance of rain is " << (getChanceOfRain() * 100) << " percent"
		<< endl;

	if (getChanceOfRain() > 0.5) {
		cout << "Bring an umbrella!" << endl;
	}
}

int MyWeatherPrediction::convertCelsiusToFahrenheit(int celsius)
{
	return static_cast<int>((9.0 / 5.0) * celsius + 32);
}

int MyWeatherPrediction::convertFahrenheitToCelsius(int fahrenheit)
{
	return static_cast<int>((5.0 / 9.0) * (fahrenheit - 32));
}

string MyWeatherPrediction::getTemperature() const
{
	// 화씨 기호를 추가한다.
	// 참고: \u00B0는 ISO/IEC 10646 표준의 온도 기호다.
	return WeatherPrediction::getTemperature() + "\u00B0F";
	//return __super::getTemperature() + "\u00B0F"; // MS VC++
}


int main()
{
	MyWeatherPrediction p;
	p.setCurrentTempCelsius(33);
	p.setPositionOfJupiter(80);
	p.showResult();
	cout << p.getTemperature() << endl;
	return 0;
}
