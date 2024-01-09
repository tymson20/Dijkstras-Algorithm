#ifndef NODE_H
#define NODE_H

class Node {
private:
    static int s_Id;

public:
    explicit Node() : m_Id(s_Id) { s_Id++; }

    int getId() const { return m_Id; }

private:
    int m_Id;
};

#endif // NODE_H