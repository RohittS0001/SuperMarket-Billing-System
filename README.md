# Supermarket Billing System

## 📌 Description
The **Supermarket Billing System** is a simple console-based C++ program that helps in managing a small store’s billing process. It allows users to:
- Add new items to inventory
- Generate a new bill
- Display remaining stock
- Clear all data
- Exit the program

This system uses **file handling** to store inventory data persistently.

## 💻 Features
- **Add Items to Inventory** 🛒
- **Generate a New Bill** 🧾
- **Display Remaining Stock** 📦
- **Clear Inventory Data** ❌
- **Exit the System** 🔚

## 📂 File Handling
This project uses file handling to store and retrieve inventory data:
- Inventory items are stored in `billing_system1.txt`.
- A temporary file `bill_temp.txt` is used to update stock after billing.

## 🚀 Installation & Setup
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/supermarket-billing-system.git
   ```
2. Open the project folder.
3. Compile and run the C++ file:
   ```sh
   g++ billing_system.cpp -o billing_system.exe
   billing_system.exe
   ```
   *(Ensure you have `g++` installed or use any C++ compiler like MinGW or Visual Studio Code.)*

## 📝 Usage
1. **Run the program** and follow the on-screen menu.
2. **Choose an option:**
   - Press `1` to add items to inventory.
   - Press `2` to generate a bill.
   - Press `3` to view remaining stock.
   - Press `4` to clear all data.
   - Press `5` to exit the system.
3. **Inventory data is saved** in `billing_system1.txt`.

## ⚠️ Requirements
- Windows OS (for `Sleep()` function) or modify it for Linux/Mac.
- C++ Compiler (g++, MinGW, or Visual Studio Code).

## 🤝 Contributing
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -m 'Added new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a Pull Request.

## 📜 License
This project is open-source and available under the **MIT License**.

---
💡 **Created by [RohittS0001]** | ✨ Happy Coding!

