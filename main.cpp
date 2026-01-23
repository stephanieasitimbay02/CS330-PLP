//
//  main.cpp
//  TaskManager
//
//  Created by Stephanie Asitimbay on 11/29/25.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Task{
    friend ostream& operator<<(ostream& os, const Task& t);
    
private:
    string description;
    int priority;
    bool completed;
    Task* next;
    Task* previous;
    
public:
    // task constructor
    Task(string d, int p) {
        description = d;
        priority = p;
        completed = false;
        next = nullptr;
        previous = nullptr;
    }
    
    // getter methods
    string getDescription() {
        return description;
    }
    
    int getPriority() {
        return priority;
    }
    
    bool getCompleted() {
        return completed;
    }
    
    Task* getNext() {
        return next;
    }
    
    Task* getPrevious() {
        return previous;
    }

    //setter methods
    void setDescription(string desc) {
        description = desc;
    }
    
    void setPriority(int p) {
        if (p < 4 && p > 0) {
            priority = p;
        } else {
            cout << "Please enter a valid priority level (1, 2, 3)." << endl;
        }
    }
    
    void setCompleted(bool c) {
        completed = c;
    }
    
    void setNext(Task* t) {
        next = t;
    }
    
    void setPrevious(Task* t) {
        previous = t;
    }
};

ostream& operator<<(ostream& os, const Task& t) {
    string c = "no";
    if (t.completed) {
        c = "yes";
    }
    os<< "Description: "<< t.description<< ", Priority: "<< t.priority<< ", Completed: "<< c;
    return os;
}

class TaskList {
    friend ostream& operator<<(ostream& os, const TaskList& tl);
private:
    Task* front;
    Task* rear;
    int length;
    
public:
    // task list constructor
    TaskList() {
        front = nullptr;
        rear = nullptr;
        length = 0;
    }
    
    // function to add tasks to the list
    void addTask(string desc, int p) {
        // making pointer to new task
        Task* pt = new Task(desc, p);
        
        //if list is empty, making new task front and rear
        if (length == 0) {
            front = pt;
            rear = pt;
        //otherwise adding to the rear
        } else {
            pt->setPrevious(rear);
            rear->setNext(pt);
            rear = pt;
        }
        
        length += 1;
    }
    
    // function to remove tasks, takes in an int of what number task to remove
    Task* removeTask(int num) {
        if (num > length || num < 1) {
            cout<< "Please enter a valid task number" << endl;
            return nullptr;
        }
        //if list is empty nullptr will be returned
        if (length == 0) {
            cout<< "There are no tasks in your list"<< endl;
            return nullptr;
        //if only one item in the list, it will be removed
        } else if (length == 1) {
            Task* rTask = front;
            front = nullptr;
            rear = nullptr;
            length -= 1;
            return rTask;
        } else {
            //temp variable to hold front
            Task* t = front;
            //lcv to keep track of the task number
            int nTasks = 1;
            while (nTasks < num) {
                //updating t until we get to desired task number
                t = t->getNext();
                nTasks += 1;
            }
            //getting previous and next tasks
            Task* before = t->getPrevious();
            Task* after = t->getNext();
            //updating task list
            if (t == front) {
                front = after;
                front->setPrevious(nullptr);
            } else if (t == rear) {
                rear = before;
                rear->setNext(nullptr);
            } else {
                before->setNext(after);
                after->setPrevious(before);
            }
            
            length -= 1;
            return t;
        }
    }

    
    Task* markComplete(int num) {
        //making sure num is within the task list length
        if (num <= length && num > 0 && length > 0) {
            //same method as removeTask to get to desired task number
            Task* t = front;
            
            int nTasks = 1;
            while (nTasks < num) {
                t = t->getNext();
                nTasks ++;
            }
            //marking task complete
            t->setCompleted(true);
            return t;
        //if num not valid returning nullptr
        } else {
            cout<< "Please enter a valid task number"<< endl;
            return nullptr;
        }
    }
    
    // function to delete all completed tasks
    vector<Task*> deleteCompleted() {
        // initializing empty vector to hold deleted tasks
        vector<Task*> deleted;
        
        // checking if task list is empty
        if (length == 0) {
            cout<< "There are no tasks in your list"<< endl;
            return deleted;
        }
        
        // lcv to hold the front
        Task* current = front;
        
        // going through entire list
        while(current != nullptr) {
            // saving previous and next tasks in variables
            Task* after = current->getNext();
            Task* before = current->getPrevious();
            
            // checking if task has been completed
            if (current->getCompleted()) {
                // pushing completed task into vector
                deleted.push_back(current);
                
                // going through all three possible scenarios and updating task list
                if (current == front && current == rear) {
                    front = nullptr;
                    rear = nullptr;
                } else if (current == front){
                    front = after;
                    front->setPrevious(nullptr);
                } else if (current == rear) {
                    rear = before;
                    rear->setNext(nullptr);
                } else {
                    before->setNext(after);
                    after->setPrevious(before);
                }
                // adjusting length
                length -= 1;
            }
            //updating lcv
            current = after;
        }
        // returning vector of delted tasks
        return deleted;
    }
    
