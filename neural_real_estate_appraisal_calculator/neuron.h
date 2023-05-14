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

#include <stdio.h>
/*#define test*/ /*uncomment to see the neuron training process*/

/*Neuron struct*/
struct Neuron
{
    double weight;      /*variable to set the weight value*/
    double last_error;  /*variable to collect the error value*/
    double smoothing;   /*variable to set the smoothing value*/
};

/*menu function*/
void menu();

/*function for calculating the result*/
double program_input(double value1, double value2, double value3, struct Neuron *neuron);

/*function for neuron training*/
void train_neuron(double input, double expected_result, struct Neuron *neuron);
