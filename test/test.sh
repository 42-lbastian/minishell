red=$(tput setaf 1)
blue=$(tput setaf 4)
normal=$(tput sgr0)
magenta=$(tput setaf 5)

#!/bin/bash

function exec_cmd ()
{
	echo $@ | ./minishell &> ../1
	echo $@ | bash &> ../2
	DIFF=$(diff ../1 ../2)
	if [ "$DIFF" != "" ]
	then
		printf "${red}|%s| failed${normal}\n" "$@"
	fi
}

function exec_cmd_change ()
{
	echo $1 | ./minishell &> ../1
	echo $2 | bash &> ../2
	DIFF=$(diff ../1 ../2)
	if [ "$DIFF" != "" ]
	then
		printf "${red}|%s| failed${normal}\n" "$1"
	fi
}
clear

ps -p $$
printf "\n"

if [ $# == 0 ]
then
	make re
	exec_cmd 'echo toto'
	exec_cmd 'echo toto tata titi'
	exec_cmd 'echo toto tata titi -n'
	exec_cmd 'echo toto'
	exec_cmd 'echo'
	exec_cmd 'echo "toto"'
	exec_cmd 'echo '\''toto'\'''
	exec_cmd 'echo " "'
	exec_cmd 'echo '\'' '\'''
	exec_cmd 'echo ""'
	exec_cmd 'echo ! "" !'
	exec_cmd 'echo '\'''\'''
	exec_cmd 'echo ! '\'''\'' !'

	exec_cmd 'echo -n !toto tata titi!'
	exec_cmd 'echo -n !toto!'
	exec_cmd 'echo -n !""!'
	exec_cmd 'echo -n ! "" !'
	exec_cmd 'echo -n'


	exec_cmd "echo "\""$USER"\"""
	exec_cmd 'echo '\''$USER'\'''
	exec_cmd "echo $USER"

	exec_cmd "ls "\""$USER"\"""
	exec_cmd "ls "\""$TOTO"\"""
	exec_cmd 'ls '\''$USER'\'''

	exec_cmd "$USER"
	exec_cmd "$TOTO"
else
	printf "${magenta}Change\n\n${normal}"
	exec_cmd_change 'ls ~/Documents/\' 'ls ~/Documents/'
	exec_cmd_change 'ls ~/Docu\ments/' 'ls ~/Documents/'
	exec_cmd_change 'ls \~/Documents/' 'ls ~/Documents/'
	
	echo
	echo 'echo "to\"to"'
	echo 'cat << EOF(what you want)'
	echo '"toto'\'''
	echo ''\''toto"'

fi
