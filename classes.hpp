#ifndef AST_NODE_H
#define AST_NODE_H

#include <iostream>
#include <vector>
// #include <stdlib.h>


// Abstract base class for AST nodes
class AstNode {
public:
    static int n;
    std::string name = "undefined";   // String member variable with default value
    std::string label = "undefined";
    virtual void add(AstNode* node) = 0;
    virtual void print() const = 0;
    virtual ~AstNode() {}

};
/******************************************/

class ProgramNode : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    ProgramNode(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "program_" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~ProgramNode()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};


// Composite node for representing binary expressions
class add_Node : public AstNode {
private:

    AstNode* left;
    AstNode* right;

public:
    add_Node()
        {
            this->label = "add" ;
            this->name = this->label + std::to_string(n++);
        }

    void add(AstNode* node) override {
        if (!left)
            left = node;
        else if (!right)
            right = node;
        else
            std::cerr << "Add expression already has two children." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        std::cout << "  " << name << " -> " << left->name << ";" << std::endl;
        left->print();
        std::cout << "  " << name << " -> " << right->name << ";" << std::endl;
        right->print();
   }

    ~add_Node() {
        delete left;
        delete right;
    }
};

class sub_Node : public AstNode {
private:

    AstNode* left;
    AstNode* right;

public:
    sub_Node()
        {
            this->label = "sub" ;
            this->name = this->label + std::to_string(n++);
        }

    void add(AstNode* node) override {
        if (!left)
            left = node;
        else if (!right)
            right = node;
        else
            std::cerr << "Sub expression already has two children." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        std::cout << "  " << name << " -> " << left->name << ";" << std::endl;
        left->print();
        std::cout << "  " << name << " -> " << right->name << ";" << std::endl;
        right->print();
   }

    ~sub_Node() {
        delete left;
        delete right;
    }
};


class mul_Node : public AstNode {
private:

    AstNode* left;
    AstNode* right;

public:
    mul_Node()
        {
            this->label = "mul" ;
            this->name = this->label + std::to_string(n++);
        }

    void add(AstNode* node) override {
        if (!left)
            left = node;
        else if (!right)
            right = node;
        else
            std::cerr << "Mul expression already has two children." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        std::cout << "  " << name << " -> " << left->name << ";" << std::endl;
        left->print();
        std::cout << "  " << name << " -> " << right->name << ";" << std::endl;
        right->print();
   }

    ~mul_Node() {
        delete left;
        delete right;
    }
};


class div_Node : public AstNode {
private:

    AstNode* left;
    AstNode* right;

public:
    div_Node()
        {
            this->label = "div" ;
            this->name = this->label + std::to_string(n++);
        }

    void add(AstNode* node) override {
        if (!left)
            left = node;
        else if (!right)
            right = node;
        else
            std::cerr << "Div expression already has two children." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        std::cout << "  " << name << " -> " << left->name << ";" << std::endl;
        left->print();
        std::cout << "  " << name << " -> " << right->name << ";" << std::endl;
        right->print();
   }

    ~div_Node() {
        delete left;
        delete right;
    }
};

class equal_Node : public AstNode {
private:

    AstNode* left;
    AstNode* right;

public:
    equal_Node()
        {
            this->label = "equal" ;
            this->name = this->label + std::to_string(n++);
        }

    void add(AstNode* node) override {
        if (!left)
            left = node;
        else if (!right)
            right = node;
        else
            std::cerr << "Equal expression already has two children." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        std::cout << "  " << name << " -> " << left->name << ";" << std::endl;
        left->print();
        std::cout << "  " << name << " -> " << right->name << ";" << std::endl;
        right->print();
   }

    ~equal_Node() {
        delete left;
        delete right;
    }
};


class greaterorequal_Node : public AstNode {
private:

    AstNode* left;
    AstNode* right;

public:
    greaterorequal_Node()
        {
            this->label = "GrEq" ;
            this->name = this->label + std::to_string(n++);
        }

    void add(AstNode* node) override {
        if (!left)
            left = node;
        else if (!right)
            right = node;
        else
            std::cerr << "greater_or_equal_Node expression already has two children." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        std::cout << "  " << name << " -> " << left->name << ";" << std::endl;
        left->print();
        std::cout << "  " << name << " -> " << right->name << ";" << std::endl;
        right->print();
   }

