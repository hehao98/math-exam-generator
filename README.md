# math-exam-generator
#### Overview
This is my implementation of an exercise project from
*Build To Win: Effective Software Engineering* (ISBN 978-7-115-46076-9),
Chapter 1. It can randomly generate primary school level calculation
exercises into a TXT file with a variety of options.
I hope to practice several of the fundamental concepts in software
engineering in this project, get familiar with Personal Software Process,
and learn basic knowledge needed for developing individual projects.
#### Features
1. Can generate +, -, *, / calculation exercises with both integers and
fractions.
2. Allow generating an answer sheet along with the exam paper.
3. Allow expressions with more than two operands.
4. Can use brackets to generate more complex exercises.
#### Compile
1. This project is based on CMake. I personally use Clion for most of
the development, but it should also work well on any Unix-alike OS using 
CMake, since it only use standard C/C++ libraries and several POSIX APIs.
2. This program use `googletest` to create unit tests. The steps to
download, compile and link it are already included in the CMake script.
Ideally it should work automatically.
#### How to Use
Usage:
`math-exam-generator [--total num] [--minop num]
[--maxop num] [--minval num] [--maxval num] [--add] [--sub]
[--multi] [--div] [--frac] [> filename.txt]*`
For example:  
`math-exam-generator --total 10 --minop 2 --maxop 5 --minval -100
--maxval 100 --add --sub --multi --div --frac > paper.txt`
will generate an exam paper with 10 questions, each question
contains 2 operands at minimum, 5 operands at maximum, use numbers
ranging from \[-100, 100\], and can contain addition, subtraction,
multiplication, division and fractions. The result will be put into
standard output, and will be redirected to paper.txt. If any of the
parameters are missing or malformed, a default value will be used.
