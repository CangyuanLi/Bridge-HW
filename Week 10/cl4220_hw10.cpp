#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

template <class T>
class LListNode;

template <class T>
class LList;

class Employee;

/*--------------------------------- Linked List Node Class ---------------------------------*/

template <class T>
class LListNode 
{
    public:
        T data;
        LListNode<T> *next;
        LListNode() : data(T()), next(nullptr) {};
        LListNode(T newdata = T(), LListNode<T>* newnext = nullptr) : data(newdata), next(newnext) {};
        T &get_data() { return this -> data; };
        friend class LList<T>; 
};

/*--------------------------------- Linked List Class ---------------------------------*/

template <class T>
class LList
{
    LListNode<T> *head;
    LListNode<T> *recursive_copy(LListNode<T> *rhs);

    public:
        LList() : head(nullptr) {};
        LList(const LList &rhs) : head(nullptr) { *this = rhs; };
        ~LList() { clear(); };
        void insert_at_head(T newdata);
        T remove_from_head();
        bool is_empty() const { return head == nullptr; };
        void clear();
        void insert_at_end(T newdata);
        LListNode<T>* get_head() const { return this -> head; };
        void insert_at_point(LListNode<T> *ptr, T newdata);
        int get_size();
        LListNode<T>* get_node_at_index(int index);
        void swap_nodes(LListNode<T> *first, LListNode<T> *second);
};

template <class T>
int LList<T>::get_size()
{
    LListNode<T> *current = LList<T>::head;
    int count = 0;
    while (current != nullptr)
    {
        count += 1;
        current = current -> LListNode::next;
    }
    
    return count;
}

template <class T>
void LList<T>::swap_nodes(LListNode<T> *first, LListNode<T> *second)
{
    T temp = first -> LListNode<T>::data;
    first -> LListNode<T>::data = second -> LListNode<T>::data;
    second -> LListNode<T>::data = temp;
    first = first -> LListNode<T>::next;
}

template <class T>
LListNode<T>* LList<T>::get_node_at_index(int index)
{
    LListNode<T> *current = LList<T>::head;
    int count = 0;
    while (current != nullptr)
    {
        if (count == index)
        {
            return current;
        }

        count += 1;
        current = current -> LListNode::next;
    }
    
    std::cout << "Invalid index";
    return LList<T>::head;
}

template <class T>
void LList<T>::insert_at_head(T newdata) 
{
    LListNode<T> *new_node = new LListNode<T>();
    new_node -> LListNode::data = newdata;
    new_node -> LListNode::next = LList::head;
    LList::head = new_node;
}

template <class T>
void LList<T>::insert_at_end(T newdata)
{
    LListNode<T> *new_node = new LListNode<T>(newdata);  // allocate a new node
    new_node -> LListNode::data = newdata; // input new data
    new_node -> LListNode::next = nullptr; // now the next node is a nullptr

    if (LList::head == nullptr) 
    {
        LList::head = new_node; // if this is first node added, make it the head
    } 
    else 
    {
        LListNode<T> *temp = LList::head;
        while (temp -> LListNode::next != nullptr) // go to the last node
        {
            temp = temp -> LListNode::next;
        }

        temp -> LListNode::next = new_node;
    }    
}

template <class T>
LListNode<T> *LList<T>::recursive_copy(LListNode<T> *rhs)
{
    if (rhs == nullptr)
    {
        return nullptr;
    }
    
    return new LListNode<T>(rhs -> LListNode::data, recursive_copy(rhs -> LListNode::next));
}

template <class T>
void LList<T>::clear() 
{
	LListNode<T> *temp = head; 
	while (temp != nullptr) {
		LListNode<T> *to_delete = temp; 
		temp = temp -> LListNode<T>::next; 
		delete to_delete; 
	}
}

/*--------------------------------- Employee Class ---------------------------------*/

class Employee
{
    private:
        int id;
        std::string name;
        float hourly_pay;
        int hours_worked;
        float total_pay;

    public:
        // constructors
        Employee();
        Employee(int emp_id, std::string emp_name, float emp_hourly_pay);
        Employee(int emp_id, int hours_worked);

        // getters
        std::string get_name() { return name; };
        int get_id() { return id; };
        int get_hourly_pay() { return hourly_pay; };
        int get_hours_worked() { return hours_worked; };
        int get_total_pay() { return total_pay; };

        void add_hours_worked(int hours_worked) { this -> hours_worked += hours_worked; };
        void set_total_pay() { total_pay = (hourly_pay * hours_worked); };
};

Employee::Employee(int emp_id, std::string emp_name, float emp_hourly_pay)
{
    Employee::id = emp_id;
    Employee::name = emp_name;
    Employee::hourly_pay = emp_hourly_pay;
}

