red=$(tput setaf 1)
normal=$(tput sgr0)

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=readline.supp ./a.out
printf "\n\n\t\t${red}WARNING Supress free readline return${normal}"
