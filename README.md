# get_next_line

The aim of this project is to make you code a function that returns a line ending with a newline ('\n'), read from a file descriptor.
Things that you will learn, or at least that I have learnt, in this project:
  - Difference between __*common*__ and __*static variables*__
  - Part of UNIX System Interface, or how to use a __*file descriptor*__ to __*read*__ a file
  - Everything is a file in UNIX

# Installation

Clone the repository to a directory.

```

git clone https://github.com/ytanne/get_next_line get_next_line

```
Run the following command to clone [libft repository](https://github.com/ytanne/libft) inside the folder.
(This is important, otherwise it will not work)

```

cd get_next_line && git clone https://github.com/ytanne/libft libft

```

To test the function, create a text file to read and run the following command with the name of your file instead of {NAME\_OF\_YOUR\_FILE}.

```

make && ./test {NAME_OF_YOUR_FILE}.txt

```

Voila, you get the first line, most likely ended with a new line, of text in your file.

# Uninstallation

To clean up the mess after the make run the following.

```

make fclean

```

Optional

```

cd .. && rm -rf get_next_line

```

# Final note

Thanks for reading! 
I spend some time on this project, and I am glad that you read until the end of README :D
![](https://socialnewsdaily.com/wp-content/uploads/2016/03/4f7d3b4ce8695b31c2305d1f53eb161afb7d25b1.jpg)
