# Task Manager

A simple command-line task manager written in C. Tasks are stored in memory while the program is running.

## Features

- Show all tasks
- Show pending tasks
- Show completed tasks
- Add a task (name, description, date)
- Delete a task by name
- Mark a task as completed by name

## Requirements

- A C compiler (GCC or Clang)

## Build and Run

```bash
gcc -Wall -Wextra -o task_manager task_manager.c
./task_manager
```

## Usage

The program displays a menu. Type the number of an option and press Enter.

```
1. Show all Tasks
2. Show Pending Tasks
3. Show Completed Tasks
4. Add Task
5. Delete Task
6. Complete Task
7. Exit
```

When adding a task, you are asked for:

| Field       | Format       | Max length |
|-------------|--------------|------------|
| Name        | Text         | 99         |
| Description | Text         | 299        |
| Date        | YYYY-MM-DD   | 19         |

To delete or complete a task, type its exact name when prompted.

## Limitations

- Maximum of 20 tasks.
- Tasks are not saved: they are lost when the program exits.
- Task names are matched exactly, including case.

## Project Structure

```
task_manager.c   Source code
README.md        This file
```
