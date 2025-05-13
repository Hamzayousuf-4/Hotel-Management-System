
```
# 🏨 Hotel Management System

A complete console-based **Hotel Management System** built in C++ using object-oriented programming principles and file handling.  
This project simulates hotel operations including room booking, customer management, staff management, billing, and complaint tracking.

---

## 📋 Features

- **Owner, Manager, Receptionist login system**
- **Room management**
  - Assign AC / NON-AC rooms
  - Track room availability
- **Customer management**
  - Add guest details
  - View guest list
- **Billing system**
  - Auto-generated unique invoice numbers
- **Complaint recording**
- **File-based persistent storage (.dat files)**

---

## 🎭 Role-Based Access

| Role | Features |
|------|----------|
| Owner | Appoint/Remove Managers, View Room Info, View Guest Info, View Bills, View Complaints |
| Manager | Appoint/Remove Receptionists, View Room Info, View Guest Info, View Bills, Record Complaints |
| Receptionist | Check Room Availability, Add Customer, Generate Bill, Customer Checkout, View Guest Info |

---

## 📂 Project Structure

Hotel-Management-System/
├── HMS.h          → Header file with all class definitions  
├── SETUP.cpp      → System setup (reset files, initialize rooms, create owner account)  
├── final.cpp      → Main Hotel Management System (all role-based functionality)  
├── Bills.dat, Complains.dat, Invoice.dat, Manager.dat, Owner.dat, receptionistfile.dat, Rooms.dat, UNIQUE_ID.dat → Data files  
└── README.md  

---

## 🛠️ Technologies Used

- C++ (OOP concepts, file handling, inheritance, polymorphism)
- Console application
- Windows (system-specific commands like system("CLS"), system("COLOR"))

---

## 🖥️ How to Compile and Run

### 🔧 1. Setup

Make sure you have a C++ compiler installed:
- Windows → MinGW-w64
- Linux/macOS → g++

### 📝 2. Compile

First, run setup:
```

g++ SETUP.cpp -o setup.exe
setup.exe

```

Then, run the main system:
```

g++ final.cpp -o hotel.exe
hotel.exe

```

### ⚠️ Note:
This program is designed for **Windows console**. It uses system("CLS") and system("COLOR").

---

## 💡 Data Files

All `.dat` files are stored in the same folder as the code:
- Bills.dat
- Complains.dat
- Invoice.dat
- Manager.dat
- Owner.dat
- receptionistfile.dat
- Rooms.dat
- UNIQUE_ID.dat

These files are generated automatically by the program or can be provided for demonstration.

---

## 👨‍💻 Author

**Hamza Yousuf**  
FAST NUCES - Cyber Security Student  

---

## 📜 License

This project is intended for educational and academic purposes.  
No commercial use allowed without permission.
```


