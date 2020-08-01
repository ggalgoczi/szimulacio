#for f in ../macs/*.sh; do  # or wget-*.sh instead of *.sh
#declare -a StringArray=("../macs/0.sh" "../macs/1.sh" "../macs/2.sh" "../macs/37.sh" )
declare -a StringArray=("../macs/36.sh" )


for f in ${StringArray[@]}; do  # or wget-*.sh instead of *.sh
  bash "$f" -H   || break # if needed 
done
