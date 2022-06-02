/*
MIT License

Copyright (c) 2022 m!haly4

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "neuron.h"

int main()
{
    /*necessary values ​​for the training of neurons*/
    double price_determined_by_the_income_approach = 123500.20;
    double price_determined_by_a_comparative_approach = 121050.30;
    double price_determined_by_the_cost_approach = 118006.150;
    double the_amount_of_prices = 0;
    double expected_result = 120852.220;

    /*delimiter for menu*/
    char single_delimiter[] = "--------------------------------------------------------------------\n";

    /*setting neuron weight and smoothing*/
    struct Neuron neuron;
    neuron.weight = 0.50;
    neuron.smoothing = 0.001;

    the_amount_of_prices = price_determined_by_the_income_approach + 
                            price_determined_by_a_comparative_approach + 
                            price_determined_by_the_cost_approach;

    /*the process of training neurons*/
    int i = 0;
    do
    {
        ++i;

        train_neuron(expected_result, the_amount_of_prices, &neuron);

#ifdef test
            printf("Iteration: %i,\tError: %.6lf\n", i, neuron.last_error);
#endif

    } while ((neuron.last_error > neuron.smoothing) || (neuron.last_error < -neuron.smoothing));
    
    printf("\nNeuron training is complete\n\n");

    /*outputting the example*/
    printf("Example of determining the value of real estate: \n");
    printf("%.2lf - the price determined by the income approach\n%.2lf - the price is determined by a comparative approach\n%.2lf - the price is determined by the cost approach\nReal estate price: %.2lf\n\n", 
                                price_determined_by_the_income_approach,
                                price_determined_by_a_comparative_approach,
                                price_determined_by_the_cost_approach, 
                                program_input(price_determined_by_the_income_approach, price_determined_by_a_comparative_approach, price_determined_by_the_cost_approach, &neuron));

    /*menu*/
    int choise = 1;
    double value1, value2, value3;
    int scanning_value = 0;

    while(choise != 0)
    {
        printf("%s", single_delimiter);

        menu();
        printf("Your choise: ");
        scanning_value = scanf("%i", &choise);

        /*checking the correctness of the input*/
        if(scanning_value == 1)
        {
            printf("%s", single_delimiter);

            if(choise == 1)
            {
                printf("%s", single_delimiter);

                printf("Enter values:\n - the price determined by the income approach\n - the price is determined by a comparative approach\n - the price is determined by the cost approach\nInput one by one:\n");
                scanning_value = scanf("%lf%lf%lf", &value1, &value2, &value3);

                /*checking the correctness of the input*/
                if(scanning_value == 3)
                {
                    printf("%s", single_delimiter);
                    
                    /*outputting the result*/
                    printf("%.2lf - the price determined by the income approach\n%.2lf - the price is determined by a comparative approach\n%.2lf - the price is determined by the cost approach\nReal estate price: %.2lf\n\n", 
                                value1,
                                value2,
                                value3, 
                                program_input(value1, value2, value3, &neuron));;
                }
                else
                {
                    printf("Error: invalid input");
                }
            }
            else if(choise == 2)
            {
                printf("---> Creator of this program: git-user-cpp (m!haly4) <---\n"
                "     ---> Link: https://github.com/git-user-cpp <---\n"
                "---> License: https://github.com/git-user-cpp/neural_real_estate_appraisal_calculator/blob/main/LICENSE <---\n");
            }
        }
        else
        {
            printf("Error: invalid input");
        }
    }

    printf("The program is stopped\n");

    return 0;
}