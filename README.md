# 🏠 Hostel Management System

A complete hostel management system with both **Web-based UI** and **CLI (C++)** versions.

## 📁 Project Structure

| Component | Technology | Description |
|-----------|------------|-------------|
| Web App | HTML/CSS/JS | Modern dashboard with student, room, fee, and maintenance management |
| CLI App | C++ | Console-based version with OOP concepts |
| Data Storage | JSON | Persistent data storage for the web app |

## ✨ Features

### Web Application
- **Dashboard** - Real-time statistics and overview
- **Student Management** - Add, edit, delete students
- **Room Management** - Table/Grid views, add/remove rooms
- **Room Allocation** - Assign students to available rooms
- **Fee Management** - Track payments per student
- **Maintenance Requests** - Submit and resolve issues
- **Warden Panel** - Overview of hostel operations
- **Data Export** - Export all data as JSON

### CLI Application (C++)
- Object-Oriented design with inheritance
- Student registration and room allocation
- Fee payment tracking
- Maintenance request system
- Polymorphic room types (Single/Double)

## 🚀 How to Run

### Web Application
1. Clone the repository
2. Navigate to `web-app/` folder
3. Open `index.html` in any modern browser
4. Data persists in browser's localStorage

### CLI Application
```bash
cd cli-app
g++ main.cpp -o hostel
./hostel
