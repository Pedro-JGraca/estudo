if [ $# -ne 1 ]; then
	echo "forma: bash compile.sh Princiapal.java"
else
	#abaixo está o codigo. Acima apenas para caso não coloque o numero certo de argumentos
	if [ $1 == "Principal.java" ]; then
		posicao=$(echo $(pwd))
		a="/"
		echo $posicao$a$1
		cd ..
		javac -d compilado/ $posicao$a$1
		mv compilado/ $posicao
	else
		echo "Arg1 precisa ser Princinpal.java"
	fi;
fi;
