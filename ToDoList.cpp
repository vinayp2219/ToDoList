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
    string dueDate; // TAKEN FROM SYSTEM TODAY();
    string priority; // LOW MEDIUM HIGH
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
        cout << "Please add some task first to View";
    } else {
        cout << "\nTasks:\n";
        cout << "   " << "Task" << " " << "Category" << " " << "Priority" << " " << "DueDate" << " " << "Status" << " " << "Reminder" << "\n";

        // Sort the tasks based on priority level
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

void markTaskAsCompleted() {
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber >= 0 && taskNumber <= NotesAdded.size()) {
        NotesAdded[taskNumber - 1].completed = 1;
    } else {
        cout << "Invalid Task Number" << "\n";
    }
}

void deleteTask() {
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber >= 0 && taskNumber <= NotesAdded.size()) {
        NotesAdded.erase(NotesAdded.begin() + taskNumber - 1);
    } else {
        cout << "Invalid Task Number" << "\n";
    }
}

void setReminder() {
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber >= 0 && taskNumber <= NotesAdded.size()) {
        cout << "Enter the reminder time (HH:MM): ";
        cin >> NotesAdded[taskNumber - 1].reminderTime;
        NotesAdded[taskNumber - 1].reminder = true;
    } else {
        cout << "Invalid Task Number" << "\n";
    }
}

void filterTaskByCategory() {
    string categoryToFilter;
    cout << "Enter the category to filter: ";
    cin >> categoryToFilter;

    cout << "\nTasks in the " << categoryToFilter << " category:\n";
    cout << "   " << "Task" << " " << "Category" << " " << "Priority" << " " << "DueDate" << " " << "Status" << " " << "Reminder" << "\n";

    bool foundTasks = false;
    for (const auto& task : NotesAdded) {
        if (task.category == categoryToFilter) {
            foundTasks = true;
            cout << "- " << task.description << " "
                 << task.category << " "
                 << task.priority << " "
                 << task.dueDate << " "
                 << (task.completed ? "Completed" : "Pending") << " "
                 << (task.reminder ? task.reminderTime : "No") << "\n";
        }
    }

    if (!foundTasks) {
        cout << "No tasks found in the " << categoryToFilter << " category." << endl;
    }
}

void addtask() {
    string description;
    string category;
    string priority;

    cout << "Enter the Description\n";
    cin.ignore();
    getline(cin, description);

    auto now = time(nullptr);
    tm* current = localtime(&now);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", current);
    string dueDate(buffer);

    cout << "Choose a category: " << endl;
    for (size_t i = 0; i < categories.size(); ++i) {
        cout << i + 1 << ". " << categories[i] << endl;
    }

    int categoryChoice;
    cin >> categoryChoice;
    if (categoryChoice > 0 && categoryChoice <= categories.size()) {
        category = categories[categoryChoice - 1];
    } else {
        cout << "Invalid choice, defaulting to 'Other'" << endl;
        category = "Other";
    }

    cout << "Enter priority (HIGH/LOW/MEDIUM): ";
    cin >> priority;

    Task task(description, category, priority, dueDate);
    NotesAdded.push_back(task);
}

void displayMenu() {
    int choice;
    do {
        cout << "\nMenu:\n"
             << "1. Add Task\n"
             << "2. View Task\n"
             << "3. Mark Task as Completed\n"
             << "4. Delete Task\n"
             << "5. Set Reminder\n"
             << "6. Filter Task By Category\n"
             << "7. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addtask();
            break;
        case 2:
            displayTasks();
            break;
        case 3:
            markTaskAsCompleted();
            break;
        case 4:
            deleteTask();
            break;
        case 5:
            setReminder();
            break;
        case 6:
            filterTaskByCategory();
            break;
        case 7:
            cout << "Goodbye! Please do the tasks on time";
            break;
        }
    } while (choice != 7);
}

int main() {
    displayMenu();
    return 0;
}
