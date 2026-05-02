# 🏥 Hospital Queue Management System

A priority-based patient queue system written in C using a **linked list** data structure. Emergency patients are automatically placed ahead of normal patients, ensuring critical cases are always treated first.

---

## Features

- **Priority Queue** — Emergency patients (priority 1) are always served before Normal patients (priority 2)
- **Add Patients** — Register new patients with an ID, name, and priority level
- **Treat Patients** — Dequeue and treat the highest-priority patient at the front
- **Display Queue** — View all patients currently waiting in order
- **Search** — Look up a patient by their ID
- **Update** — Modify a patient's name or priority while they're in the queue

---

## Data Structure

The system uses a **singly linked list** sorted by priority:

```
[Emergency Patient] → [Emergency Patient] → [Normal Patient] → [Normal Patient] → NULL
```

Each node represents a patient:

```c
struct Patient {
    int id;           // Unique patient identifier
    char name[50];    // Patient name
    int priority;     // 1 = Emergency, 2 = Normal
    struct Patient* next;
};
```

---

## Getting Started

### Prerequisites

- GCC compiler (or any C compiler)

### Compile

```bash
gcc hospital_queue.c -o hospital_queue
```

### Run

```bash
./hospital_queue
```

---

## Usage

When you run the program, you'll see this menu:

```
--- Hospital Queue System ---
1. Add Patient
2. Treat Patient
3. Display Patients
4. Search Patient
5. Update Patient
6. Exit
```

### Example Walkthrough

**Add an emergency patient:**
```
Enter choice: 1
Enter ID: 101
Enter Name: Alice
Enter Priority (1 Emergency / 2 Normal): 1
Patient added successfully!
```

**Add a normal patient:**
```
Enter choice: 1
Enter ID: 102
Enter Name: Bob
Enter Priority (1 Emergency / 2 Normal): 2
Patient added successfully!
```

**Display the queue:**
```
--- Patient Queue ---
ID: 101 | Name: Alice | Priority: Emergency
ID: 102 | Name: Bob   | Priority: Normal
```

**Treat the next patient (always highest priority first):**
```
Enter choice: 2
Treating Patient: Alice (ID: 101)
```

---

## Priority Logic

| Priority | Label     | Description                          |
|----------|-----------|--------------------------------------|
| `1`      | Emergency | Inserted at the front of the queue   |
| `2`      | Normal    | Inserted after all emergency patients|

When multiple patients share the same priority, they are served in **FIFO order** (first added, first served).

---

## Limitations

- Names cannot contain spaces (uses `scanf("%s", ...)`)
- Priority is binary — only `1` (Emergency) or `2` (Normal) is supported
- The `updatePatient` function modifies the patient's data in-place but does **not** re-sort the queue after a priority change
- No persistent storage — all data is lost when the program exits

---

## File Structure

```
.
└── hospital_queue.c    # All source code in a single file
```

---

## License

This project is open source and available for educational use.
