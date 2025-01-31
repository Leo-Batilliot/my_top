# my_top  
## Goal of the project  
Recode the top command using ncurses along with some of it's uses  
## User Inputs  
All of the flags have a unique usage and can be combined together :  
- **`U`** : only prints the processes started by the specified user
- **`d`** : changes the refresh rate (in seconds)
- **`n`** : the program will automaticaly close after refreshing n times
  
Here's a list of useful keys you can use while the programm is opened :  
- **`scroll down/down arrow`** scroll down through the list of processes  
- **`scroll up/up arrow`** scroll up through the list of processes  
- **`E`** cycle through different units of memory for processes  
- **`Shift+E`** cycle through different units of memory for the system section
- **`Q`** closes the program
## Usage
use **`make`** to create the **`my_top`** exectuable  

./my_top (+any flags in any order)  
examples :  
- **`./my_top`**  
    will display a top ncurse window with a default refresh rate of 3 seconds
- **`./my_top -U root -d 0.5 -n 20`**  
    will display a top with only root's processes a .5 refresh rate and will close after 20 refreshes
