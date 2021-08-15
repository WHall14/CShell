# CShell
Implementing a simple shell in C


Commands:
• calc expr. - prints out the result of the mathematical prefix expression that 
 comes after the command. 
• time - prints out the current local time and date 
• path - prints out the current working directory 
• sys - prints the name and version of the OS and CPU type 
• put dirname filename(s) [-f] – put files filenames in the directory dirname
• get filename - prints the content of the file filename to the screen 
• quit - ends the program



Notes: 
• If the command is not one of the above, you should print an error message and wait for a 
new command. 
• You can assume the expression after the calc command is a valid prefix expression 
containing only ‘+’ and ‘–‘ signs. You can also assume a space character separates any two 
numbers/signs. e.g. “+ + 2 3 - 4 5”. 
• Note that if you want to use the prefixadd() function from week 2 workshop you will need 
to store the expression as a ragged array of strings (see week 2 exercise 3). 
• time – you can use the functions defined in <time.h> (link). Hint: look at time(), 
localtime() and asctime() functions. 
• path - you can use the linux system function getcwd() (link). 
• put - The put command will create a new directory called dirname and copy the file (or 
files) listed in the command, in this directory. If the directory exists you should only print 
an error message, unless -f has been specified, in which case the directory will be 
completely overwritten (old content is deleted). If a file(s) doesn’t exist, you will need to 
print a ‘file not found’ message for that file. 
• get - The get command will dump the file contents to the screen 40 lines at a time and 
pause, waiting for a key to be pressed before displaying the next 40 lines etc. 
