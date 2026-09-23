#include <stdio.h>

int main(void)
{
    double temperature;
    double celsius;
    double convertedTemperature;
    char inputScale;
    char outputScale;
    printf("Enter the temperature value: ");
    if (scanf("%lf", &temperature) != 1) {
        printf("Invalid temperature. Please enter a number.\n");
        return 1;
    }
    printf("Enter the original scale (C, F, or K): ");
    if (scanf(" %c", &inputScale) != 1) {
        return 1;
    }
    printf("Enter the scale to convert to (C, F, or K): ");
    if (scanf(" %c", &outputScale) != 1) {
        return 1;
    }

    if (inputScale == 'c') inputScale = 'C';
    if (inputScale == 'f') inputScale = 'F';
    if (inputScale == 'k') inputScale = 'K';
    if (outputScale == 'c') outputScale = 'C';
    if (outputScale == 'f') outputScale = 'F';
    if (outputScale == 'k') outputScale = 'K';

    if ((inputScale != 'C' && inputScale != 'F' && inputScale != 'K') ||
        (outputScale != 'C' && outputScale != 'F' && outputScale != 'K')) {
        printf("Invalid scale. Use C, F, or K.\n");
        return 1;
    }

    if (inputScale == 'C') {
        celsius = temperature;
    } else if (inputScale == 'F') {
        celsius = (temperature - 32) * 5 / 9;
    } else {
        celsius = temperature - 273.15;
    }

    if (celsius < -273.15) {
        printf("Invalid temperature. It cannot be below absolute zero.\n");
        return 1;
    }

    if (outputScale == 'C') {
        convertedTemperature = celsius;
    } else if (outputScale == 'F') {
        convertedTemperature = celsius * 9 / 5 + 32;
    } else {
        convertedTemperature = celsius + 273.15;
    }

    printf("Converted temperature: %.2f %c\n", convertedTemperature, outputScale);

    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a warm jacket.\n");
    } else if (celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Enjoy the comfortable weather!\n");
    } else if (celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors if possible and avoid too much sun.\n");
    }

    return 0;
}