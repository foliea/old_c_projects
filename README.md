# Old C Projects

Projects I did a few years ago (between 2009 and 2010) when I was a student.

Using C standard library was forbidden for some project so I reinvented the wheel a few times.

I used to work on FreeBSD when I did this projects. Some are also working
under other Linux/Unix environments, but unfortunatly some don't. 

## bsq

Find the biggest square in a map.

  `./bsq map_file`
  
Check `test.txt` to see a map file example.

You can also activate the color mode :

  `./bsq -colors map_file`

## get_next_line

This project is a function that returns a line read from a ﬁle
descriptor.
  
  ```c
  char *get_next_line(const int fd);
  ```
  
## grimly


## lemipc


## malloc

My own malloc implementation.

[man malloc](http://www.freebsd.org/cgi/man.cgi?query=malloc&sektion=9)

## minitalk

The communication between the client and the server only uses signals.
The server is able to handle various clients following each others.
Only allowed to use the signals SIGUSR1 and SIGUSR2.

  ```
  $ ./server
  PID=7845
  ```
  
  ```
  $ ./client 7845 "This is a message"
  ```
  
The server will then display "This is a message".

## mud

A simple multi-user dungeon server.

## my_ftp

A simple ftp server with a command-line client

## my_irc

A simple irc server with a gtk client.

## my_libc

My own implementation of the C standard library.

## my_ls

My own system function ls [-lRdrt] [FILE]

[man ls](http://www.freebsd.org/cgi/man.cgi?query=ls&apropos=0&sektion=1&manpath=Red+Hat+Linux%2Fi386+9&format=html)

## my_printf

My own implementation of the printf function from the C library.

  ```c
  int my_printf(const char * restrict format, ...);
  ```
  
[man printf](http://www.freebsd.org/cgi/man.cgi?query=printf&sektion=3)

## my_select

A termcaps item selector. It takes the parameters and convert them into a selectable list.

  ```
  $ ./my_select "lol" "test "etc"
  lol
  test
  etc
  ```
  
`SPACE`: Select an item.
`ENTER`: Display selected items on standard ouput.

## mysh

My own unix shell.

This project handle the ’;’, the pipes ’|’ and the four redirections ’>’, ’<’, ’»’ and ’«’.

  `$ ./mysh`

## ntn

Display a number in french.

  ```
  $ ./ntn 42
  quarante-deux
  ```
  
## philosophes

A solution to the [dining philosophers](http://en.wikipedia.org/wiki/Dining_philosophers_problem) problem.

  `$ ./philosophes`



## push_swap

This program take the parameters as a list of parameters
(no doubles, all numbers are valid and ﬁt in an integer). This program display the
series of operations allowing to sort the list. Operations are displayed separated by a
space, no space at the start or the end, and with a newline at the end. The goal is to
sort the list with the fewest operations possible.

  ```
  $ ./push_swap 2 1 3 6 5 8
  sa pb pb pb sa pa pa pa
  ```
  
## sudoki-bi

A sudoku solver.
Check `test.txt` to see a map file example.
You can chain one or many maps in the same file.

  `$ ./sudoki-bi map_file`

## zappy
