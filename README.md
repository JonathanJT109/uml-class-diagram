# UML Class Diagram
This is a project that takes `C++` code and creates a class diagram. In other
words, it is a transpiler from `C++` to `Mermaid`.

## How to Use
The program takes 2 arguments, one required and the other optional. The first
argument is the input file, the program will take the input file name as the main
source to generate the tokens. The second argument (optional) is the output
file name which the program will use to show the ouput, if none is given then
the program will output the result in the terminal.


## Example
If you look at the directory, there are already two files: `input.txt` `output.txt`
If you look into the first file, `input.txt`, you will see that there is
already code in the file:

```
<input.txt>
var a = 5
var b = 10 * 3
var c = 3 (10 / 5.5) + a * b

print(c)
```
You can change this file to whatever you would like to test. To "tokenize," use
the lexer, you can call the executable and pass the name of the file as the 
first argument

```
./bin/umlClassDiagram input.txt
```

If you look at your terminal, you should hopefully see the tokens for each line:

```
var a = 5
^^^ (IdentifierToken, "var", 0 -> 3, line: 0)
    ^ (IdentifierToken, "a", 4 -> 5, line: 0)
      ^ (EqualToken, "=", 6 -> 7, line: 0)
        ^ (IntegerToken, "5", 8 -> 9, line: 0)
          (EndOfLineToken, "\n", 9 -> 10, line: 0)
var b = 10 * 3
^^^ (IdentifierToken, "var", 0 -> 3, line: 1)
    ^ (IdentifierToken, "b", 4 -> 5, line: 1)
      ^ (EqualToken, "=", 6 -> 7, line: 1)
        ^^ (IntegerToken, "10", 8 -> 10, line: 1)
           ^ (AsteriskToken, "*", 11 -> 12, line: 1)
             ^ (IntegerToken, "3", 13 -> 14, line: 1)
               (EndOfLineToken, "\n", 14 -> 15, line: 1)
var c = 3 (10 / 5.5) + a * b
^^^ (IdentifierToken, "var", 0 -> 3, line: 2)
    ^ (IdentifierToken, "c", 4 -> 5, line: 2)
      ^ (EqualToken, "=", 6 -> 7, line: 2)
        ^ (IntegerToken, "3", 8 -> 9, line: 2)
          ^ (LeftParenToken, "(", 10 -> 11, line: 2)
           ^^ (IntegerToken, "10", 11 -> 13, line: 2)
              ^ (SlashToken, "/", 14 -> 15, line: 2)
                ^^^ (FloatToken, "5.5", 16 -> 19, line: 2)
                   ^ (RightParenToken, ")", 19 -> 20, line: 2)
                     ^ (PlusToken, "+", 21 -> 22, line: 2)
                       ^ (IdentifierToken, "a", 23 -> 24, line: 2)
                         ^ (AsteriskToken, "*", 25 -> 26, line: 2)
                           ^ (IdentifierToken, "b", 27 -> 28, line: 2)
                             (EndOfLineToken, "\n", 28 -> 29, line: 2)

 (EndOfLineToken, "\n", 0 -> 1, line: 3)
print(c)
^^^^^ (IdentifierToken, "print", 0 -> 5, line: 4)
     ^ (LeftParenToken, "(", 5 -> 6, line: 4)
      ^ (IdentifierToken, "c", 6 -> 7, line: 4)
       ^ (RightParenToken, ")", 7 -> 8, line: 4)
         (EndOfLineToken, "\n", 8 -> 9, line: 4)
<End of File>

```

If you want to save the file, you can pass a second argument, the outpu file
name. If you look at the directory there is already a file with the name 
`output.txt`. It has the same result as the one with no arguments. You can try
saving the tokens in a file doing the following:

```
./bin/umlClassDiagram input.txt output.txt
```

If you go into the `output.txt`, you should see the result

```
<output.txt>
var a = 5
^^^ (IdentifierToken, "var", 0 -> 3, line: 0)
    ^ (IdentifierToken, "a", 4 -> 5, line: 0)
      ^ (EqualToken, "=", 6 -> 7, line: 0)
        ^ (IntegerToken, "5", 8 -> 9, line: 0)
          (EndOfLineToken, "\n", 9 -> 10, line: 0)
var b = 10 * 3
^^^ (IdentifierToken, "var", 0 -> 3, line: 1)
    ^ (IdentifierToken, "b", 4 -> 5, line: 1)
      ^ (EqualToken, "=", 6 -> 7, line: 1)
        ^^ (IntegerToken, "10", 8 -> 10, line: 1)
           ^ (AsteriskToken, "*", 11 -> 12, line: 1)
             ^ (IntegerToken, "3", 13 -> 14, line: 1)
               (EndOfLineToken, "\n", 14 -> 15, line: 1)
var c = 3 (10 / 5.5) + a * b
^^^ (IdentifierToken, "var", 0 -> 3, line: 2)
    ^ (IdentifierToken, "c", 4 -> 5, line: 2)
      ^ (EqualToken, "=", 6 -> 7, line: 2)
        ^ (IntegerToken, "3", 8 -> 9, line: 2)
          ^ (LeftParenToken, "(", 10 -> 11, line: 2)
           ^^ (IntegerToken, "10", 11 -> 13, line: 2)
              ^ (SlashToken, "/", 14 -> 15, line: 2)
                ^^^ (FloatToken, "5.5", 16 -> 19, line: 2)
                   ^ (RightParenToken, ")", 19 -> 20, line: 2)
                     ^ (PlusToken, "+", 21 -> 22, line: 2)
                       ^ (IdentifierToken, "a", 23 -> 24, line: 2)
                         ^ (AsteriskToken, "*", 25 -> 26, line: 2)
                           ^ (IdentifierToken, "b", 27 -> 28, line: 2)
                             (EndOfLineToken, "\n", 28 -> 29, line: 2)

```

## Edit
Ideally, to use the program you would only need to clone the repo and use the
executable located in the bin directory. However, if you want to change the
source code, you can install `CMake`, then, go to the build directory and
follow the next steps:

```
cd build
cmake ..
cmake --build .
cd ..
```

Hopefully, you will be able to see the executable located in the bin directory.

## Inspiration
[vim9jit](https://github.com/tjdevries/vim9jit)

[Simple C++ Lexer](https://gist.github.com/arrieta/1a309138689e09375b90b3b1aa768e20)

[Building a Compiler](https://www.youtube.com/watch?v=wgHIkdUQbp0&list=PLRAdsfhKI4OWNOSfS7EUu5GRAVmze1t2y)