    //function to print a sorted version of task list
    void printSortedTaskList() {
        // checking if task list is empty
        if (length == 0) {
            cout<< "There are no tasks in your list"<< endl;
        } else{
            // making empty vector to hold tasks
            vector<Task*> tasks;
            // making lcv as frint
            Task* current = front;
            //going through entire list
            while(current != nullptr) {
                //pushing all tasks into vector
                tasks.push_back(current);
                //updating lcv
                current = current->getNext();
            }
            // sorting the vector by priority
            sort(tasks.begin(), tasks.end(), [] (Task* a, Task* b) {
                return a->getPriority() < b->getPriority();
            });
            int index = 1;
            // printing the sorted vector
            for (Task* t: tasks) {
                cout<<index<< ". "<< *t<< endl;
                index++;
            }
        }
    }
    
    // function to get the number of tasks in list
    int getNumTasks() {
        return length;
    }
    
};

ostream& operator<<(ostream& os, const TaskList& tl) {
    if (tl.length == 0) {
        os<< "There are no tasks in your list" << endl;
        return os;
    } else {
        Task* current = tl.front;
        int index = 1;
        
        while (current != nullptr) {
            os<< index<< ". "<< *current<< endl;
            current = current->getNext();
            index++;
        }
        return os;
    }
}

void introduction() {
    cout<< "Welcome to your task manager"<< endl;
    cout<< "You will be able to: "<< endl;
    cout<< "1. Add tasks"<< endl<< "2. Remove Tasks"<< endl<< "3. Mark tasks complete"<< endl<< "4. Remove all completed tasks"<< endl<< "5. See your task list"<< endl<< "6. See your task list sorted by priority"<< endl;
};



int main(int argc, const char * argv[]) {
    introduction();
    string kg = "y";
    string printList;
    int option;
    TaskList tl;
    
    while (kg == "y") {
        cout<< "Would you like to reprint option list? (y/n)"<< endl;
        cin>> printList;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (printList == "y") {
            introduction();
        }
        
        cout<< "Which option would you like to do? (1-6)"<< endl;
        cin>> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (option == 1){
            cout<< "You have chosen option 1: Add a task"<< endl;
            
            string desc;
            cout<< "Please enter a short description of your task: "<< endl;
            getline(cin, desc);
            
            int p;
            cout<< "Please enter a priority level for your task (1, 2, 3): "<< endl;
            cin>> p;
            
            tl.addTask(desc, p);
            
            cout<< "Task added!"<< endl;
        } else if (option == 2) {
            int tnum;
            
            cout<< "You have chosen option 2: Remove a task"<< endl;
            cout<< "Here is your task list: "<< endl;
            cout<< tl<< endl;
            
            cout<< "What task number would you like to delete?"<< endl;
            cin>> tnum;
            
            Task* r = tl.removeTask(tnum);
            cout<< "Task: "<< *r<< ", has been deleted!"<< endl;
            delete r;
            
        } else if (option == 3) {
            int tnum;
            
            cout<< "You have chosen option 3: Mark a task complete"<< endl;
            cout<< "Here is your task list: "<< endl;
            cout<< tl<< endl;
            
            cout<< "What task number would you like to mark complete?"<< endl;
            cin>> tnum;
            
            Task* c = tl.markComplete(tnum);
            cout<< "Task: "<< *c<< ", has been marked complete!"<< endl;
            
        } else if (option == 4) {
            cout<< "You have chosen option 4: Remove all completed tasks"<< endl;
            
            vector<Task*> cTasks = tl.deleteCompleted();
            cout<< "Tasks deleted: "<< endl;
            for (Task* t : cTasks) {
                cout<< *t<< endl;
            }
            
            for (Task* t : cTasks) {
                delete t;
            }
            
        } else if (option == 5) {
            cout<< "You have chosen option 5: Print task list"<< endl;
            cout<< tl;
            
        } else if (option == 6) {
            cout<< "You have chosen option 6: Print sorted task list"<< endl;
            tl.printSortedTaskList();
            
        } else {
            cout<< "Please enter a valid option"<< endl;
        }
        
        cout<< "Would you like to choose another option? (y/n)"<< endl;
        cin>> kg;
    }
}
    