    ~greaterorequal_Node() {
        delete left;
        delete right;
    }
};



class lessorequal_Node : public AstNode {
private:

    AstNode* left;
    AstNode* right;

public:
    lessorequal_Node()
        {
            this->label = "LsEq" ;
            this->name = this->label + std::to_string(n++);
        }

    void add(AstNode* node) override {
        if (!left)
            left = node;
        else if (!right)
            right = node;
        else
            std::cerr << "less_or_equal_Node expression already has two children." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        std::cout << "  " << name << " -> " << left->name << ";" << std::endl;
        left->print();
        std::cout << "  " << name << " -> " << right->name << ";" << std::endl;
        right->print();
   }

    ~lessorequal_Node() {
        delete left;
        delete right;
    }
};

class greaterthan_Node : public AstNode {
private:

    AstNode* left;
    AstNode* right;

public:
    greaterthan_Node()
        {
            this->label = "GrTh" ;
            this->name = this->label + std::to_string(n++);
        }

    void add(AstNode* node) override {
        if (!left)
            left = node;
        else if (!right)
            right = node;
        else
            std::cerr << "greater_than_Node expression already has two children." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        std::cout << "  " << name << " -> " << left->name << ";" << std::endl;
        left->print();
        std::cout << "  " << name << " -> " << right->name << ";" << std::endl;
        right->print();
   }

    ~greaterthan_Node() {
        delete left;
        delete right;
    }
};

class lessthan_Node : public AstNode {
private:

    AstNode* left;
    AstNode* right;

public:
    lessthan_Node()
        {
            this->label = "LsTh" ;
            this->name = this->label + std::to_string(n++);
        }

    void add(AstNode* node) override {
        if (!left)
            left = node;
        else if (!right)
            right = node;
        else
            std::cerr << "less_than_Node expression already has two children." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        std::cout << "  " << name << " -> " << left->name << ";" << std::endl;
        left->print();
        std::cout << "  " << name << " -> " << right->name << ";" << std::endl;
        right->print();
   }

    ~lessthan_Node() {
        delete left;
        delete right;
    }
};


class pow_Node : public AstNode {
private:

    AstNode* left;
    AstNode* right;

public:
    pow_Node()
        {
            this->label = "Pow" ;
            this->name = this->label + std::to_string(n++);
        }

    void add(AstNode* node) override {
        if (!left)
            left = node;
        else if (!right)
            right = node;
        else
            std::cerr << "pow_Node expression already has two children." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        std::cout << "  " << name << " -> " << left->name << ";" << std::endl;
        left->print();
        std::cout << "  " << name << " -> " << right->name << ";" << std::endl;
        right->print();
   }

    ~pow_Node() {
        delete left;
        delete right;
    }
};




class mod_Node : public AstNode {
private:

    AstNode* left;
    AstNode* right;

public:
    mod_Node()
        {
            this->label = "Mod" ;
            this->name = this->label + std::to_string(n++);
        }

    void add(AstNode* node) override {
        if (!left)
            left = node;
        else if (!right)
            right = node;
        else
            std::cerr << "mod_Node expression already has two children." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        std::cout << "  " << name << " -> " << left->name << ";" << std::endl;
        left->print();
        std::cout << "  " << name << " -> " << right->name << ";" << std::endl;
        right->print();
   }

    ~mod_Node() {
        delete left;
        delete right;
    }
};




class and_Node : public AstNode {
private:

    AstNode* left;
    AstNode* right;

public:
    and_Node()
        {
            this->label = "And" ;
            this->name = this->label + std::to_string(n++);
        }

    void add(AstNode* node) override {
        if (!left)
            left = node;
        else if (!right)
            right = node;
        else
            std::cerr << "and_Node expression already has two children." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        std::cout << "  " << name << " -> " << left->name << ";" << std::endl;
        left->print();
        std::cout << "  " << name << " -> " << right->name << ";" << std::endl;
        right->print();
   }

    ~and_Node() {
        delete left;
        delete right;
    }
};


class at_Node : public AstNode {
private:

    AstNode* left;
    AstNode* right;

public:
    at_Node(const std::string &name)
        {
            this->label = "At" ;
            this->name = this->label + std::to_string(n++);
        }

