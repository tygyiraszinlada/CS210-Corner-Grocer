# Corner Grocer Item Tracking Program

### Overview
This project was developed in C++ for CS 210. The goal was to build a program that tracks how often grocery items are purchased throughout the day. The program reads from an input file, counts each item using a map data structure, and allows the user to interact with the results through a simple menu system.

This project helped me better understand how data flows through a program — from file input, to storage, to user interaction.

### Program Features
- Search for how many times a specific item was purchased  
- Display all items and their purchase frequencies  
- View a histogram representation of item frequency  
- Generate a backup data file  

### Portfolio Reflection

### What Problem Was This Solving?
This program simulates a realworld scenario where a store might want to track item popularity. Instead of manually counting purchases, the system reads data from a file and automatically calculates frequency totals. It demonstrates practical use of file input/output and data structures to solve a realistic business problem.

### What I Did Well
One thing I did particularly well in this project was breaking the program into clear, focused functions instead of placing everything inside `main()`. Separating tasks like reading the file, searching for items, displaying results, and building the histogram made the program easier to understand and maintain.

I also focused on:
- Writing clear and descriptive variable names  
- Keeping formatting consistent  
- Making the menu easy to navigate  
- Verifying that file data was processed correctly  

Using `map<string, int>` made counting items efficient and simplified the logic significantly.

### Areas for Improvement
While the program works as intended, there are definitely areas where I could improve it. For example, I could add stronger input validation to handle unexpected user input more gracefully. I could also improve file error handling in case the input file is missing or corrupted.

If I were to expand this project further, I would likely convert it into a class based design to make it more scalable and modular. These improvements would make the program more robust and closer to production level quality.

### Most Challenging Part
The most challenging part of this project was making sure the file input was processed correctly and that the map stored accurate counts without overwriting values. Debugging required stepping through the logic carefully and testing different scenarios to confirm the results matched expectations.

Working through those challenges helped me gain confidence using STL containers and file streams in C++.

### Transferable Skills
This project strengthened several skills that are transferable to future coursework and real world development:

- Working with STL data structures  
- File handling and data processing  
- Modular program design  
- Debugging and logical problem solving  
- Writing readable, maintainable code  

Overall, this project reinforced the importance of structure, clarity, and planning when building software.

### How to Run
1. Compile the program using a C++ compiler.
2. Make sure the input file is in the same directory.
3. Run the executable.
4. Follow the menu prompts.
