# (IIT2015036) ppl-assignment 
ppl-assignment-CosmicCoder96 **(Abhinav Khare)**  created by GitHub Classroom

##About

>This project is an assignment for the Principal of Programming Languages course. It emphasises on Object Oriented Design and has been written in C++. Currently it holds the solution of *Questions 1 and 2.*

##Environment

>This project was built on  MAC OS Sierra *Version 10.12.3 (16D32)* Text Editor used was sublime text 3 and command line tools were used.
The documentation for the assignment can be found in Documentaion.pdf file and class diagram as under Class_Diagram.pdf.
C++ 
###g++ version
>4.2.1 Compatible Apple LLVM 8.0.0 (clang-800.0.42.1)


## How to run?


### Question 1
>First step would be to genereate a random list of boys and girls 
```
g++ generate-girls.cpp -o data-girls
./data-girls
g++ generate-boys.cpp -o data-boys
./data-boys
```
>To run question 1
```
g++ 1.cpp Couple.cpp MakeCouples.cpp Boy.cpp Girl.cpp
./a.out
```
>The generated couples will be stored in List_of_Couples.txt
  
### Question 2
>**Ignore if already done for question 1** : Generate random list of boys and girls
```
g++ generate-girls.cpp -o data-girls
./data-girls
g++ generate-boys.cpp -o data-boys
./data-boys
```
>Generate random gifts
```
g++ generate-gifts.cpp -o data-gifts
./data-gifts
```
>To run Querstion 2
```
g++ 2.cpp Couple.cpp MakeCouples.cpp Boy.cpp Girl.cpp
```

## Logging details
> ###General text files (Get recreated when the questions are run)
  * List of randomly generated boys : List_of_boys.txt
  * List of randomly generated girls : List_of_Girls.txt
  * List of randomly generated gifts : List_of_Gifts.cpp
  * List of generated couples : List_of_Gifts.txt
  * List of gifts given : List_of_Gifts_Given.txt
 >###Logging (Log file is permanent and maintains logs of all the executions)
 >It Maintains all the transactions which take place and logs them with timestamp. 
 
  **General Log** : Log.txt
