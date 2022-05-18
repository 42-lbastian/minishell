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

make re
clear

ps -p $$
printf "\n"

#echo
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


exec_cmd 'echo "$USER"'
exec_cmd 'echo '$USER''
exec_cmd 'echo $USER'
exec_cmd 'ls "$USER"'
exec_cmd 'ls '$USER''
exec_cmd '$USER'

exec_cmd 'ls ~/Documents'
exec_cmd 'ls ~/\Documents'
exec_cmd 'ls ~/Docum\ents'
exec_cmd 'ls \~/Documents'



printf "\n\n${magenta}A tester\n\n${normal}"
echo 'ls ~/Documents/\'
