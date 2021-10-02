S=1 && for (( A = $1; A>=0; A--)); do [[ $A -eq 0  ]] && echo $S || [[ $A -eq $1 ]] && S=$A || S=$[$S*($A)] ;done 
