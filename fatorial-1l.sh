for (( A=$1; A>0; A--)); do [[ $A -eq 1  ]] && echo $S || [[ $A -eq $1 ]] && S=$A || S=$[$S*($A)] ;done 
