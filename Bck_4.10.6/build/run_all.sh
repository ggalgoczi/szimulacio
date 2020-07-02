for f in ../macs/*.sh; do  # or wget-*.sh instead of *.sh
  bash "$f" -H   || break # if needed 
done
