
|LEXER ->|PARSER ->|EXPANDER ->|EXECUTOR|
|--|--|--|--|


### TO-DO now : 
- Linked list for ENV (format :
	-  char	* var
	- char *value
	- t_list	*next
- Make signals work
	- CTRL-C	(New Prompt on a new line)
	- CTRL-D	(Exit the shell / only with an empty line)
	- CTRL-\		(do nothing)

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
