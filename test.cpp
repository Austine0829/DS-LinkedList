#include <iostream>

using namespace std;

struct Person{
    string name;
    int age;

    Person *next;
};

class Information{
    private:
    Person *head;

    public:

    Information();
    ~Information();

    Information (const Information &other) = delete;
    Information operator = (const Information &other) = delete;

    void add(string name, int age);
    void removeAt(int node);
    void updateAt(int node, string newName, int newAge);
    void display();
    void at(int node);
};

Information :: Information()
:head{0}
{

}

Information :: ~Information()
{
    if (head != nullptr)
    {
        delete head; 
        head = nullptr;
    }
}

void Information :: add(string name, int age){

    Person *add = new Person;

    add->name = name;
    add->age = age;
    add->next = nullptr;

    if (head == nullptr)
    {
        head = add;
    }

    else
    {
        Person *current = head;

        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = add;
        
    }
}

void Information :: removeAt(int node){

    Person *current = head;
    Person *prev = head;
    int index = 0;

    while (current != nullptr && index < node)
    {
        prev = current;
        current = current->next;
        
        index++;
    }
    
    if (node != 0)
    {
        prev->next = current->next;
        current->next = nullptr;    
    }

    else
    {
        head = current->next;     
    }
}

void Information :: updateAt(int node, string newName, int newAge){

    Person *current = head;
    int index = 0;

    while (current != nullptr && index < node)
    {
        current = current->next;
        index++;
    }

    if (current != nullptr)
    {
        current->name = newName;
        current->age = newAge;
    }

    else
    {
        cout << "Node Not Found\n";
    }
}

void Information :: display(){

    Person *current = head;

    while (current != nullptr)
    {
        cout << "Name: " << current->name << " ";
        cout << "Age: " << current->age << " ";
        cout << "-------> ";

        current = current->next;
    }
}

void Information :: at(int node){

    Person *current = head;
    int index = 0;

    while (current != nullptr && index < node)
    {
        current = current->next;
        
        index++;
    }

    cout << "Name: " << current->name << "\n";
    cout << "Age: " << current->age << "\n";
}

int main(){    

    Information use;

    use.add("Austine", 21);
    use.add("Winter", 23);
    use.add("Giselle", 21);
    use.add("Karina", 22);

    use.updateAt(1, "Ning Ning", 22);

    use.display();

    return 0;
}
