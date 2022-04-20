#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include <memory>

class List
{
private:
    struct Node{
	Node() = default;
	Node(int v, Node* p, Node* n)
	    : value{v}, prev{p}, next{n} {}
	int value {};
	Node* prev {};
	std::unique_ptr<Node> next {};
    };
	
    std::unique_ptr<Node> head {};
    Node* tail {};
    int sz {};
    
public:
    List();
    List(List const &);
    List(List &&) noexcept;
    List(std::initializer_list<int>);

    List & operator=(List const &)&;
    List & operator=(List &&)& noexcept;

    void push_front(int);
    void push_back(int);

    int back() const noexcept;
    int & back() noexcept;

    int front() const noexcept;
    int & front() noexcept;

    int & at(int idx);
    int const & at(int idx) const;

    int size() const noexcept;
    bool empty() const noexcept;

    void swap(List & other) noexcept;

       class List_Iterator
    {
    public:
	friend class List;
	using iterator_category = std::bidirectional_iterator_tag;
	using value_type = int;
	using difference_type = int;
	using pointer = int*;
	using reference = int&;

	reference operator*() const;
	
	List_Iterator & operator++();
	List_Iterator operator++(int);
	
	List_Iterator & operator--();
	List_Iterator operator--(int);

	bool operator==(const List_Iterator&) const;
	bool operator!=(const List_Iterator&) const;
	pointer operator->() const;
	
    private:
	List_Iterator();
	List_Iterator(Node* ptr);
	Node* curr{};
    };

    List_Iterator begin() const;
    List_Iterator end() const;

};

#endif //LIST_H
