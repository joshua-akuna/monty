# The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty bytes codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty bytes code files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

Monty byte code files can contain blank lines (empty or made of spaces only), and any additional text after the opcode or its required argument is not taken into account.

## The monty program
* Usage: _monty file_
> where _file_ is the path to the file containing Monty byte code.

* If the user does not give any file or more than one argument to the program, print the error message _Usage: monty file_, followed by a new line, and exit with the status _EXIT_FAILURE_.

* If, for any reason, it's not not possible to open the file, print the error message _Error: Can't open file <file>_, followed by a new line, and exit with the status code _EXIT_FAILURE_.
> where _file_ is the name of the file.