Employee::Employee(int emp_id, int hours_worked)
{
    Employee::id = emp_id;
    Employee::hours_worked = hours_worked;
}

/*--------------------------------- Other Functions ---------------------------------*/

void strip_endline_chars(std::string &str) {
    char endline_chars[2] = { '\r', '\n' };

    for (int i = 0; i < 2; i++) 
    {
        str.erase(std::remove(str.begin(), str.end(), endline_chars[i]), str.end());
    }
}

void open_file(std::ifstream &infile) 
{
	std::string filepath;
	std::cout << "Enter filepath: ";
	std::cin >> filepath;
	infile.open(filepath);

	while (!infile) 
    {
		std::cout << "File failed to open.\n";
		std::cout << "Enter filepath: ";
		std::cin >> filepath;
		infile.clear();
		infile.open(filepath);
	}
}

LList<Employee> read_employee_file()
{
    std::ifstream emp_file;
    open_file(emp_file);

    LList<Employee> emp_file_llist;
    int emp_id;
    while (emp_file >> emp_id)
    {
        float emp_hourly_rate;
        emp_file >> emp_hourly_rate;

        std::string emp_name;
        emp_file.ignore(9999, ' ');
        std::getline(emp_file, emp_name);
        strip_endline_chars(emp_name);
        
        Employee emp(emp_id, emp_name, emp_hourly_rate);
        emp_file_llist.insert_at_end(emp);
    }

    emp_file.close();

    return emp_file_llist;
}

LList<Employee> read_hour_file()
{
    std::ifstream hour_file;
    open_file(hour_file);

    LList<Employee> hour_file_llist;
    int emp_id;
    while (hour_file >> emp_id)
    {
        int hours_worked;
        hour_file >> hours_worked;   
        
        Employee emp(emp_id, hours_worked);
        hour_file_llist.insert_at_end(emp);
    }

    hour_file.close();

    return hour_file_llist;
}

void add_hour_data_to_emp(LList<Employee> *emp_llist, LList<Employee> *hour_llist)
{
    for (LListNode<Employee> *i = (*emp_llist).get_head(); i != nullptr; i = i -> LListNode::next) 
    {
        int emp_file_id = i -> get_data().get_id();
        for (LListNode<Employee> *j = (*hour_llist).get_head(); j != nullptr; j = j -> LListNode::next)
        {
            int hour_file_id = j -> get_data().get_id();
            if (emp_file_id == hour_file_id)
            {
                int hours_worked = j -> get_data().get_hours_worked();
                i -> get_data().add_hours_worked(hours_worked);
            }
        }

        i -> get_data().set_total_pay();
    }
}

int find_index_of_max(LList<Employee> *llist, int low, int high)
{
    int max_pay = llist -> get_node_at_index(low) -> get_data().get_total_pay();

    int max_index = low;
    for (int i = low + 1; i <= high; i++)
    {
        int pay = llist -> get_node_at_index(i) -> get_data().get_total_pay();

        if (pay > max_pay)
        {
            max_pay = pay;
            max_index = i;
        }
    }
    
    return max_index;
}

void sort_by_payroll(LList<Employee> *merged_llist)
{
    int size = merged_llist -> get_size();

    for (int i = 0; i < size; i++)
    {
        int max_ind = find_index_of_max(merged_llist, i, size - 1);
        LListNode<Employee> *i_ptr = merged_llist -> get_node_at_index(i);
        LListNode<Employee> *max_ind_ptr = merged_llist -> get_node_at_index(max_ind);
        merged_llist -> swap_nodes(i_ptr, max_ind_ptr);
    }
}

void test_swap(LList<Employee> *emp_file_llist)
{
    LListNode<Employee>* i_ptr = emp_file_llist -> get_node_at_index(0);
    LListNode<Employee>* max_ind_ptr = emp_file_llist -> get_node_at_index(1);
    emp_file_llist -> swap_nodes(i_ptr, max_ind_ptr);
}

void print_final_output(LList<Employee> *final_llist) 
{
    LListNode<Employee> *head = final_llist -> get_head();
	std::cout << "\n********Payroll Information********\n";

	for (LListNode<Employee> *i = head; i != nullptr; i = i -> LListNode::next) 
    {
		std::string emp_name = i -> get_data().get_name();
		float emp_total_pay = i -> get_data().get_total_pay();
		std::cout << emp_name << ", $" << emp_total_pay << '\n';
	}
	std::cout << "***********End Payroll*************\n";
}

/*--------------------------------- Main ---------------------------------*/

int main()
{
    LList<Employee> emp_file_llist = read_employee_file();
    LList<Employee> hour_file_llist = read_hour_file();
    add_hour_data_to_emp(&emp_file_llist, &hour_file_llist);
    print_final_output(&emp_file_llist);
    
    sort_by_payroll(&emp_file_llist);

    print_final_output(&emp_file_llist);
}