    void add(AstNode* node) override {
        if (!left)
            left = node;
        else if (!right)
            right = node;
        else
            std::cerr << "at_Node expression already has two children." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        std::cout << "  " << name << " -> " << left->name << ";" << std::endl;
        left->print();
        std::cout << "  " << name << " -> " << right->name << ";" << std::endl;
        right->print();
   }

    ~at_Node() {
        delete left;
        delete right;
    }
};




class compound_stat : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    compound_stat(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "compound_stat" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~compound_stat()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};


class simple_stat : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    simple_stat(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "simple_stat" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~simple_stat()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class statements : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    statements(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "stats" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~statements()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};


class statement : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    statement(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "statement" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~statement()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};


class print_node : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    print_node(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "print" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~print_node()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};




class function_call : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    function_call(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "function_call" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~function_call()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};



class yield_statement : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    yield_statement(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "yield_statement" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~yield_statement()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};




class relational : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    relational(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "relational" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~relational()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};


class equality : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    equality(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "function_call" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~equality()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};


class membership : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    membership(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "function_call" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~membership()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};



class identity : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    identity(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "function_call" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~identity()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};


class logicalnot : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    logicalnot(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "function_call" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~logicalnot()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};





class logicaland : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    logicaland(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "function_call" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~logicaland()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};




class logicalor : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    logicalor(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "function_call" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~logicalor()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};












class Assert_statementNode: public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    Assert_statementNode(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "assert" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~Assert_statementNode()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};


class Args_generatorNode: public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    Args_generatorNode(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "args_generator" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~Args_generatorNode()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};


class Range_expressionNode: public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    Range_expressionNode(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "range_expression" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~Range_expressionNode()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class Assignment_statementNode : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    Assignment_statementNode(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "assignment_stat" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~Assignment_statementNode()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class expression_stat : public AstNode {
private:
    std::vector<AstNode*> next;

public:
    expression_stat(const std::string& name) {
        this->name = name + std::to_string(n);
        this->label = "expression_stat" + std::to_string(n++);
    }

    void add(AstNode* node) override {
        next.push_back(node);
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~expression_stat() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class return_statement : public AstNode {
private:
    std::vector<AstNode*> next;

public:
    return_statement(const std::string& name) {
        this->name = name + std::to_string(n);
        this->label = "return" + std::to_string(n++);
    }

    void add(AstNode* node) override {
        next.push_back(node);
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~return_statement() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};




class block : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    block(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "block" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~block()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};



class assert_statement : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    assert_statement(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "assert_statement" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~assert_statement()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};





class break_statement : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    break_statement(const std::string& name) {
        this->name = name + std::to_string(n);
        this->label = "break" + std::to_string(n++);
    }
       void add(AstNode* node) override {
        next.push_back(node);
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~break_statement()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }

};


class continue_statement : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    continue_statement(const std::string& name) {
        this->name = name + std::to_string(n);
        this->label = "continue" + std::to_string(n++);
    }
       void add(AstNode* node) override {
        next.push_back(node);
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
     ~continue_statement() {
        for (const auto* stmt : next) {
            delete stmt;
        }
    }
};

class global_statement : public AstNode {
private:
    std::vector<AstNode*> identifiers;

public:
    global_statement(const std::string& name) {
        this->name = name + std::to_string(n);
        this->label = "global" + std::to_string(n++);
    }

    void add(AstNode* node) override {
        identifiers.push_back(node);
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto& identifier : identifiers) {
            std::cout << "  " << name << " -> " << identifier->name << ";" << std::endl;
            identifier->print();
        }
    }

    ~global_statement() {
        for (const auto& identifier : identifiers) {
            delete identifier;
        }
    }
};

class nonlocal_statement : public AstNode {
private:
    std::vector<AstNode*> identifiers;

public:
    nonlocal_statement(const std::string& name) {
        this->name = name + std::to_string(n);
        this->label = "nonlocal" + std::to_string(n++);
    }

    void add(AstNode* node) override {
        identifiers.push_back(node);
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto& identifier : identifiers) {
            std::cout << "  " << name << " -> " << identifier->name << ";" << std::endl;
            identifier->print();
        }
    }

    ~nonlocal_statement() {
        for (const auto& identifier : identifiers) {
            delete identifier;
        }
    }
};



class if_statement : public AstNode {
private:
    AstNode* condition;
    std::vector<AstNode*> Body;

public:
    if_statement(const std::string& name, AstNode* condition) {
        this->name = name + std::to_string(n);
        this->label = "if" + std::to_string(n++);
        this->condition = condition;
    }

    void add(AstNode *node) override
        {
            Body.push_back(node);
        }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        std::cout << "  " << name << " -> " << condition->name << ";" << std::endl;
        condition->print();

        for (const auto& stmt : Body) {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }


    ~if_statement() {
        delete condition;
        for (const auto &stmt : Body) {
            delete stmt;
        }
    }
};


class else_statement : public AstNode {
private:
    std::vector<AstNode*> elseBody;

public:
    else_statement(const std::string& name) {
        this->name = name + std::to_string(n);
        this->label = "else" + std::to_string(n++);
    }

    void add(AstNode* node) {
        elseBody.push_back(node);
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;

        for (const auto& stmt : elseBody) {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~else_statement() {
        for (const auto& stmt : elseBody) {
            delete stmt;
        }
    }
};







class while_statement : public AstNode {
private:
    AstNode* condition;
    std::vector<AstNode*> body;

public:
    while_statement(const std::string& name, AstNode* condition) {
        this->name = name + std::to_string(n);
        this->label = "while_statement" + std::to_string(n++);
        this->condition = condition;
    }

    void add(AstNode* node) {
        body.push_back(node);
    }

    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        std::cout << "  " << name << " -> " << condition->name << ";" << std::endl;
        condition->print();

        for (const auto& stmt : body) {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~while_statement() {
        delete condition;
        for (const auto& stmt : body) {
            delete stmt;
        }
    }
};

class for_statement : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    for_statement(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "for" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~for_statement()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class GeneratorNode : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    GeneratorNode(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "generator" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~GeneratorNode()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class class_statement : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    class_statement(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "class" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~class_statement()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class Class_argsNode : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    Class_argsNode(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "class_args" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~Class_argsNode()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class with_statement : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    with_statement(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "with_stat" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~with_statement()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class with : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    with(const std::string &name)
{
    this->name = name + std::to_string(n);
    this->label = "with";
}

void add(AstNode *node) override
{
    next.push_back(node);
}

void print() const override
{
    std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
    for (const auto &stmt : next)
    {
        std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
        stmt->print();
    }
}

~with()
{
    for (const auto &stmt : next)
    {
        delete stmt;
    }
}
};

class complex_with_as_statement : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    complex_with_as_statement(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "complex_with_as_stat" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~complex_with_as_statement()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class With_asNode : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    With_asNode(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "with_as" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~With_asNode()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class try_statement : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    try_statement(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "try" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~try_statement()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class except_statement_list : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    except_statement_list(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "except_stat_list" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~except_statement_list()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class except_statement : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    except_statement(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "except_stat" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~except_statement()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class Except_expressionNode : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    Except_expressionNode(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "except_expression" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~Except_expressionNode()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class Exception_asNode : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    Exception_asNode(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "exception_as" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~Exception_asNode()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class Finally_statementNode : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    Finally_statementNode(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "finally_stat" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~Finally_statementNode()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class Match_statementNode : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    Match_statementNode(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "match" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~Match_statementNode()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class Pattern_listNode : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    Pattern_listNode(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "pattern_list" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~Pattern_listNode()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class PatternNode : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    PatternNode(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "pattern" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~PatternNode()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class function_def : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    function_def(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "function_def" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~function_def()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class Function_declaration_argsNode : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    Function_declaration_argsNode(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "function_declaration_args" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~Function_declaration_argsNode()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class Function_identifier_parameterNode : public AstNode
{
private:
    std::vector<AstNode*> next;

public:
    Function_identifier_parameterNode(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "function_identifier_parameter" + std::to_string(n++);
    }

    void add(AstNode *node) override
    {
        next.push_back(node);
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &stmt : next)
        {
            std::cout << "  " << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }

    ~Function_identifier_parameterNode()
    {
        for (const auto &stmt : next)
        {
            delete stmt;
        }
    }
};

class Keyword_argsNode : public AstNode
{
private:
    std::vector<std::pair<std::string, AstNode*>> args;

public:
    Keyword_argsNode(const std::string &name)
    {
        this->name = name + std::to_string(n);
        this->label = "keyword_args" + std::to_string(n++);
    }

    void add(const std::string &keyword, AstNode *value)
    {
        args.push_back(std::make_pair(keyword, value));
    }

    void print() const override
    {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto &arg : args)
        {
            std::cout << "  " << name << " -> " << arg.second->name << ";" << std::endl;
            arg.second->print();
        }
    }

    ~Keyword_argsNode()
    {
        for (const auto &arg : args)
        {
            delete arg.second;
        }
    }
};

class COMMENTNode : public AstNode {
private:
    std::string  value;
public:
    COMMENTNode(std::string name, std::string label, int value) {
        this->name = name + std::to_string(n);
        this->label = label  + std::to_string(n++);
        this->value = value; 
    }

    void add(AstNode* /*node*/) override {
        std::cerr << "Cannot add a child to a leaf node." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [shape=box,label=\"" << label << ": " << value << "\"]" << std::endl;

    }
};

class INTEGER : public AstNode {
private:
    int value;
public:
    INTEGER(std::string name, std::string label, int value) {
        this->name = name + std::to_string(n);
        this->label = label + std::to_string(n++);
        this->value = value; 
    }

    void add(AstNode* /*node*/) override {
        std::cerr << "Cannot add a child to a leaf node." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [shape=box,label=\"" << label << ": " << value << "\"]" << std::endl;

    }
};

class FLOAT : public AstNode {
private:
    float value;
public:
    FLOAT(std::string name, std::string label, int value) {
        this->name = name + std::to_string(n);
        this->label = label + std::to_string(n++);
        this->value = value; 
    }

    void add(AstNode* /*node*/) override {
        std::cerr << "Cannot add a child to a leaf node." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [shape=box,label=\"" << label << ": " << value << "\"]" << std::endl;

    }
};

class IDENTIFIER : public AstNode {
private:
    std::string  value;
public:
    IDENTIFIER(std::string name, std::string label, int value) {
        this->name = name + std::to_string(n);
        this->label = label + std::to_string(n++);
        this->value = value; 
    }

    void add(AstNode* /*node*/) override {
        std::cerr << "Cannot add a child to a leaf node." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [shape=box,label=\"" << label << ": " << value << "\"]" << std::endl;

    }
};

class COMMENT_END : public AstNode {
private:
    std::string value;
public:
    COMMENT_END(std::string name, std::string label, std::string value) {
        this->name = name + std::to_string(n); 
        this->label = label + std::to_string(n++);
        this->value = value; 
    }

    void add(AstNode* /*node*/) override {
        std::cerr << "Cannot add a child to a leaf node." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [shape=box,label=\"" << label << ": " << value << "\"]" << std::endl;

    }
};


class STRING_CONTENT : public AstNode {
private:
    std::string value;
public:
    STRING_CONTENT(std::string name, std::string label, std::string value) {
        this->name = name + std::to_string(n);
        this->label = label + std::to_string(n++);
        this->value = value; 
    }

    void add(AstNode* /*node*/) override {
        std::cerr << "Cannot add a child to a leaf node." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [shape=box,label=\"" << label << ": " << value << "\"]" << std::endl;

    }
};


class STRING_END : public AstNode {
private:
    std::string value;
public:
    STRING_END(std::string name, std::string label, std::string value) {
        this->name = name + std::to_string(n);
        this->label = label + std::to_string(n++);
        this->value = value;
    }

    void add(AstNode* /*node*/) override {
        std::cerr << "Cannot add a child to a leaf node." << std::endl;
    }

    void print() const override {
        std::cout << "\t" << name << " [shape=box,label=\"" << label << ": " << value << "\"]" << std::endl;

    }
};
class AST {
private:
    AstNode* root = nullptr;
public:
    AST(AstNode* r) : root(r) {}

    ~AST() {
        if (root != nullptr) {
            delete root;
            root = nullptr;
        }
    }
    void Print() {
        std::cout << "digraph G {" << std::endl;
        root->print();
        std::cout << "}" << std::endl;
    }
};
#endif 


