if [[ $1 == "latest" ]]; then
  ls -t log | head -1 | xargs -I {} cat log/{}
elif [[ $1 == "name"]]; then
  cat "log/${2}.log"
else
  ls -t log | head -1 | xargs -I {} cat log/{}
fi
