#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm> // Required for remove_if

using namespace std;
class Task {
private:
// We ideally want our class to have an ID, A title, a description, a status.
    int ID;
    string title;
    string description;
    string status;

public:
// We need constructors, setters and getters
    Task(int id, string _title, string _description, string _status) : ID(id), title(_title), description(_description), status(_status) {}

    int getID() const {
        return ID;
    }
    string getTitle() const {
        return title;
    }
    string getDescription() const {
        return description;
    }
    string getStatus() const {
        return status;
    }

    // setters are never constant but getters are 
    void setTitle(string _title)  {
        title = _title;
    }

    void setDescription(string _description)  {
        description = _description;
    }

    void setStatus (string _status)  {
        status = _status;
    }
    // This just allows us to display the contents
    void display() const {
        cout << "The ID is " << ID << "\nThe title is " << title << "\nThe description is " << description << "\nThe status is " << status << endl;
    }
};

// What features would we want our task manager to have?

class TaskManager {
private:
    int nextID;
    vector<Task> tasks;

public:
// We need constructors getters and setters
// Then we need to decide what we want our task Manager to do.
// So I would like it to add tasks, update tasks, and also to delete tasks. I would like to view tasks as well.

    TaskManager() : nextID(1) {}
    
    int getID() const {
        return nextID;
    }

    void addTask(string title, string description, string status) {
        tasks.emplace_back(nextID ++, title, description, status);
    }
    
    void viewTasks() {
        for (size_t i = 0; i < tasks.size(); i++) {
            tasks[i].display();
            cout << "-------------------------------------" << endl;
        }
    }

    void updateTask(int id, string title, string description, string status) {
        for (size_t i = 0; i < tasks.size(); i++) {
            if (tasks[i].getID() == id) {
                tasks[i].setTitle(title);
                tasks[i].setDescription(description);
                tasks[i].setStatus(status);
                return ;
            }
        }
        cout << "Task not found." << endl; // Task ID not found in the vector
    }

    void deleteTask(int id) {
        for (size_t i = 0; i < tasks.size(); ++i) { // Iterate over vector elements
            if (tasks[i].getID() == id) { // Check if current task's ID matches
                tasks.erase(tasks.begin() + i); // Remove element using iterator
                return; // Exit function after deleting the task
            }
        }
        cout << "Task not found." << endl; // Task ID not found in the vector
    }
    void saveToFile(const string& filename) const {
        ofstream file(filename);
        for (const auto& task : tasks) {
            file << task.getID() << '\n' << task.getTitle() << '\n'
                 << task.getDescription() << '\n' << task.getStatus() << '\n';
        }
    }

    // Method to load tasks from a file
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        int id;
        string title, description, status;

        while (file >> id >> ws) {
            getline(file, title);
            getline(file, description);
            getline(file, status);
            tasks.emplace_back(id, title, description, status);
            nextID = max(nextID, id + 1);
        }
    }
};

int main() {
    int choice;
    TaskManager manager;
    while (true) {
        cout << "1. Add Task\n2. View Tasks\n3. Update Task\n4. Delete Task\n5. Save and Exit\n";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string title;
            string description;
            string status;
            cout << "Enter the title: " ;
            getline(cin,title);
            cout << "Enter the descritpion: " ;
            getline(cin,description);
            cout << "Enter the status: " ;
            getline(cin,status);
            manager.addTask(title,description,status);
        } else if (choice == 2) {
            manager.viewTasks();
        } else if (choice == 3) {
            int id;
            string title, description, status;
            cout << "Enter task ID to update: ";
            cin >> id;
            cin.ignore();
            cout << "Enter new title: ";
            getline(cin, title);
            cout << "Enter new description: ";
            getline(cin, description);
            cout << "Enter new status: ";
            getline(cin, status);
            manager.updateTask(id, title, description, status);
        } else if (choice == 4) {
            int id;
            cout<< "Enter the id you would like to delete";
            cin >> id;
            manager.deleteTask(id);
        } else if (choice == 5) {
            manager.saveToFile("tasks.txt");
            break;
        } else {
            cout << "This is an invalid choice" << endl;
        }
    }
    return 0;


}
