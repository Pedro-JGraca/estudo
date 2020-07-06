cd compilado/ 2>>/dev/null
if [ $? -eq 0 ]; then
	pasta=$(echo $(ls))
	principal=".Principal"
	java $pasta$principal
else
	echo "falta compilar"
fi;

