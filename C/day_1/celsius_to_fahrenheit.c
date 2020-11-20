#include <stdio.h>

/*
 * print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300
 */

float convertTemperature(float lower, float upper, float step, float (*convert) (float));
float convertFahrenheitToCelsius(float fahrenheitTemperature);
float convertCelsiusToFahrenheit(float celsiusTemperature);
float convertKelvinToCelsius(float kelvinTemperature);

int main()
{
	float fahr, celsius;
    float lower, upper, step;

	lower = 0; /* lower limit of temperature scale */
	upper = 300; /* upper limit  */
	
	step = 20; /* step size */

	printf("Conversion from Fahrenheit to Celsius\n%20s\n", "--------------------");
	convertTemperature(lower, upper, step, convertFahrenheitToCelsius);

	printf("\nConversion from Celsius to Fahrenheit\n%20s\n", "--------------------");
	convertTemperature(lower, upper, step, convertCelsiusToFahrenheit);

	printf("\nConversion from Kelvin to Celsius\n%20s\n", "--------------------");
	convertTemperature(lower, upper, step, convertKelvinToCelsius);
}

float convertTemperature(float lower, float upper, float step, float (*convert) (float))
{
	float result;
	float low = lower;

	while (low <= upper)
	{
		result = (* convert)(low);
		printf("%3.0f\t%6.1f\n", low, result);
	    
		low = low + step;	
	}

	return result;
}

float convertFahrenheitToCelsius(float fahrenheitTemperature)
{
	return (5.0 / 9.0) * (fahrenheitTemperature - 32.0); 
}

float convertCelsiusToFahrenheit(float celsiusTemperature)
{
	return (9.0 / 5.0) * celsiusTemperature + 32.0;
}

float convertKelvinToCelsius(float kelvinTemperature)
{
	return kelvinTemperature - 273.15;
}
