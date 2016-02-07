#include "binarytreealgorithm.h"
#include <math.h>
#include <sstream>
using namespace std;
#define PI 3.14159265

BinaryTreeAlgorithm::BinaryTreeAlgorithm(void)
{
}
BinaryTreeAlgorithm::~BinaryTreeAlgorithm(void)
{
    for ( int i = 0; i < (int) treeNodes.size(); ++i )
    {
        TreeNodeItem* item = treeNodes.top();
        treeNodes.pop();
        delete item;
    }
    return;
}

double BinaryTreeAlgorithm::GetExpressionResult()
{
    if(treeNodes.size() == 0)
    {
        HandleError("Irregular expression. This is no first node element in binary tree!!! ");
    }
    TreeNodeItem* firstNode = treeNodes.top();
    treeNodes.pop();

    return RunRecurcion(*firstNode);
}

void BinaryTreeAlgorithm::Create(vector<string> RPNstring)
{
    for ( int i = 0; i < (int) RPNstring.size(); ++i )
    {
        if (IsTokenDigit(RPNstring[i]))
        {
            treeNodes.push(create_node(RPNstring[i]));
        }
        else if (IsTokenOperator(RPNstring[i]) || RPNstring[i].compare("max")==0)
        {
            TreeNodeItem* node= create_node(RPNstring[i]);
            if(!(treeNodes.size() < 2))
            {
                node->rightNode= treeNodes.top();
                treeNodes.pop();
                node->leftNode= treeNodes.top();
                treeNodes.pop();
                treeNodes.push(node);
           }
           else
           {
                HandleError("Irregular expression. Error ocurance in tree operator building!!! ");
           }
        }
        else if (IsTokenFunction(RPNstring[i]))
        {
            if(!treeNodes.size() == 0)
            {
                TreeNodeItem* node= create_node(RPNstring[i]);
                node->leftNode = treeNodes.top();
                treeNodes.pop();

                treeNodes.push(node);
            }
            else
            {
                HandleError("Irregular expression. Error ocurance in tree function building!!! ");
            }
        }
    }
}

TreeNodeItem* BinaryTreeAlgorithm::create_node(string t) {
    TreeNodeItem* n = (TreeNodeItem*)malloc(sizeof(TreeNodeItem));
    TreeNodeItem* newClass = new (n) TreeNodeItem();
    if (IsTokenDigit(t))
    {
        replace(t.begin(), t.end(), ',','.');
        newClass->value = stod(t);
        newClass->mathExpession = "";
    }
    else
    {
        newClass->mathExpession = t;
        newClass->value=0;
    }
    newClass->leftNode = newClass->rightNode = 0;
    return newClass;
}

double BinaryTreeAlgorithm::RunRecurcion(TreeNodeItem node)
{
    if(node.mathExpession.compare("+")==0)
    {
     return RunRecurcion(*node.leftNode) + RunRecurcion(*node.rightNode);
    }
    else if(node.mathExpession.compare("-")==0)
    {
      return RunRecurcion(*node.leftNode) - RunRecurcion(*node.rightNode);
    }
    else if(node.mathExpession.compare("/")==0)
    {
      return RunRecurcion(*node.leftNode) / RunRecurcion(*node.rightNode);
    }
    else if(node.mathExpession.compare("*")==0)
    {
      return RunRecurcion(*node.leftNode) * RunRecurcion(*node.rightNode);
    }
    else if(node.mathExpession.compare("sin")==0)
    {
       return sin(RunRecurcion(*node.leftNode)*PI/180);
    }
    else if(node.mathExpession.compare("cos")==0)
    {
       return cos(RunRecurcion(*node.leftNode)*PI/180);
    }
    else if(node.mathExpession.compare("sqrt")==0)
    {
        return sqrt(RunRecurcion(*node.leftNode));
    }
    else if(node.mathExpession.compare("^")==0)
    {
       return pow(RunRecurcion(*node.leftNode), RunRecurcion(*node.rightNode));
    }
    else if(node.mathExpession.compare("max")==0)
    {
     return max(RunRecurcion(*node.leftNode), RunRecurcion(*node.rightNode));
    }
    else if(node.mathExpession.compare("tan")==0)
    {
    return tan(RunRecurcion(*node.leftNode)*PI/180);
    }
    else
    {
      return node.value;
    }
}


