#!bin/sh

if [ "${BASH_SOURCE[0]}" != "" ]; then
    # This should work in bash.
    _src=${BASH_SOURCE[0]}
elif [ "${ZSH_NAME}" != "" ]; then
    # And this in zsh.
    _src=${(%):-%x}
elif [ "${1}" != "" ]; then
    # If none of the above works, we take it from the command line.
    _src="${1/setup.sh/}/setup.sh"
else
    echo -e "\033[1;31mERROR:\033[0m Could not determine the base directory of ConvertToROOT, i.e. where \"setup.sh\" is located."
    return 1
fi

location="$(cd -P "$(dirname "${_src}")" && pwd)"
unset _src

echo -e "\n******************************************************"
echo -e "*External tool to convert CSV files to ROOT files    *"
echo -e "*Developed by Anil Sonay, anil.sonay@cern.ch         *"
echo -e "******************************************************\n"

export CONVERTTOROOT_HOME=$location
echo -e "\nMVAKit Home Dir : " ${CONVERTTOROOT_HOME}

alias converter-make='cd ${CONVERTTOROOT_HOME}/build/; make -j4; cd ../'
alias converter-clean='rm -rf ${CONVERTTOROOT_HOME}/build/'
alias converter-build='mkdir ${CONVERTTOROOT_HOME}/build && cd ${CONVERTTOROOT_HOME}/build; cmake ../; make -j4; cd ../'

if [ -d "${CONVERTTOROOT_HOME}/build/bin" ] 
then
    echo -e "Your build/bin directory already exist."
    echo -e "\nTo recompile please use \e[1m\e[4mmvakit-make\e[0m.\n"
else
    echo -e "\nTo compile please use \e[1m\e[4mmvakit-build\e[0m.\n"
fi

chmod +x share/*

export CPATH=${CPATH}${CPATH:+:}${CONVERTTOROOT_HOME}
export PATH=${PATH}${PATH:+:}${CONVERTTOROOT_HOME}/build/bin
export PATH=${PATH}${PATH:+:}${CONVERTTOROOT_HOME}/share
export PYTHONPATH=${PYTHONPATH}${PYTHONPATH:+:}${CONVERTTOROOT_HOME}
