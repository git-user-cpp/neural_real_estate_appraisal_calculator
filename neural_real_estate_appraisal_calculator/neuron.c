/*
MIT License

Copyright (c) 2022 Andrew Kushyk

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

/*menu function*/
void menu()
{
    printf("Choose an option:\n1) Determine the value of real estate\n2) Info about the creator and license\n0) Stop the program\n");
}

/*function for calculating the result*/
double program_input(double value1, double value2, double value3, struct Neuron *neuron)
{
    double input = value1 + value2 + value3;
    return input * neuron->weight;
}

/*function for neuron training*/
void train_neuron(double expected_result, double input, struct Neuron *neuron)
{
    double result = input * neuron->weight;
    neuron->last_error = expected_result - result;

    double corretion = (neuron->last_error / result) * neuron->smoothing;
    neuron->weight += corretion;
}
