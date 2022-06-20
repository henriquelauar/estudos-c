// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>

void converterRad(float graus1, float *radiano1) {
    float pi = 3.141592;

    *radiano1 = (graus1 * pi) / 180;
}

void converterGraus (float radiano2, float *graus2) {
    float pi = 3.14159265359;

    *graus2 = (radiano2 * 180) / pi;
}    

void CelsiusFahrenheit(float celsius1, float *fahrenheit1) {
    *fahrenheit1 = celsius1 * 9/5 + 32;
};

void CelsiusKelvin(float celsius1, float *kelvin1) {
    *kelvin1 = celsius1 + 273.15;
};    

void FahrenheitCelsius(float fahrenheit2, float *celsius2) {
    *celsius2 = (fahrenheit2 - 32) * 5/9;
};

void FahrenheitKelvin(float fahrenheit2, float *kelvin2) {
    *kelvin2 = (fahrenheit2 - 32) * 5/9 + 273.15;
};

void converterKelvin(float kelvin3, float *celsius3, float *fahrenheit3) {
    *celsius3 = kelvin3 - 273.15;
    *fahrenheit3 = (kelvin3 - 273.15) * 9/5 + 32;
}

int main () {
    int opcao1, opcao2, opcao3;
    float celsius1, fahrenheit1, kelvin1, celsius2, fahrenheit2, kelvin2, celsius3, fahrenheit3, kelvin3;
    float graus1, radiano1, graus2, radiano2;

    printf("\n### CONVERSOR DE UNIDADES ###\n\n1) Ângulo\n2) Temperatura\n");

    printf("\nDigite uma opção: ");
    scanf("%d", &opcao1);
    
    switch(opcao1) {
        case 1:
            printf("\nQual a unidade de origem?\n\n1) Graus\n2) Radianos\n");
            printf("\nSelecione uma opção: ");
            scanf("%d", &opcao2);
        break;
        case 2:
            printf("\nQual a unidade de origem?\n\n1) Celsius\n2) Fahrenheit\n3) Kelvin");
            printf("\n\nSelecione uma opção: ");
            scanf("%d", &opcao3);
        break;
    };

    switch(opcao2) {
        case 1:
            printf("\nDigite o valor em Graus: ");
            scanf("%f", &graus1);
            converterRad(graus1, &radiano1);
            printf("\nValor em radianos: %f\n", radiano1);
        break;
        case 2:
            printf("\nDigite o valor em Radianos: ");
            scanf("%f", &radiano2);
            converterGraus(radiano2, &graus2);
            printf("\nValor em graus: %f\n", graus2);
        break;
    };

    if (opcao1 == 2) {
        switch(opcao3) {
            case 1:
                printf("\nDigite o valor em Celsius: ");
                scanf("%f", &celsius1);
                CelsiusFahrenheit(celsius1, &fahrenheit1);
                CelsiusKelvin(celsius1, &kelvin1);
                printf("\nValor em Fahrenheit: %f\n", fahrenheit1);
                printf("\nValor em Kelvin: %f\n", kelvin1);
            break;
            case 2:
                printf("\nDigite o valor em Fahrenheit: ");
                scanf("%f", &fahrenheit2);
                FahrenheitCelsius(fahrenheit2, &celsius2);
                FahrenheitKelvin(fahrenheit2, &kelvin2);
                printf("\nValor em Celsius: %f\n", celsius2);
                printf("\nValor em Kelvin: %f\n", kelvin2);
            break;
            case 3:
                printf("\nDigite o valor em Kelvin: ");
                scanf("%f", &kelvin3);
                converterKelvin(kelvin3, &celsius3, &fahrenheit3);
                printf("\nValor em Fahrenheit: %f\n", celsius3);
                printf("\nValor em Kelvin: %f\n", fahrenheit3);
            break;
        };
    }

    return 0;
}