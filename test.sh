red=$(tput setaf 1)
blue=$(tput setaf 4)
normal=$(tput sgr0)
magenta=$(tput setaf 5)

#!/bin/bash

function exec_cmd ()
{
	echo $@ | ./minishell/minishell &> 1

	printf "minishell> %s\n" "$@" > 2
	#echo $@ | bash --posix &>> 2
	echo $@ | bash &>> 2
	printf "minishell> " >> 2
	
	DIFF=$(diff 1 2)
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

	#ECHO

	exec_cmd 'echo toto'
	exec_cmd 'echo toto tata titi'
	exec_cmd 'echo toto tata titi -n'
	exec_cmd 'echo toto'
	exec_cmd 'echo'
	exec_cmd 'echo "toto"'
	exec_cmd 'echo t"toto"'
	exec_cmd 'echo t" toto"'
	exec_cmd 'echo t"  toto"'
	exec_cmd 'echo '\''toto'\'''
	exec_cmd 'echo " "'
	exec_cmd 'echo "   "'
	exec_cmd 'echo "   t"'
	exec_cmd 'echo '\'' '\'''
	exec_cmd 'echo ""'
	exec_cmd 'echo '\'''\'''

	exec_cmd 'echo -n toto tata titi'
	exec_cmd 'echo -n toto'
	exec_cmd 'echo - toto'
	exec_cmd 'echo -toto'
	exec_cmd 'echo -nnnnnnnnnnn toto'
	exec_cmd 'echo -ntoto'
	exec_cmd 'echo -n'

	#exec_cmd "echo "\""$USER"\"""
	#exec_cmd 'echo '\''$USER'\'''
	#exec_cmd "echo $USER"
	#exec_cmd 'echo \$USER'
	#exec_cmd 'echo '\''$US"ER'\'''

	#exec_cmd '"echo" toto'
	#exec_cmd ''\''echo'\'' toto'
	#exec_cmd 'echo '\''"toto"'\'''
	exit 1

	#PWD
	exec_cmd 'pwd'

	#exec_cmd "$USER"
	#exec_cmd "$TOTO"
else
	printf "${magenta}Change\n\n${normal}"
	#exec_cmd_change 'ls ~/Documents/\' 'ls ~/Documents/'
	#exec_cmd_change 'ls ~/Docu\ments/' 'ls ~/Documents/'
	#exec_cmd_change 'ls \~/Documents/' 'ls ~/Documents/'
	
	echo
	echo 'echo "to\"to"'
	echo 'cat << EOF(what you want)'
	echo '"toto'\'''
	echo ''\''toto"'
	echo './minishell'

fi
