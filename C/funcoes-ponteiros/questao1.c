// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>

void converterCelsius(float celsius, float *fahrenheit, float *kelvin) {
    *fahrenheit = celsius * 9 / 5 + 32;
    *kelvin = celsius + 273.15;
};

int main () {
    float celsius, fahrenheit, kelvin;
    printf("\nDigite a temperatura em Celsius: ");
    scanf("%f", &celsius);

    converterCelsius(celsius, &fahrenheit, &kelvin);

    printf("\nFahrenheit: %.2f", fahrenheit);
    printf("\nKelvin: %.2f\n\n", kelvin);

    return 0;
};