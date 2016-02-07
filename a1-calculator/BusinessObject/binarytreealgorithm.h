#ifndef BINARYTREEALGORITHM_H
#define BINARYTREEALGORITHM_H
#include <string>
#include <map>
#include "TreeNodeItem.h"
#include "MathTokenAccessory.h"
#include "errorhandler.h"

class BinaryTreeAlgorithm : public MathTokenAccessory, public ErrorHandler
{
public:
        BinaryTreeAlgorithm(void);
        ~BinaryTreeAlgorithm(void);
        std::stack<TreeNodeItem*> treeNodes;
        void Create(std::vector<std::string> RPNstring);
        double GetExpressionResult();
        void SetFunctons(std::vector<std::string> functions) {_functions= functions;}
        void SetOperators(std::map<std::string, std::pair< int,int >> operators) {_operators= operators;}

    private:
        double RunRecurcion(TreeNodeItem node);
        TreeNodeItem* create_node(std::string t);
};

#endif // BINARYTREEALGORITHM_H
