<h1 align="center">
📖 philosophers
</h1>

<p align="center">
	<b><i>I never thought philosophy would be so deadly</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/jlima91/get_next_line_42?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/jlima91/get_next_line_42?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/jlima91/get_next_line_42?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/jlima91/get_next_line_42?color=green" />
</p>

## ✏️ Summary
```
In this project, you will learn the basics of threading a process.
You will see how to create threads and you will discover mutexes.
```
## 💡 About the project

```
This project is a training to multi-threads/multi-process programming with the use of mutexes.
This project is a good lesson in C optimization as we need to save every bit of CPU usage we can to ensure
the survival of our philosophers.
```
This program simulates the famous [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem).

You can read the project subject [here](https://github.com/jlima91/philosophers_42/blob/master/philosophers.pdf).


## 🛠️ Usage

#### 1. Compiling the program

To compile, go to the program path and run:

```
make
``` 

#### 2. Executing the program

To execute the program, run:
```
$ ./philo arg1 arg 2 arg3 arg4 arg5
```
```
arg1 - The number of philosophers and also the number of forks
arg2 - Time to die (in milliseconds)
arg3 - Time to eat (in milliseconds)
arg4 - Time to sleep (in milliseconds)
arg5 - Number of times each philosopher must eat (optional argument)
```
