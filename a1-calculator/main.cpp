#include <QCoreApplication>

#include "CalculatorSubtypes/calculator.h"
#include "CalculatorSubtypes/scientificcalculator.h"
#include "CalculatorSubtypes/standartcalculator.h"
#include <map>
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::map<std::string,double> parameters;
    try
    {
        std::cout<<"Enter parameters number : ";
        int parametersNumber = 0;
        std::cin >> parametersNumber;
        for (int i = 0; i < parametersNumber; i++)
        {
            std::cout << "Enter parameter name : ";
            std::string parametersName="";
            std::cin >> parametersName;
            std::cout<<"Enter parameter value : ";
            double parameterValue=0;
            std::cin >> parameterValue;
            parameters.insert(std::pair<std::string,double>(parametersName,parameterValue));
        }
        std::cout << "Enter expression : " << std::endl;
        std::string expression;
        std::cin >> expression;


        Calculator* calc =new ScientificCalculator(expression, parameters);
        std::vector<std::string> rpnExpression = calc->CalculateRPN();
        calc->CreateTree();
        double result = calc->CalculateMathematicalExpression();

        std::cout<<std::endl;
        std::cout<<"Result is = "<<result<< std::endl ;
        int b;
        std::cin>> b;
        delete calc;
    }
    catch(...)
    {
        std::perror("You shoud input valid data");
        return EXIT_FAILURE;
    }
    return a.exec();

}
