<h1 align="center"> push_swap </h1>
<h4 align="center"> As beautiful as a shell </h4>

<h5 align="center">
  <a href="#description_id">Description</a> - 
  <a href="#usage_id">Usage</a> - 
  <a href="#credits_id">Ressource</a>
</h5>

---

<h2 id="description_id"> Description of the project: </h2>

The objective of this project is to create a simple shell. We have to implement redirections and pipe, manage quotes and double quotes and handle environment variables and signals (for ctrl c - ctrl d and ctrl \). We also have to code this builtins:
- ```echo``` with -n flag
- ```cd``` with only a relative or absolute path
- ```pwd```
- ```export```
- ```unset```
- ```env```
- ```exit```

We also learned how to make a suppression file for valgrind because the function readline used for catching input has memory leaks.

<h2 id="usage_id"> Usage: </h2>

#### Compilation: (in the folder that contain the makefile)
```shell
make
```

Then 
```shell
./minishell
```

You're in our minishell


<h2 id="credits_id"> Credits </h2>

This project was made with <a href="https://github.com/krozis">krozis</a>

I was responsible for the lexer/parser, environement variable, redirections and pipe and execution of command or builtins

Krozis was in charge of signals, builtins and he help me a lot with git
