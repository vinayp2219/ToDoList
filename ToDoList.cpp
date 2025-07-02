#include <iostream>
#include <cstdlib>
#include <cmath>
#include <bits/stdc++.h>
#include <ctime>

using namespace std;

class Task {
public:
    string description;
    string category;
    bool completed;
    string dueDate;
    string priority;
    bool reminder;
    string reminderTime;
    int priorityLevel;

    Task(string description, string category, string priority, string dueDate) {
        this->description = description;
        this->category = category;
        this->dueDate = dueDate;
        this->priority = priority;
        this->completed = false;
        this->reminder = false;
        this->reminderTime = "";
        this->setPriorityLevel();
    }

    void setPriorityLevel() {
        if (priority == "HIGH") {
            priorityLevel = 3;
        } else if (priority == "MEDIUM") {
            priorityLevel = 2;
        } else {
            priorityLevel = 1;
        }
    }
};

vector<Task> NotesAdded;
vector<string> categories = {"Work", "Personal", "Study", "Shopping", "Other"};

void displayTasks() {
    if (NotesAdded.empty()) {
        cout << "Please add some task first to View\n";
    } else {
        cout << "\nTasks:\n";
        cout << "   " << "Task" << " " << "Category" << " " << "Priority" << " " << "DueDate" << " " << "Status" << " " << "Reminder" << "\n";

        sort(NotesAdded.begin(), NotesAdded.end(), [](const Task& a, const Task& b) {
            return a.priorityLevel > b.priorityLevel;
        });

        for (int i = 0; i < NotesAdded.size(); i++) {
            cout << i + 1 << ". "
                 << NotesAdded[i].description << " "
                 << NotesAdded[i].category << " "
                 << NotesAdded[i].priority << " "
                 << NotesAdded[i].dueDate << " "
                 << (NotesAdded[i].completed ? "Completed" : "Pending") << " "
                 << (NotesAdded[i].reminder ? NotesAdded[i].reminderTime : "No") << "\n";
        }
    }
}

void addSampleTask(string description, string category, string priority) {
    auto now = time(nullptr);
    tm* current = localtime(&now);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", current);
    string dueDate(buffer);

    Task task(description, category, priority, dueDate);
    NotesAdded.push_back(task);
}

void interactiveMenu() {
    int choice;
    do {
        cout << "\nMenu:\n"
             << "1. Add Task\n"
             << "2. View Task\n"
             << "3. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string description, priority;
                int cat;
                cout << "Enter description: ";
                cin.ignore();
                getline(cin, description);
                cout << "Choose category:\n";
                for (int i = 0; i < categories.size(); i++) {
                    cout << i + 1 << ". " << categories[i] << "\n";
                }
                cin >> cat;
                string category = (cat > 0 && cat <= categories.size()) ? categories[cat - 1] : "Other";
                cout << "Enter priority (HIGH/MEDIUM/LOW): ";
                cin >> priority;
                addSampleTask(description, category, priority);
                break;
            }
            case 2:
                displayTasks();
                break;
            case 3:
                cout << "Goodbye! Please do the tasks on time\n";
                break;
        }
    } while (choice != 3);
}

int main() {
#ifdef JENKINS
    addSampleTask("Finish Jenkins setup", "Work", "HIGH");
    addSampleTask("Write C++ report", "Study", "MEDIUM");
    displayTasks();
    cout << "Automated Jenkins run completed.\n";
#else
    interactiveMenu();
#endif
    return 0;
}
