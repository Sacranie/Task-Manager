# Task-Manager-Using-OOP
Task Manager in C++
Overview
This project is a Task Manager implemented in C++. It allows users to efficiently manage tasks with features to add, view, update, delete, and save tasks. The Task Manager ensures that your tasks are saved to a file, so they persist even after you exit the program and can be retrieved when you run the application again.

Features
Add Task: Users can add a new task by providing a title, description, and status.
View Tasks: Display all the tasks with their details, including ID, title, description, and status.
Update Task: Update the details of an existing task by providing its ID.
Delete Task: Remove a task from the list by providing its ID.
Save and Exit: Save all tasks to a file and exit the program. When the program is run again, it will load the tasks from the file.
How It Works
Adding a Task:

The user is prompted to enter the title, description, and status of the task.
The task is then added to the list with a unique ID.
Viewing Tasks:

The program displays all tasks in a formatted manner, showing their ID, title, description, and status.
Updating a Task:

The user provides the ID of the task to be updated.
The user then enters the new title, description, and status for the task.
The program updates the task details accordingly.
Deleting a Task:

The user provides the ID of the task to be deleted.
The program removes the task from the list if the ID matches.
Saving and Exiting:

All tasks are saved to a file named tasks.txt.
When the program starts, it loads tasks from tasks.txt if the file exists, ensuring continuity of task management.
