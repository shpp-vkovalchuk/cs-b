#ifndef TREENODEITEM_H
#define TREENODEITEM_H
#include <string>

class TreeNodeItem
{
public:
    TreeNodeItem(void);
    ~TreeNodeItem(void);

    TreeNodeItem(std::string &expr)
    {
        mathExpession=expr;
    }
    double value;
    std::string mathExpession;
    TreeNodeItem* leftNode;
    TreeNodeItem* rightNode;
};

#endif // TREENODEITEM_H
