
#ifndef _PARSE_TREE_HPP_
#define _PARSE_TREE_HPP_
#include "itr_utils.hpp"
#include <vector>
#include <iostream>
namespace Bubble
{
    /**
     * 파스 트리 노드 선언부
     */
    template<class T>
    class ParseTreeNode {
        ParseTreeNode<T>* parent;
        std::vector<const ParseTreeNode<T>*> children;
        T* item;


    public:
        ParseTreeNode();
        ParseTreeNode(T* d);
        virtual ~ParseTreeNode();
        void AppendChild(const ParseTreeNode<T>* d);
        const std::vector<const ParseTreeNode<T>*>& Children() const { return children; }
        const ParseTreeNode<T>* Child(int index) const { return children[index]; }
        void TraversePostOrder() const;
        T* Item() const { return item; }
    };

    template<class T>
    ParseTreeNode<T>::ParseTreeNode()
        : item(0)
    {
    }

    /**
     * 파스 트리 노드 생성자. 
     *
     * d - 초기화 할 아이템의 포인터
     */
    template<class T>
    ParseTreeNode<T>::ParseTreeNode(T* d)
        : item(d)
    {
    }

    /**
     * 파스 트리 노드 파괴자. 아이템과 자식노드까지 모두 파괴한다.
     */
    template<class T>
    ParseTreeNode<T>::~ParseTreeNode()
    {
        ItrUtils::sequence_delete(children.begin(), children.end());
        if (item != 0) delete item;
        std::cerr << ".";
    }

    /**
     * 트리 노드 포인터를 받아서 자식 트리의 맨 오른쪽에 추가해 준다.
     */
    template<class T>
    void ParseTreeNode<T>::AppendChild(const ParseTreeNode<T>* node)
    {
        children.push_back(node);
    }

    template<class T>
    void ParseTreeNode<T>::TraversePostOrder() const
    {
        for (unsigned int i = 0; i < children.size(); i++)
            children[i]->TraversePostOrder();
        if (item)
            std::cerr << item->toString();
    }

    /**
     * 파스 트리 선언부
     */
    template<class T> class ParseTree {
        ParseTreeNode<T>* root;

    public:
        ParseTree(ParseTreeNode<T>* r);
        virtual ~ParseTree();
        void TraversePostOrder() const;
    };

    /**
     * 파스 트리 생성자. 루트를 인자로 받는다.
     */
    template<class T>
    ParseTree<T>::ParseTree(ParseTreeNode<T>* r)
        : root(r)
    {
    }

    /**
     * 파스 트리 파괴자. 모든 노드를 파괴한다.
     */
    template<class T>
    ParseTree<T>::~ParseTree()
    {
        delete root;
        std::cerr << std::endl;
    }

    template<class T>
    void ParseTree<T>::TraversePostOrder() const
    {
        root->TraversePostOrder();
    }
}
#endif
