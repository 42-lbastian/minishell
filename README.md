
|LEXER ->|PARSER ->|EXPANDER ->|EXECUTOR|
|--|--|--|--|


### TO-DO now :
- Make signals work (!) must work for child processes too!
	- ~~CTRL-C	(New Prompt on a new line)~~
	- CTRL-D	(Exit the shell) -> Need error code + child processus gestion + fix bug when buffer is not empty (exit written but not leaving)
	- ~~CTRL-\		(do nothing)~~

### ON WORK :
- Can it work for exit_code ??

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
