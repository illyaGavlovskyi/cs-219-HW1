CS 219 Programming Project 2

to run this code you will run make and ./adder in the terminal.

the data that is stored inside data.txt will be read in. It has to be in the format of OPERATION first Hexadecimal second Hexadecimal.

This program from the start declares 3 strings and 3 uint32_t data type variables. strings are used by gettline to extract data from a file. I start by opening an ifstream and checking if it opens, if not program returns 0. After that, a while loop opens that runs until the file is empty. 

Every iteration starts by emptying all 3 strings to ensure that no extra data in the output. The data is collected using getlines. to convert string to uint32_t i used stoul( ). If (ADD, AND, ORR, SUB, XOR, ASR, LSR,LSL, NOT, ADDS, ANDS, ORRS, SUBS XORS, ASRS, LSRS, LSLS, NOTS) operation is selected the code keeps running otherwise program ends. a variable of type stringstream from sstream library gets created and a function <<hex<< is used to convert a hexadecimal number to a string type. after that, I create a string that gets set to a value from the stringstream with the use of .str(). this allows to use cout and displays the correct value to the user. 

But before that, there is another function that is made to set all the values inside the string to the upper case to have the correct format. 