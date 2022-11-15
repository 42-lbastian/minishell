
|LEXER ->|PARSER ->|EXPANDER ->|EXECUTOR|
|--|--|--|--|


### TO-DO now :
- Makefile -> pass to CC instead of GCC
- Linked list for ENV (format :
	-  char	* var
	- char *value
	- t_list	*next
- Make signals work (!) must work for child processes too!
	- CTRL-C	(New Prompt on a new line) -> decided not to avoid "^C", to be faithful to bash.
	- CTRL-D	(Exit the shell / only with an empty line) -> Not done yet.
	- ~~CTRL-\		(do nothing)~~

### FOLLOW:
| builtins |
|--|
| cd |
| echo + echo -n |
| pwd |
| export |
| unset |
| env |
| exit |
